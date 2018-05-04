/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ospeka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 20:53:28 by ospeka            #+#    #+#             */
/*   Updated: 2017/11/10 20:53:30 by ospeka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	ssize_t	count_size(size_t n)
{
	ssize_t         buff;
	ssize_t			size;

	size = 0;
	buff = (ssize_t)n;
	if (buff < 0)
		size++;
	if (n == 0)
		return (2);
	while (buff != 0)
	{
		size++;
		buff = buff / 10;
	}
	return (size + 1);
}

static char	*write_str(char *res, size_t i, size_t buff)
{
	while (buff != 0)
	{
		res[i] = '0' + buff % 10;
		i--;
		buff = buff / 10;
	}
	return (res);
}

char		*ft_itoa(ssize_t n)
{
    size_t          buff;
	char            *res;
	ssize_t			i;

	i = count_size(n) - 2;
	buff = n;
    if (n * 2 == 0 && n != 0)
        return (ft_strdup("9223372036854775808"));
	res = (char*)malloc(sizeof(char) * count_size(n));
	if (n == 0)
	{
		res[0] = '0';
		res[1] = '\0';
		return (res);
	}
	if (res == NULL)
		return (NULL);
	if (n < 0)
	{
		res[0] = '-';
		buff *= -n;
	}
	res[count_size(n) - 1] = '\0';
	res = write_str(res, i, buff);
	return (res);
}
