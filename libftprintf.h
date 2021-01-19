/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JoLecomte <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 17:35:00 by JoLecomte         #+#    #+#             */
/*   Updated: 2021/01/17 16:10:45 by jlecomte         ###   ########.fr       */
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

typedef struct		s_flags
{
int	fzero;
int	fminus;
int	width;
int	prec;
int	w_star;
}		t_flags;

int		ft_printf(const char *str, ...);
//char	*ft_memcpy(char *dst, char *src, size_t n);
size_t	ft_strlen(char *s);
//char	*dynq_strcat(char *dst, char *src, int len);
//char	*len_strdup(char *dst, char *src, int len);

#endif
