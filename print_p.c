/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ospeka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 16:00:09 by ospeka            #+#    #+#             */
/*   Updated: 2018/05/12 16:00:22 by ospeka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_p(t_modes mods, size_t arg)
{
	char	*prefix;
	char	*value;
	char	*padding;
	char	*res;
	int		len;

	prefix = ft_strdup("0x");
	value = make_value_x(mods, arg);
	value = to_lower_str(value);
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
