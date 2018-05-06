#include "ft_printf.h"

t_modes write_mods(const char *s, t_modes mods)
{
    //char *id_s;
    //char *res;


    if (*s == '-' || *s == '+' || *s == ' ' || *s == '#' || *s == '0')
    {
        mods.flags[0] = *s;
        s++;
    }
    if (*s == '-' || *s == '+' || *s == ' ' || *s == '#' || *s == '0')
    {
        mods.flags[1] = *s;
        s++;
    }
    if (*s == '-' || *s == '+' || *s == ' ' || *s == '#' || *s == '0')
    {
        mods.flags[2] = *s;
        s++;
    }
    //made func write_flags with appending flags
    if (*s >= '0' && *s <= '9')
        mods.width = ft_atoi(s);
    while (*s >= '0' && *s <= '9')
        s++;
    if (*s == '.')
    {
        s++;
        mods.precision = ft_atoi(s);
    }
    while (*s >= '0' && *s <= '9')
        s++;
    if (*s == 'h' || *s == 'l' || *s == 'j' || *s == 'z')
    {
        mods.mod[0] = *s;
        s++;
    }
    if (*s == 'h' && mods.mod[0] == 'h')
    {
        mods.mod[1] = 'h';
        s++;
    }
    if (*s == 'l' && mods.mod[0] == 'l')
    {
        mods.mod[1] = 'l';
        s++;
    }
//    id_s = "sSpdDioOuUxXcC%";
//    res = ft_strchr(id_s, *s);
//    if (res != NULL)
//    {
    mods.id = *s;
    s++;
//    }
    mods.s = (char*)s;
    return (mods);
}

int    print_mod(t_modes mods, va_list ap)
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
        return(print_p(mods, va_arg(ap, size_t)));
    if (mods.id == '%')
        return (print_percent(mods));
    if (ft_strchr("sSpdDioOuUxXcC%", mods.id) == NULL)
        return (print_c(mods, mods.id));
    return (0);
}

t_modes set_modes(void)
{
    t_modes mods;

    mods.flags[0] = '_';
    mods.flags[1] = '_';
    mods.flags[2] = '_';
    mods.width = -1;
    mods.precision = -1;
    mods.mod[0] = '_';
    mods.mod[1] = '_';
    mods.id = '_';
    mods.s = NULL;
    return (mods);
}
int     ft_printf(const char *str, ...)
{
    va_list ap;
    int     i;
    t_modes mods;
    int     res;

    res = 0;
    i = 0;
    va_start(ap, str);
    mods = set_modes();
    while (*str != '\0')
    {
        if (str[i] == '%' && str[i + 1] != '\0')
        {
            mods = write_mods((&str[i] + 1), mods);
            res += print_mod(mods, ap);
            str += (mods.s - str);
            mods = set_modes();
            continue ;
        }
        if (*str != '%')
            write(1, &(*str), 1);
        *str != '%' ? res++ : res;
        str++;
    }
    va_end(ap);
    return (res);
}

//#include <limits.h>
//#include <locale.h>
//
//int main(void)
//{
//    int r1;
//    int r2;
//    char* l = setlocale(LC_ALL, "");
//
//       r1 = printf("|%4.15S|\n", L"我是一只猫。");
//    r2 = ft_printf("|%4.15S|\n", L"我是一只猫。");
//
//    printf("r1 = %d; r2 = %d\n", r1, r2);
//    //system("leaks PRINTF");
//    system("leaks PRINTF | grep Process | tail -n 1");
////    printf("|%010+hhllh.42l0d|rest\n", 42);
////     printf("'%25hhhllljzi' '%-i'\n", -9223372036854775808, -42);δ
//
//    return 0;
//}

//assert_printf("%4.15S", L"我是一只猫。");