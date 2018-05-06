#include "ft_printf.h"

int     print_c(t_modes mods, int arg)
{
    int     res;
    char    *padding;
    char    *mask;

    res = 0;
    if (ft_strchr(mods.flags, '-') != NULL)
    {
        res += print_uc(arg, mods);
        padding = make_padding_c(mods, 0, res);
        ft_putstr(padding);
        res += (int)ft_strlen(padding);
        free(padding);
        return (res);
    }
    else
    {
        mask = get_mask(count_bits(arg));
        padding = make_padding_c(mods, 0, (int)(ft_strlen(mask) / 8));
        ft_putstr(padding);
        res += (int)ft_strlen(padding);
        res += print_uc(arg, mods);
        free(padding);
        free(mask);
    }
    return (res);
}

int    print_uc(int arg, t_modes mods)
{
    char    *bits_str;
    char    *mask;
    char    *after_mask_imp;
    char    **arr_of_bits;
    int     res;

    if (mods.id == 'c' && ft_strncmp(mods.mod, "__", 2) == 0)
    {
        ft_putchar((char)arg);
        return (1);
    }
    bits_str = ft_itoabase(arg, 2);
    mask = get_mask(count_bits(arg));
    after_mask_imp = imp_mask(bits_str, mask);
    res = (int)(ft_strlen(after_mask_imp)) / 8;
    arr_of_bits = ft_strsplit(after_mask_imp, ' ');
    free(after_mask_imp);
    write_arr_of_bits(conv_arr(arr_of_bits, after_mask_imp));
    return (res);
}

char    *make_padding_c(t_modes mods, int pref_len, int value_len)
{
    char    *padding;
    char    filler;
    int     count_to_fill;

    padding = ft_strdup("");
    filler = ' ';
    if (ft_strchr(mods.flags, '0') != NULL && ft_strchr(mods.flags, '-') == NULL)
        filler = '0';
    if (mods.precision == -1 && mods.width != -1)
    {
        count_to_fill = mods.width - pref_len - value_len;
        free(padding);
        padding = create_and_fill(count_to_fill, filler);
    }
    if (mods.precision != -1 && mods.width != -1)
    {
        count_to_fill = mods.width - pref_len - value_len;
        if (count_to_fill >= 0)
        {
            free(padding);
            padding = create_and_fill(count_to_fill, filler);
        }
    }
    return (padding);
}

int    *conv_arr(char **arr_of_bits, char *after_mask_imp)
{
    int i;
    int *int_arr;

    i = 0;
    int_arr = (int*)malloc(sizeof(int) * (ft_strlen(after_mask_imp) / 8) + 1);
    int_arr[ft_strlen(after_mask_imp) / 8] = -1;
    while (arr_of_bits[i] != NULL)
    {
        int_arr[i] = ft_atoi_base(arr_of_bits[i], 2);
        free(arr_of_bits[i]);
        i++;
    }
    free(arr_of_bits[i]);
    free(arr_of_bits);
    return (int_arr);
}

void    write_arr_of_bits(int  *arr)
{
    int i;

    i = 0;
    while (arr[i] != -1)
    {
        write(1, &(arr[i]), 1);
        i++;
    }
    free(arr);
}

char    *imp_mask(char *bits, char *mask)
{
    int     i;
    int     j;
    char    *res;

    i = (int)ft_strlen(mask) - 1;
    j = (int)ft_strlen(bits) - 1;
    res = ft_strdup(mask);
    free(mask);
    while (j != -1)
    {
        if (res[i] == 'x')
        {
            res[i] = bits[j];
            j--;
        }
        i--;
    }
    i = 0;
    while (res[i] != '\0')
    {
        if (res[i] == 'x')
            res[i] = '0';
        i++;
    }
    free(bits);
    return (res);
}

char    *get_mask(int num_of_bits)
{
    if (num_of_bits <= 7)
        return (ft_strdup("0xxxxxxx"));
    if (num_of_bits <= 11)
        return (ft_strdup("110xxxxx 10xxxxxx"));
    if (num_of_bits <= 16)
        return (ft_strdup("1110xxxx 10xxxxxx 10xxxxxx"));
    if (num_of_bits <= 21)
        return (ft_strdup("11110xxx 10xxxxxx 10xxxxxx 10xxxxxx"));
    return (ft_strdup(""));
}

int     count_bits(int arg)
{
    int res;

    res = 0;
    while (arg != 0)
    {
        res++;
        arg /= 2;
    }
    return (res);
}
