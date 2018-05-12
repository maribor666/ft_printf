/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ospeka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 15:57:50 by ospeka            #+#    #+#             */
/*   Updated: 2018/05/12 15:57:53 by ospeka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_o(t_modes mods, size_t arg)
{
	char	*prefix;
	char	*padding;
	char	*value;
	char	*res;
	int		len;

	arg = caster_o(mods, arg);
	prefix = make_prefix_o(mods, arg);
	value = make_value_o(mods, arg, prefix);
	padding = make_padding(mods, prefix, value);
	res = make_res_d(mods.flags, prefix, padding, value);
	ft_putstr(res);
	free(prefix);
	free(padding);
	free(value);
	len = (int)ft_strlen(res);
	free(res);
	return (len);
}

size_t		caster_o(t_modes mods, size_t arg)
{
	if (ft_strcmp(mods.mod, "hh") == 0 && mods.id == 'O')
		return ((unsigned short)arg);
	if (ft_strcmp(mods.mod, "h") == 0)
		return ((unsigned short)arg);
	if (ft_strcmp(mods.mod, "hh") == 0)
		return ((unsigned char)arg);
	if (ft_strcmp(mods.mod, "l") == 0 || mods.id == 'O')
		return ((unsigned long)arg);
	if (ft_strcmp(mods.mod, "ll") == 0)
		return ((unsigned long long)arg);
	if (ft_strcmp(mods.mod, "j") == 0)
		return ((uintmax_t)arg);
	if (ft_strcmp(mods.mod, "z") == 0)
		return ((size_t)arg);
	return ((unsigned int)arg);
}

char		*make_prefix_o(t_modes mods, size_t arg)
{
	if (mods.precision == 0 && arg == 0 && ft_strchr(mods.flags, '#') == NULL)
		return (ft_strdup(""));
	if (mods.precision == -1 && arg == 0 && ft_strchr(mods.flags, '#') != NULL)
		return (ft_strdup(""));
	if (ft_strchr(mods.flags, '#') != NULL)
		return (ft_strdup("0"));
	return (ft_strdup(""));
}

char		*make_value_o(t_modes mods, size_t arg, char *prefix)
{
	char	*value;
	char	*p;
	char	*num;
	int		pr;

	pr = mods.precision;
	if (arg == 0 && mods.precision == 0)
		return (ft_strdup(""));
	num = ft_itoabase(arg, 8);
	if (mods.precision != -1)
	{
		if (mods.precision >= (int)ft_strlen(num))
		{
			p = create_and_fill(pr - ft_strlen(num) - ft_strlen(prefix), '0');
			value = ft_strjoin(p, num);
			free(p);
			free(num);
		}
		else
			return (num);
		return (value);
	}
	return (num);
}
