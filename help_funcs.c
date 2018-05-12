/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ospeka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 17:12:21 by ospeka            #+#    #+#             */
/*   Updated: 2018/05/12 17:12:23 by ospeka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			is_mods(char c)
{
	if (ft_isdigit(c) == 1 || is_flag(c) == 1
		|| is_mod(c) == 1 || c == '.')
		return (1);
	else
		return (0);
}

int			is_mod(char c)
{
	if (c == 'h' || c == 'l' || c == 'j' || c == 'z')
		return (1);
	else
		return (0);
}

int			is_flag(char c)
{
	if (c == '+' || c == '-' || c == '0'
		|| c == '#' || c == ' ')
		return (1);
	else
		return (0);
}

ssize_t		caster(t_modes mods, ssize_t arg)
{
	if (ft_strcmp(mods.mod, "h") == 0 && mods.id == 'D')
		return ((unsigned short)arg);
	if (ft_strcmp(mods.mod, "h") == 0)
		return ((short)arg);
	if (ft_strcmp(mods.mod, "hh") == 0 && mods.id == 'D')
		return ((unsigned short)arg);
	if (ft_strcmp(mods.mod, "hh") == 0)
		return ((signed char)arg);
	if (ft_strcmp(mods.mod, "l") == 0)
		return ((long)arg);
	if (ft_strcmp(mods.mod, "ll") == 0)
		return ((long long)arg);
	if (ft_strcmp(mods.mod, "j") == 0)
		return ((intmax_t)arg);
	if (ft_strcmp(mods.mod, "z") == 0)
		return ((size_t)arg);
	if (mods.id == 'D')
		return ((long int)arg);
	return ((int)arg);
}

char		*append(char *source, char *to_append)
{
	char	*res;

	res = ft_strjoin(source, to_append);
	free(source);
	return (res);
}
