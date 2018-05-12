/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_funcs2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ospeka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 17:21:17 by ospeka            #+#    #+#             */
/*   Updated: 2018/05/12 17:21:19 by ospeka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*create_and_fill(int count, char filler)
{
	char	*res;
	int		i;

	i = 0;
	if (count <= 0)
		return (ft_strdup(""));
	res = malloc(sizeof(char) * (count + 1));
	res[count] = '\0';
	while (i < count)
	{
		res[i] = filler;
		i++;
	}
	return (res);
}

int			count_bytes_in_intarr(int *arr)
{
	int i;

	i = 0;
	while (arr[i] != -1)
		i++;
	return (i);
}

char		*append_char(char *source, char to_append)
{
	char *res;
	char c[2];

	c[1] = '\0';
	c[0] = to_append;
	res = ft_strjoin(source, c);
	free(source);
	return (res);
}

int			count_len_us(wchar_t *arg, int prec, int res)
{
	int		i;
	int		*uchar;

	i = 0;
	if (prec == -1)
		return (count_len_wo_prec(arg));
	while (arg[i] != '\0' && prec > 0)
	{
		if (arg[i] <= 127)
		{
			i++;
			res++;
			prec--;
		}
		else
		{
			uchar = make_uchar_for_s((int)(arg[i]));
			prec -= count_bytes_in_intarr(uchar);
			if (prec >= 0)
				res += count_bytes_in_intarr(uchar);
			free(uchar);
			i++;
		}
	}
	return (res);
}

int			count_len_wo_prec(wchar_t *arg)
{
	int		res;
	int		i;
	int		*uchar;

	i = 0;
	res = 0;
	while (arg[i] != '\0')
	{
		if (arg[i] <= 127)
		{
			i++;
			res++;
		}
		else
		{
			uchar = make_uchar_for_s((int)(arg[i]));
			res += count_bytes_in_intarr(uchar);
			free(uchar);
			i++;
		}
	}
	return (res);
}
