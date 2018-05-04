/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 15:16:40 by exam              #+#    #+#             */
/*   Updated: 2018/04/13 16:57:02 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_correct(char c, int base)
{
    if (c >= '0' && c <= '0' + base && base <= 10)
        return (1);
    if (base > 10)
    {
        if ((c >= 'a' && c <= 'a' + base - 11) ||
            (c >= '0' && c <= '9'))
            return (1);
        if ((c >= 'A' && c <= 'A' + base - 11) ||
            (c >= '0' && c <= '9'))
            return (1);
    }
    return (0);
}

int		find_x(char c, int base)
{
    int x;

    x = 0;
    if (c >= 'a' && c <= 'a' + base - 10)
        x = 39;
    if (c >= 'A' && c <= 'A' + base - 10)
        x = 7;
    return (x);
}

int		ft_atoi_base(const char *str, int str_base)
{
    int res;
    int i;
    int minus;
    int x;

    x = 0;
    res = 0;
    i = 0;
    minus = 1;
    if (str[0] == '-')
    {
        minus = -1;
        i++;
    }
    while (is_correct(str[i], str_base) == 1 && str[i] != '\0')
    {
        x = find_x(str[i], str_base);
        res = res * str_base + (str[i] - '0' - x);
        i++;
    }
    return (res * minus);
}
