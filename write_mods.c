/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_mods.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ospeka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 17:11:04 by ospeka            #+#    #+#             */
/*   Updated: 2018/05/12 17:11:06 by ospeka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_modes		write_mods(const char *s, t_modes mods)
{
	int i;
	int is_dot;

	is_dot = 0;
	i = 0;
	while (is_mods(s[i]) == 1 && s[i] != '\0')
		i++;
	if (s[i] != '\0')
		mods.id = s[i];
	mods = fill_mods(mods, i, (char*)s, is_dot);
	mods.mod = rewrite_mod(mods.mod);
	mods.s = (char*)(s + i + 1);
	return (mods);
}

t_modes		fill_mods(t_modes mods, int i, char *s, int is_dot)
{
	int j;

	j = 0;
	while (j < i)
	{
		mods = fill_flags(s, &j, mods);
		if (ft_isdigit(s[j]) == 1 && is_dot == 0 && s[j] != '0')
		{
			mods.width = ft_atoi(&(s[j]));
			while (ft_isdigit(s[j]) == 1)
				j++;
		}
		if (s[j] == '.')
		{
			is_dot = 1;
			j++;
			if (s[j] == '0' || ft_isdigit(s[j]) == 0)
				mods.precision = 0;
		}
		mods = fill_prec_mod(s, &j, mods, is_dot);
	}
	return (mods);
}

t_modes		fill_prec_mod(char *s, int *j, t_modes mods, int is_dot)
{
	if (ft_isdigit(s[(*j)]) == 1 && is_dot == 1 && s[(*j)] != '0')
	{
		mods.precision = ft_atoi(&(s[(*j)]));
		while (ft_isdigit(s[(*j)]) == 1)
			(*j)++;
	}
	if (is_mod(s[(*j)]) == 1)
	{
		mods.mod = append_char(mods.mod, s[(*j)]);
		(*j)++;
	}
	return (mods);
}

t_modes		fill_flags(char *s, int *j, t_modes mods)
{
	if (is_flag(s[(*j)]) == 1)
	{
		if (s[(*j) - 1] == '.' && s[(*j)] == '0')
			(*j)++;
		else
		{
			mods.flags = append_char(mods.flags, s[(*j)]);
			(*j)++;
		}
	}
	return (mods);
}

char		*rewrite_mod(char *mod)
{
	char *res;

	if (ft_strlen(mod) <= 1)
		return (mod);
	res = ft_strdup("");
	if (mod[ft_strlen(mod) - 1] == 'z' || mod[ft_strlen(mod) - 1] == 'j')
	{
		res = append_char(res, mod[ft_strlen(mod) - 1]);
		free(mod);
		return (res);
	}
	else
	{
		if (mod[ft_strlen(mod) - 1] == mod[ft_strlen(mod) - 2])
		{
			res = append(res, &(mod[ft_strlen(mod) - 2]));
			free(mod);
		}
		else
		{
			res = append(res, &(mod[ft_strlen(mod) - 1]));
			free(mod);
		}
		return (res);
	}
}
