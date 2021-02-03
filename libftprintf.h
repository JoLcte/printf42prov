/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JoLecomte <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 17:35:00 by JoLecomte         #+#    #+#             */
/*   Updated: 2021/02/03 15:03:34 by jlecomte         ###   ########.fr       */
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
int	fzero; // = 0
int	fleft; // = 0
int fplus; // = 0
int fspace; // = 0
int prefix; // = 0
int	width; // = -1
int	prec; // -1
}				t_flags;

/*
 ** MAIN FUNCTIONS **
 */

int		ft_printf(const char *str, ...);
size_t	buf_pilot(char *buf, char *s, size_t len, size_t len_buff);

/*
 ** CONVERT FUNCTIONS **
 */

void	flags_parse(const char **str, t_flags *f);
void	bonus_parse(const char **str, t_flags *f);
void	width_n_prec(const char **str, t_flags *f);

/*
 ** UTILS FONCTIONS **
 */

char	*char_chr(char *s);
size_t	ft_strlen(char *s);
void	ft_cpy(char *dst, char *src, size_t len);

#endif
