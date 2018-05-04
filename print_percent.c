

#include "ft_printf.h"

int     print_percent(t_modes mods)
{
    int res;

    res = print_c(mods, '%');
    return (res);
}