/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ospeka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 14:58:32 by ospeka            #+#    #+#             */
/*   Updated: 2018/05/12 14:58:38 by ospeka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_FT_PRINTF_H
# define PRINTF_FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

typedef struct	s_mods{
	char	*flags;
	int		width;
	int		precision;
	char	*mod;
	char	id;
	char	*s;
}				t_modes;

int				ft_printf(const char *str, ...);
int				is_mods(char c);
int				is_flag(char c);
int				is_mod(char c);
t_modes			free_modes(t_modes mods);
char			*rewrite_mod(char *mod);
t_modes			fill_mods(t_modes mods, int i, char *s, int is_dot);
t_modes			fill_flags(char *s, int *j, t_modes mods);
t_modes			fill_prec_mod(char *s, int *j, t_modes mods, int is_dot);
int				perfom_conv(const char **str, t_modes mods, int *i, va_list ap);
int				print_d(t_modes mods, ssize_t arg);
char			*make_value(t_modes mods, ssize_t arg);
char			*make_padding(t_modes mods, char *prefix, char *value);
char			*make_prefix(t_modes mods, ssize_t arg);
char			*make_res_d(char *flags, char *prefix,
									char *padding, char *value);
t_modes			write_mods(const char *s, t_modes mods);
char			*create_and_fill(int count, char filler);
char			*append(char *source, char *to_append);
int				print_mod(t_modes mods, va_list ap);
ssize_t			caster(t_modes mods, ssize_t arg);
int				ft_atoi(const char *str);
int				ft_count_num(int num);
char			*ft_itoa(ssize_t n);
void			ft_putstr(char const *s);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlen(const char *s);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi_base(const char *str, int str_base);
void			ft_putchar(char c);
char			*ft_itoabase(size_t n, int base);
char			**ft_strsplit(char const *s, char c);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_isdigit(int c);
int				print_o(t_modes mods, size_t arg);
size_t			caster_o(t_modes mods, size_t arg);
char			*make_prefix_o(t_modes mods, size_t arg);
char			*make_value_o(t_modes mods, size_t arg, char *prefix);
int				print_x(t_modes mods, size_t arg);
char			*to_lower_str(char *value);
char			*make_prefix_x(t_modes mods, size_t arg);
char			*make_value_x(t_modes mods, size_t arg);
int				print_u(t_modes mods, size_t arg);
char			*make_value_u(t_modes mods, size_t arg);
size_t			caster_u(t_modes mods, size_t arg);
int				print_p(t_modes mods, size_t arg);
int				print_c(t_modes mods, int arg);
int				print_uc(int arg, t_modes mods);
int				count_bits(int arg);
char			*imp_mask(char *bits, char *mask);
char			*get_mask(int num_of_bits);
void			write_arr_of_bits(int *arr);
int				*conv_arr(char **arr_of_bits, char *after_mask_imp);
char			*make_padding_c(t_modes mods, int pref_len, int value_len);
int				print_s(t_modes mods, wchar_t *arg);
int				count_len_us(wchar_t *arg, int prec, int len);
int				count_len_wo_prec(wchar_t *arg);
int				print_us_prec(wchar_t *arg, int prec);
int				print_us(wchar_t *arg);
int				print_us_prec_c(wchar_t *arg, int *i, int *prec);
int				format_print_us(t_modes mods, wchar_t *arg);
char			*make_value_s(t_modes mods, char *arg);
char			*append_char(char *source, char to_append);
char			*make_padding_s(t_modes mods, int value_len);
int				make_res_s(t_modes mods, char *value, char *padding);
int				print_res_us(t_modes mods, wchar_t *arg);
int				count_bytes_in_intarr(int *arr);
int				*make_uchar_for_s(int c);
#endif
