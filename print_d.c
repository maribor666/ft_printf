/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ospeka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 15:54:34 by ospeka            #+#    #+#             */
/*   Updated: 2018/05/12 15:54:35 by ospeka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_d(t_modes mods, ssize_t arg)
{
	char	*prefix;
	char	*value;
	char	*padding;
	char	*res;
	int		len;

	arg = caster(mods, arg);
	prefix = make_prefix(mods, arg);
	value = make_value(mods, arg);
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

char		*make_res_d(char *flags, char *prefix, char *padding, char *value)
{
	char	*buff;
	char	*res;

	if (ft_strchr(flags, '0') != NULL && ft_strchr(flags, '-') == NULL)
	{
		buff = ft_strjoin(prefix, padding);
		res = ft_strjoin(buff, value);
		free(buff);
	}
	else
	{
		if (ft_strchr(flags, '-') != NULL)
		{
			buff = ft_strjoin(prefix, value);
			res = ft_strjoin(buff, padding);
			free(buff);
		}
		else
		{
			buff = ft_strjoin(prefix, value);
			res = ft_strjoin(padding, buff);
			free(buff);
		}
	}
	return (res);
}

char		*make_value(t_modes mods, ssize_t arg)
{
	char	*value;
	char	*p;
	char	*num;

	if (arg < 0)
		arg *= -1;
	num = ft_itoa(arg);
	if (arg == 0 && mods.precision == 0)
		return (ft_strdup(""));
	if (mods.precision != -1)
	{
		if (mods.precision >= ft_count_num(arg))
		{
			p = create_and_fill(mods.precision - ft_count_num(arg), '0');
			value = append(p, num);
			free(num);
		}
		else
		{
			value = ft_strdup(num);
			free(num);
		}
		return (value);
	}
	return (num);
}

char		*make_padding(t_modes mods, char *prefix, char *value)
{
	char	*padding;
	char	filler;
	int		count_to_fill;

	padding = ft_strdup("");
	filler = ' ';
	if (ft_strchr(mods.flags, '0') != NULL &&
			ft_strchr(mods.flags, '-') == NULL && mods.precision == -1)
		filler = '0';
	if (mods.precision == -1 && mods.width != -1)
	{
		count_to_fill = mods.width - ft_strlen(prefix) - ft_strlen(value);
		free(padding);
		padding = create_and_fill(count_to_fill, filler);
	}
	if (mods.precision != -1 && mods.width != -1)
	{
		count_to_fill = mods.width - ft_strlen(prefix) - ft_strlen(value);
		if (count_to_fill >= 0)
		{
			free(padding);
			padding = create_and_fill(count_to_fill, filler);
		}
	}
	return (padding);
}

char		*make_prefix(t_modes mods, ssize_t arg)
{
	char	*prefix;

	prefix = ft_strdup("");
	if (ft_strchr(mods.flags, '+') != NULL)
	{
		if (arg < 0)
			prefix = append(prefix, "-");
		else
			prefix = append(prefix, "+");
		return (prefix);
	}
	if (ft_strchr(mods.flags, ' ') != NULL)
	{
		if (arg < 0)
			prefix = append(prefix, "-");
		else
			prefix = append(prefix, " ");
		return (prefix);
	}
	if (arg < 0)
		prefix = append(prefix, "-");
	return (prefix);
}
