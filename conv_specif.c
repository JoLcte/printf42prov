/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_specif.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 16:17:32 by jlecomte          #+#    #+#             */
/*   Updated: 2021/02/20 13:59:08 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

#include "libftprintf.h"

int	str_conv(char *s, size_t len_s, char *buf)
{
	buf_pilot(buf, s, len_s);
	return ((int)len_s);
}

int	str_conv_width(char *s, size_t len_s, char *buf, t_flags *f)
{
	const char s_width[f->width + 1];

	f->width -= (int)len_s;
	if (f->width > 0)
	{
		space_magic((char *)s_width, f->width);
		if (f->fleft)
		{
			buf_pilot(buf, s, len_s);
			buf_pilot(buf, s_width, f->width);
		}
		else
		{
			buf_pilot(buf, s_width, f->width);
			buf_pilot(buf, s, len_s);
		}
		return ((int)(len_s) + f->width);
	}
	return (f->width);
}

int ptr_conv(void *p, char *buf, t_flags *f)
{
	//ajouter 0x ?
	// faire des tests sur un char * par exemple
	// ou un *int
	return (0);
}

int numsign_conv(int num, char *buf, t_flags *f)
{

	return (0);
}

int numunsign_conv(unsigned int num, char *buf, t_flags *f)
{

	return (0);
}

int	conv_char(va_list ap, char *buf, t_flags *f)
{
	char	c[2];

	c[1] = 0;
	*c = (unsigned char)va_arg(ap, int);
	if (f->width > 1)
		return (str_conv_width(c, 1, buf, f));
	return (str_conv(c, 1, buf));
}

int	conv_str(va_list ap, char *buf, t_flags *f)
{
	size_t		len_s;
	char		*s;
	const char	nul_str[] = "(null)";

	s = va_arg(ap, char *);
	if (!s)
	{
		len_s = prec_str((char *)nul_str, f->prec);
		if (f->width > (int)len_s)
			return (str_conv_width((char *)nul_str, len_s, buf, f));
		return (str_conv((char *)nul_str, len_s, buf));
	}
	len_s = prec_str(s, f->prec);
	if (f->width > (int)len_s)
		return (str_conv_width(s, len_s, buf, f));
	return (str_conv(s, len_s, buf));
}

int	conv_num(va_list ap, char *buf, t_flags *f)
{
	if (f->spec == 'p')
		return (ptr_conv(va_arg(ap, void *), buf, f));
	else if (f->spec == 'd' || f->spec == 'i' || f->spec == 'u')
		return (numsign_conv(va_arg(ap, int), buf, f));
	else if (f->spec == 'o' || f->spec == 'x' || f->spec == 'X')
		return (numunsign_conv(va_arg(ap, unsigned int), buf, f));
	return (0);
}
