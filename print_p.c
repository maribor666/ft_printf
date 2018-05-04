
#include "ft_printf.h"

int     print_p(t_modes mods, size_t arg)
{
    char *prefix;
    char *value;
    char *padding;
    char *res;
    char *buff;
    int len;

    prefix = ft_strdup("0x");
    value = make_value_x(mods, arg);
    value = to_lower_str(value);
    padding = make_padding(mods, prefix, value);
    if (ft_strchr(mods.flags, '0') != NULL && ft_strchr(mods.flags, '-') == NULL)
    {
        buff = ft_strjoin(prefix, padding);
        res = ft_strjoin(buff, value);
        free(buff);
    }
    else {
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