/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ospeka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 16:35:57 by ospeka            #+#    #+#             */
/*   Updated: 2017/11/06 16:35:59 by ospeka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	size_t i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i])
	{
		if ((char)c == '\0')
		{
			return ((char*)(s + ft_strlen(s)));
		}
		if ((unsigned char)s[i] == (char)c)
		{
			return ((char*)(s + i));
		}
		i++;
	}
	return (NULL);
}
