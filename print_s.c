/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ospeka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 16:01:44 by ospeka            #+#    #+#             */
/*   Updated: 2018/05/12 16:01:45 by ospeka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_s(t_modes mods, wchar_t *arg)
{
	char	*padding;
	char	*value;
	int		len;

	if ((ft_strcmp(mods.mod, "l") == 0 || mods.id == 'S') && arg != NULL)
		return (format_print_us(mods, arg));
	else
	{
		value = make_value_s(mods, (char*)arg);
		padding = make_padding_s(mods, (int)ft_strlen(value));
		len = make_res_s(mods, value, padding);
		return (len);
	}
}

int			make_res_s(t_modes mods, char *value, char *padding)
{
	int		len;
	char	*res;

	if (ft_strchr(mods.flags, '-') != NULL)
	{
		res = ft_strjoin(value, padding);
		len = (int)ft_strlen(res);
		ft_putstr(res);
		free(padding);
		free(value);
		free(res);
		return (len);
	}
	else
	{
		res = ft_strjoin(padding, value);
		len = (int)ft_strlen(res);
		ft_putstr(res);
		free(padding);
		free(value);
		free(res);
		return (len);
	}
}

int			*make_uchar_for_s(int c)
{
	char	*bits_str;
	char	*mask;
	char	*after_mask_imp;
	char	**arr_of_bits;
	int		*res;

	bits_str = ft_itoabase(c, 2);
	mask = get_mask(count_bits(c));
	after_mask_imp = imp_mask(bits_str, mask);
	arr_of_bits = ft_strsplit(after_mask_imp, ' ');
	free(after_mask_imp);
	res = conv_arr(arr_of_bits, after_mask_imp);
	return (res);
}

char		*make_padding_s(t_modes mods, int value_len)
{
	char	*res;
	char	filler;
	int		count_to_fill;

	filler = ' ';
	if (ft_strchr(mods.flags, '0') != NULL)
		filler = '0';
	res = ft_strdup("");
	if (mods.precision == -1 && mods.width == -1)
		return (res);
	if (mods.width != -1)
	{
		free(res);
		count_to_fill = mods.width - value_len;
		res = create_and_fill(count_to_fill, filler);
	}
	return (res);
}

char		*make_value_s(t_modes mods, char *arg)
{
	char	*res;
	int		i;

	i = 0;
	arg = arg == NULL ? "(null)" : arg;
	res = ft_strdup("");
	if (mods.width == -1 && mods.precision == -1 && arg != NULL)
		return (append(res, arg));
	if (mods.width != -1 && mods.precision == -1)
	{
		while (arg[i] != '\0')
		{
			res = append_char(res, arg[i]);
			i++;
		}
	}
	if (mods.precision != -1)
	{
		while (i < mods.precision && arg[i] != '\0')
		{
			res = append_char(res, arg[i]);
			i++;
		}
	}
	return (res);
}
