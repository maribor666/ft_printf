/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_uc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ospeka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 17:09:03 by ospeka            #+#    #+#             */
/*   Updated: 2018/05/12 17:09:06 by ospeka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		write_arr_of_bits(int *arr)
{
	int	i;

	i = 0;
	while (arr[i] != -1)
	{
		write(1, &(arr[i]), 1);
		i++;
	}
	free(arr);
}

char		*imp_mask(char *bits, char *mask)
{
	int		i;
	int		j;

	i = (int)ft_strlen(mask) - 1;
	j = (int)ft_strlen(bits) - 1;
	while (j != -1)
	{
		if (mask[i] == 'x')
		{
			mask[i] = bits[j];
			j--;
		}
		i--;
	}
	i = 0;
	while (mask[i] != '\0')
	{
		if (mask[i] == 'x')
			mask[i] = '0';
		i++;
	}
	free(bits);
	return (mask);
}

char		*get_mask(int num_of_bits)
{
	if (num_of_bits <= 7)
		return (ft_strdup("0xxxxxxx"));
	if (num_of_bits <= 11)
		return (ft_strdup("110xxxxx 10xxxxxx"));
	if (num_of_bits <= 16)
		return (ft_strdup("1110xxxx 10xxxxxx 10xxxxxx"));
	if (num_of_bits <= 21)
		return (ft_strdup("11110xxx 10xxxxxx 10xxxxxx 10xxxxxx"));
	return (ft_strdup(""));
}
