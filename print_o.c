//
// Created by Oleh SPEKA on 4/23/18.
//

#include "ft_printf.h"

int     print_o(t_modes mods, size_t arg)
{
   // printf("arg in10 - |%d|\n", arg);

    char *prefix;
    char *padding;
    char *value;
    char *buff;
    char *res;
    int  len;

    arg = caster_o(mods, arg);
    prefix = make_prefix_o(mods, arg);
    value = make_value_o(mods, arg, prefix);
    padding = make_padding(mods,  prefix, value);
    if (mods.precision != -1 && ft_strchr(mods.flags, '0') != NULL)
        *ft_strchr(mods.flags, '0') = '_';
    if (ft_strchr(mods.flags, '0') != NULL && ft_strchr(mods.flags, '-') == NULL)
    {
        buff = ft_strjoin(prefix, padding);
        res = ft_strjoin(buff, value);
        free(buff);
    }
    else
    {
        if (ft_strchr(mods.flags, '-') != NULL)
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
    ft_putstr(res);
    free(prefix);
    free(padding);
    free(value);
    len = (int)ft_strlen(res);
    free(res);
    return (len);
}

size_t  caster_o(t_modes mods, size_t arg)
{
    if (ft_strncmp(mods.mod, "hh", 2) == 0 && mods.id == 'O')
        return ((unsigned short)arg);
    if (ft_strncmp(mods.mod, "h_", 2) == 0)
        return ((unsigned short)arg);
    if (ft_strncmp(mods.mod, "hh", 2) == 0)
        return ((unsigned char)arg);
    if (ft_strncmp(mods.mod, "l_", 2) == 0 || mods.id == 'O')
        return ((unsigned long)arg);
    if (ft_strncmp(mods.mod, "ll", 2) == 0)
        return ((unsigned long long) arg);
    if (ft_strncmp(mods.mod, "j_", 2) == 0)
        return ((uintmax_t)arg);
    if (ft_strncmp(mods.mod, "z_", 2) == 0)
        return ((size_t)arg);
    return ((unsigned int)arg);
}

char *make_prefix_o(t_modes mods, size_t arg)
{
    if (mods.precision == -1 && arg == 0)
        return (ft_strdup(""));
    if (ft_strchr(mods.flags, '#') != NULL)
        return (ft_strdup("0"));
    return (ft_strdup(""));
}

char *make_value_o(t_modes mods, size_t arg, char *prefix)
{
    char *value;
    char *p;
    char *num;

    if (arg == 0 && mods.precision == 0)
        return (ft_strdup(""));
    num = ft_itoabase(arg, 8);
    if (mods.precision != -1)
    {
        if (mods.precision >= (int)ft_strlen(num))
        {
            p = create_and_fill(mods.precision - ft_strlen(num) - ft_strlen(prefix), '0');
            value = ft_strjoin(p, num);
            free(p);
            free(num);
        }
        else
            return (num);
        return (value);
    }
    return (num);
}







