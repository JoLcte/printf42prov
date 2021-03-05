/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 00:02:22 by jlecomte          #+#    #+#             */
/*   Updated: 2021/03/05 22:54:23 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFSIZ
#  define BUFSIZ 1024
# endif

typedef struct	s_flags
{
	int		fzero;
	int		fleft;
	int		fplus;
	int		fspace;
	int		prefix;
	int		width;
	int		prec;
	char	spec;
}				t_flags;

/*
** MAIN FUNCTIONS
*/

int				buf_pilot(char *buf, const char *s, int len, int empty);
int				ft_printf(const char *str, ...);
int				parse_conv(const char **s, va_list ap, char *buf, int count);

/*
** CONV FUNCTIONS
*/

int				conv_str(va_list ap, char *buf, t_flags *f);
int				conv_char(va_list ap, char *buf, t_flags *f);
int				conv_perc(char *buf, t_flags *f);
int				conv_num(va_list ap, char *buf, t_flags *f);
int				str_conv(char *s, int len_s, char *buf);
int				str_conv_width(char *s, int len_s, char *buf, t_flags *f);
int				width_max(long n, char *buf, t_flags *f, int len);
int				zero_max(long n, char *buf, t_flags *f, int len);
int				prec_max(long n, char *buf, t_flags *f, int len);

/*
** UTILS FUNCTIONS
*/

void			t_init(t_flags *f);
void			neg_width(int width, t_flags *f, const char **str);
void			neg_star_prec(int prec, t_flags *f);
void			neg_prec(int prec, t_flags *f);
void			space_magic(char *buf, int width);
void			zero_magic(char *buf, int prec);
long			num_asign(va_list ap, char spec);
int				prec_str(char *s, int prec);
int				len_ul(unsigned long n, char spec);
int				sign_padd(long *nb, t_flags *f, char *buf);
int				n_save(va_list ap, int char_count);

/*
** LIB FUNCTIONS
*/

void			ltoa(char *buf, long n, t_flags *f);
void			ultoa_base(char *buf, unsigned long n, t_flags *f);
void			ft_cpy(char *dst, const char *src, int len);
int				ft_strlen(char *s);
int				dec_len(long n);
int				hexa_len(unsigned long n);
int				max(int a, int b);
int				ft_atoi(const char **str);
const char		*char_chr(const char *s);

#endif
