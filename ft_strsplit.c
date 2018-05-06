/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ospeka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 11:57:28 by ospeka            #+#    #+#             */
/*   Updated: 2017/12/02 11:57:30 by ospeka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		words_counter(char const *s, char c)
{
	int count;
	int i;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			count++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (count);
}

static char		*write_word(char const *s, char c, int i)
{
	int		len;
	int		j;
	char	*word;
	int		k;

	k = 0;
	len = 0;
	j = i;
	while (s[j] != '\0' && s[j] != c)
	{
		len++;
		j++;
	}
	word = (char*)malloc(sizeof(char) * (len + 1));
	if (word == NULL)
		return (NULL);
	j = i;
	while (k < len)
	{
		word[k] = s[j];
		k++;
		j++;
	}
	word[k] = '\0';
	return (word);
}

static char		**write_arr(char const *s, char **res, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			res[j] = write_word(s, c, i);
			if (res[j] == NULL)
				return (NULL);
			j++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (res);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**res;

	if (s == NULL)
		return (NULL);
	res = (char**)malloc(sizeof(char*) * (words_counter(s, c) + 1));
	if (words_counter(s, c) == 0)
	{
		res[0] = NULL;
		return (res);
	}
	if (res == NULL)
		return (NULL);
	res[words_counter(s, c)] = NULL;
	res = write_arr(s, res, c);
	if (res == NULL)
		return (NULL);
	return (res);
}
