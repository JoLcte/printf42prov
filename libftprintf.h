/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JoLecomte <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 17:35:00 by JoLecomte         #+#    #+#             */
/*   Updated: 2021/02/14 14:40:11 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

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
	size_t	width;
	size_t	prec;
}				t_flags;

/*
** MAIN FUNCTIONS
*/

int				ft_printf(const char *str, ...);
size_t			buf_pilot(char *buf, const char *s, size_t len,
					size_t len_buff);

/*
** PARSING FUNCTIONS
*/

void			flags_parse(const char **str, t_flags *f, va_list ap);
void			bonus_parse(const char **str, t_flags *f);
void			width_n_prec(const char **str, t_flags *f, va_list ap);
int				parse_conv(const char **s, va_list ap, size_t len_buf,
					char *buf);

/*
** CONV FUNCTIONS
*/

int				char_conv(int c, size_t *len_buf, char *buf, t_flags *f);
int				padd_conv(const char **str, va_list ap, size_t *len_buf,
					char *buf, t_flags *f);
int				str_conv(char *s, size_t *len_buf, char *buf, t_flags *f);
int				ptr_conv(void *p, size_t *len_buf, char *buf, t_flags *f);
int				numsign_conv(int num, size_t *len_buf, char *buf, t_flags *f);
int				numunsign_conv(unsigned int num, size_t *len_buf, char *buf,
					t_flags *f);

/*
** UTILS FUNCTIONS
*/

void			neg_width(va_list ap, t_flags *f, const char **str);
void			neg_prec(va_list ap, t_flags *f, const char **str);
char			*space_magic(char *s, size_t n);

/*
** LIB FUNCTIONS
*/

const char		*char_chr(const char *s);
size_t			ft_strlen(char *s);
void			ft_cpy(char *dst, const char *src, size_t len);
int				ft_atoi(const char **str);

#endif
