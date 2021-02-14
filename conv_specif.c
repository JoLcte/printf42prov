/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_specif.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 16:17:32 by jlecomte          #+#    #+#             */
/*   Updated: 2021/02/14 16:54:08 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

#include "libftprintf.h"

int	char_conv(int c, size_t *len_buf, char *buf, t_flags *f)
{
	return (0);
}

int	str_conv(char *s, size_t *len_buf, char *buf, t_flags *f)
{
	size_t len_s;
	char s_width[f->width];
	size_t l_buf;

	len_s = ft_strlen(s);
	l_buf = *len_buf;
	if (f->prec > len_s)
	{
		s[f->prec] = 0;
		len_s = ft_strlen(s);
		//printf("len_s apres prec : %zu\n", len_s);
	}
	f->width -= len_s;
	//printf("f->width apres soustraction: %zu\n", f->width);
	if (f->width > 0)
	{
		space_magic(s_width, f->width);
		printf("s_width: |%s|\n", s_width);
		if (f->fleft)
		{
			l_buf = buf_pilot(buf, s, len_s, l_buf);
			l_buf = buf_pilot(buf, s_width, f->width, l_buf);
		}
		else
		{
			l_buf = buf_pilot(buf, s_width, f->width, l_buf);
			l_buf = buf_pilot(buf, s, len_s, l_buf);
		}
		return ((int)(len_s) + (int)f->width);
	}
	return (f->width);
	//substitute functions inside to make it shorter
}

int ptr_conv(void *p, size_t *len_buf, char *buf, t_flags *f)
{
	//ajouter 0x ?
	// faire des tests sur un char * par exemple
	// ou un *int
	return (0);
}

int numsign_conv(int num, size_t *len_buf, char *buf, t_flags *f)
{

	return (0);
}

int numunsign_conv(unsigned int num, size_t *len_buf, char *buf, t_flags *f)
{

	return (0);
}

int	padd_conv(const char **str, va_list ap, size_t *len_buf, char *buf, t_flags *f)
{
	const char *s = *str;

	//printf("on est dans padd_conv\n");
	//printf("*s = |%c|\n", *s);

	if (*s == 'c')
		return (char_conv(va_arg(ap, int), len_buf, buf, f)); // a regler
	else if (*s == 's')
		return (str_conv(va_arg(ap, char *), len_buf, buf, f));
	else if (*s == 'p')
		return (ptr_conv(va_arg(ap, void *), len_buf, buf, f));
	else if (*s == 'd' || *s == 'i' || *s == 'u')
		return (numsign_conv(va_arg(ap, int), len_buf, buf, f));
	else if (*s == 'o' || *s == 'x' || *s == 'X')
		return (numunsign_conv(va_arg(ap, unsigned int), len_buf, buf, f));
	else
		return (0);
}
