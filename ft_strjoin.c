/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ospeka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 19:27:37 by ospeka            #+#    #+#             */
/*   Updated: 2017/11/10 19:27:38 by ospeka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len2;
	char	*res;
	int		i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	len2 = ft_strlen(s2);
	res = (char*)malloc(sizeof(char) * (ft_strlen(s1) + len2 + 1));
	if (res == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	len2 = 0;
	while (s2[len2] != '\0')
	{
		res[i] = s2[len2];
		i++;
		len2++;
	}
	res[i] = '\0';
	return (res);
}
