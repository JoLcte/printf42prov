/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiquiau <ggiquiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 12:05:26 by ggiquiau          #+#    #+#             */
/*   Updated: 2021/01/15 14:45:09 by ggiquiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft.h"
# define BASE10 "0123456789"
# define BASE16_L "0123456789abcdef"
# define BASE16_U "0123456789ABCDEF"

typedef struct	s_conv
{
	char	padc;
	int		sign;
	int		ladjust;
	int		width;
	int		precision;
	int		base;
	char	conv;
}				t_conv;
int				ft_printf(const char *str, ...);
int				is_flag(char c);
int				is_modifier(char s);
int				is_conv(char c);
t_conv			init_conv(char *str, int n, va_list ap);
int				ch_len(int ch);
int				s_len(char *s, t_conv c);
int				pdiuxx_len(long long l, t_conv c);
int				format_len(t_conv c, va_list ap);
int				c_format(char **res, int ch, t_conv c);
int				s_format(char **res, char *s, t_conv c);
int				perc_format(char **res, t_conv c);
int				int_format(char **res, long long l, t_conv c, int prec);
int				format(t_conv c, char **res, va_list ap);
long long		get_long(t_conv c, va_list ap);
void			ft_llutoa_base(char **res, unsigned long long nbr, char *base);
int				get_index(char *s, char c);
void			fill_char2(char c, char **res, int len);
size_t			num_len_llu(unsigned long long nbr, size_t len_base_to);
void			ft_strcat(char *str, char **res, int n);
long long		ft_pow(long long n, int power);
int				min(int a, int b);
int				max(int a, int b);
char			*str_base(char conv);
#endif
