/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ospeka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:47:42 by ospeka            #+#    #+#             */
/*   Updated: 2017/11/06 17:47:44 by ospeka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t len1;
	size_t len2;
	size_t i;

	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (len1 == 0 && len2 == 0)
		return (0);
	if (len2 == 0)
		return (1);
	if (len1 == 0)
		return (-1);
	while (i < n && i <= len1 && i <= len2)
	{
		if (s1[i] == s2[i])
			i++;
		else
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}
