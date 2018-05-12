/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ospeka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 16:07:51 by ospeka            #+#    #+#             */
/*   Updated: 2018/05/12 16:07:52 by ospeka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_u(t_modes mods, size_t arg)
{
	char	*prefix;
	char	*padding;
	char	*value;
	char	*res;
	int		len;

	arg = caster_u(mods, arg);
	prefix = ft_strdup("");
	value = make_value_u(mods, arg);
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

size_t		caster_u(t_modes mods, size_t arg)
{
	if (ft_strcmp(mods.mod, "l") == 0 || mods.id == 'U')
		return ((unsigned long)arg);
	if (ft_strcmp(mods.mod, "h") == 0)
		return ((unsigned short)arg);
	if (ft_strcmp(mods.mod, "hh") == 0)
		return ((unsigned char)arg);
	if (ft_strcmp(mods.mod, "ll") == 0)
		return ((unsigned long long)arg);
	if (ft_strcmp(mods.mod, "j") == 0)
		return ((uintmax_t)arg);
	if (ft_strcmp(mods.mod, "z") == 0)
		return ((size_t)arg);
	return ((unsigned int)arg);
}

char		*make_value_u(t_modes mods, size_t arg)
{
	char	*value;
	char	*p;
	char	*num;

	if (arg == 0 && mods.precision == 0)
		return (ft_strdup(""));
	num = ft_itoabase(arg, 10);
	if (mods.precision != -1)
	{
		if (mods.precision >= (int)ft_strlen(num))
		{
			p = create_and_fill(mods.precision - (int)ft_strlen(num), '0');
			value = ft_strjoin(p, num);
			free(p);
		}
		else
			return (num);
		return (value);
	}
	return (num);
}
