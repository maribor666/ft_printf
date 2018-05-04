/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ospeka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 19:34:54 by ospeka            #+#    #+#             */
/*   Updated: 2017/11/21 19:34:55 by ospeka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' ||
		c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int				ft_atoi(const char *str)
{
	long long int	res;
	size_t			i;
	int				minus;

	i = 0;
	res = 0;
	minus = 1;
	while (is_space(str[i]) == 1)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		minus = str[i] == '-' ? -1 : 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		if (res < 0 && minus == -1 && res != -214783648)
			return (0);
		if (res < 0 && minus == 1)
			return (-1);
		i++;
	}
	return (res * minus);
}
