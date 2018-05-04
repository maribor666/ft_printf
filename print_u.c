
#include "ft_printf.h"


int     print_u(t_modes mods, size_t arg)
{
    char *prefix;
    char *padding;
    char *value;
    char *buff;
    char *res;
    int  len;

    arg = caster_u(mods, arg);
    prefix = ft_strdup("");// change
    value = make_value_u(mods, arg);// change
    padding = make_padding(mods,  prefix, value);
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

size_t  caster_u(t_modes mods, size_t arg)
{
    if (ft_strncmp(mods.mod, "l_", 2) == 0 || mods.id == 'U')
        return ((unsigned long)arg);
    if (ft_strncmp(mods.mod, "h_", 2) == 0)
        return ((unsigned short)arg);
    if (ft_strncmp(mods.mod, "hh", 2) == 0)
        return ((unsigned char)arg);
    if (ft_strncmp(mods.mod, "ll", 2) == 0)
        return ((unsigned long long) arg);
    if (ft_strncmp(mods.mod, "j_", 2) == 0)
        return ((uintmax_t)arg);
    if (ft_strncmp(mods.mod, "z_", 2) == 0)
        return ((size_t)arg);
    return ((unsigned int)arg);
}

char    *make_value_u(t_modes mods, size_t arg)
{
    char *value;
    char *p;
    char *num;

    if (arg == 0 && mods.precision == 0)
        return (ft_strdup(""));
    num = ft_itoabase(arg, 10);
    if (mods.precision != -1)
    {
        if (mods.precision >= (int)ft_strlen(num))
        {
            p = create_and_fill(mods.precision - (int)ft_strlen(num), '0');
            value = ft_strjoin(p, num);
            free(p);
        }
        else
            return (num);
        return (value);
    }
    return (num);
}