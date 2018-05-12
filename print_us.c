/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_us.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ospeka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 17:25:17 by ospeka            #+#    #+#             */
/*   Updated: 2018/05/12 17:25:19 by ospeka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			format_print_us(t_modes mods, wchar_t *arg)
{
	char	*padding;
	int		res;

	res = 0;
	padding = make_padding_s(mods, count_len_us(arg, mods.precision, 0));
	if (ft_strchr(mods.flags, '-') != NULL)
	{
		res += print_res_us(mods, arg);
		ft_putstr(padding);
		res += ft_strlen(padding);
		free(padding);
	}
	else
	{
		ft_putstr(padding);
		res += ft_strlen(padding);
		res += print_res_us(mods, arg);
		free(padding);
	}
	return (res);
}

int			print_res_us(t_modes mods, wchar_t *arg)
{
	int res;

	res = 0;
	if (mods.precision != -1)
		res += print_us_prec(arg, mods.precision);
	else
		res += print_us(arg);
	return (res);
}

int			print_us_prec(wchar_t *arg, int prec)
{
	int		res;
	int		i;
	int		*uchar;

	i = 0;
	res = 0;
	while (arg[i] != '\0' && prec > 0)
	{
		if (arg[i] <= 127)
			res += print_us_prec_c(arg, &i, &prec);
		else
		{
			uchar = make_uchar_for_s((int)(arg[i]));
			prec -= count_bytes_in_intarr(uchar);
			if (prec >= 0)
			{
				res += count_bytes_in_intarr(uchar);
				write_arr_of_bits(uchar);
			}
			else
				free(uchar);
			i++;
		}
	}
	return (res);
}

int			print_us_prec_c(wchar_t *arg, int *i, int *prec)
{
	ft_putchar((char)arg[(*i)]);
	(*i)++;
	(*prec)--;
	return (1);
}

int			print_us(wchar_t *arg)
{
	int res;
	int i;
	int *uchar;

	i = 0;
	res = 0;
	while (arg[i] != '\0')
	{
		if (arg[i] <= 127)
		{
			ft_putchar((char)arg[i]);
			i++;
			res++;
		}
		else
		{
			uchar = make_uchar_for_s((int)(arg[i]));
			res += count_bytes_in_intarr(uchar);
			write_arr_of_bits(uchar);
			i++;
		}
	}
	return (res);
}
