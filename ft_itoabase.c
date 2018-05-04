/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ospeka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 16:05:44 by ospeka            #+#    #+#             */
/*   Updated: 2018/01/12 16:05:45 by ospeka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	count_size(size_t n, size_t base)
{
	size_t	buff;
	int				size;

	size = 0;
	buff = (size_t)n;
//	if (buff < 0)
//		size++;
	if (n == 0)
		return (2);
	while (buff != 0)
	{
		size++;
		buff = buff / base;
	}
	return (size + 1);
}

static char	*write_str(char *res, int i, size_t buff, size_t base)
{
	char letter;

	letter = 65;
	while (buff != 0)
	{
		if ((buff % base) >= 10)
		{
			letter = 'A' + (buff % base) - 10;
			res[i] = letter;
		}
		else
			res[i] = '0' + buff % base;
		i--;
		buff = buff / base;
	}
	return (res);
}

char		*ft_itoabase(size_t n, int base)
{
	size_t          buff;
	char			*res;
	int				i;

	i = count_size(n, base) - 2;
	buff = (size_t)n;
	res = (char*)malloc(sizeof(char) * count_size(n, base));
	if (res == NULL)
		return (NULL);
	if (n == 0)
		return (ft_strdup("0"));
//	if (n < 0)
//	{
//		res[0] = '-';
//		buff = -buff;
//	}
	res[count_size(n, base) - 1] = '\0';
	res = write_str(res, i, buff, base);
	return (res);
}
