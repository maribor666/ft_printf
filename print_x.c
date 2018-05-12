/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ospeka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 16:09:57 by ospeka            #+#    #+#             */
/*   Updated: 2018/05/12 16:09:58 by ospeka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_x(t_modes mods, size_t arg)
{
	char	*prefix;
	char	*padding;
	char	*value;
	char	*res;
	int		len;

	arg = caster_o(mods, arg);
	prefix = make_prefix_x(mods, arg);
	value = make_value_x(mods, arg);
	padding = make_padding(mods, prefix, value);
	if (mods.id == 'x')
		value = to_lower_str(value);
	if (mods.precision != -1 && ft_strchr(mods.flags, '0') != NULL)
		*ft_strchr(mods.flags, '0') = '_';
	res = make_res_d(mods.flags, prefix, padding, value);
	ft_putstr(res);
	free(prefix);
	free(padding);
	free(value);
	len = (int)ft_strlen(res);
	free(res);
	return (len);
}

char		*make_prefix_x(t_modes mods, size_t arg)
{
	if (ft_strchr(mods.flags, '#') != NULL && arg == 0)
		return (ft_strdup(""));
	if (ft_strchr(mods.flags, '#') != NULL && mods.id == 'x')
		return (ft_strdup("0x"));
	if (ft_strchr(mods.flags, '#') != NULL && mods.id == 'X')
		return (ft_strdup("0X"));
	return (ft_strdup(""));
}

char		*make_value_x(t_modes mods, size_t arg)
{
	char *value;
	char *p;
	char *num;

	if (arg == 0 && mods.precision == 0)
		return (ft_strdup(""));
	num = ft_itoabase(arg, 16);
	if (mods.precision != -1)
	{
		if (mods.precision >= (int)ft_strlen(num))
		{
			p = create_and_fill(mods.precision - ft_strlen(num), '0');
			value = ft_strjoin(p, num);
			free(num);
			free(p);
		}
		else
			return (num);
		return (value);
	}
	return (num);
}

char		*to_lower_str(char *value)
{
	int		i;

	i = 0;
	while (value[i] != '\0')
	{
		if (value[i] >= 'A' && value[i] <= 'F')
			value[i] += 32;
		i++;
	}
	return (value);
}
