/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ospeka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 15:15:53 by ospeka            #+#    #+#             */
/*   Updated: 2018/05/12 15:15:56 by ospeka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_mod(t_modes mods, va_list ap)
{
	if (mods.id == 'd' || mods.id == 'i' || mods.id == 'D')
		return (print_d(mods, va_arg(ap, ssize_t)));
	if (mods.id == 'o' || mods.id == 'O')
		return (print_o(mods, va_arg(ap, size_t)));
	if (mods.id == 'x' || mods.id == 'X')
		return (print_x(mods, va_arg(ap, size_t)));
	if (mods.id == 'u' || mods.id == 'U')
		return (print_u(mods, va_arg(ap, size_t)));
	if (mods.id == 'c' || mods.id == 'C')
		return (print_c(mods, va_arg(ap, int)));
	if (mods.id == 's' || mods.id == 'S')
		return (print_s(mods, va_arg(ap, wchar_t*)));
	if (mods.id == 'p')
		return (print_p(mods, va_arg(ap, size_t)));
	if (mods.id == '%')
		return (print_c(mods, '%'));
	if (ft_strchr("sSpdDioOuUxXcC%", mods.id) == NULL)
		return (print_c(mods, mods.id));
	return (0);
}

t_modes		free_modes(t_modes mods)
{
	free(mods.flags);
	mods.width = -1;
	mods.precision = -1;
	free(mods.mod);
	mods.id = '_';
	mods.s = NULL;
	return (mods);
}

t_modes		set_modes(void)
{
	t_modes mods;

	mods.flags = ft_strdup("");
	mods.width = -1;
	mods.precision = -1;
	mods.mod = ft_strdup("");
	mods.id = '_';
	mods.s = NULL;
	return (mods);
}

int			perfom_conv(const char **str, t_modes mods, int *i, va_list ap)
{
	int res;

	res = 0;
	mods = write_mods((&(*str[(*i)]) + 1), mods);
	res += print_mod(mods, ap);
	(*str) += (mods.s - (*str));
	mods = free_modes(mods);
	return (res);
}

int			ft_printf(const char *str, ...)
{
	va_list ap;
	int		i;
	t_modes	mods;
	int		res;

	res = 0;
	i = 0;
	va_start(ap, str);
	while (*str != '\0')
	{
		mods = set_modes();
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			res += perfom_conv(&(str), mods, &i, ap);
			continue ;
		}
		else
			free_modes(mods);
		if (*str != '%')
			write(1, &(*str), 1);
		*str != '%' ? res++ : res;
		str++;
	}
	va_end(ap);
	return (res);
}
