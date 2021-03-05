/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 21:49:58 by jlecomte          #+#    #+#             */
/*   Updated: 2021/03/05 22:07:39 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conv_perc(char *buf, t_flags *f)
{
	if (f->width > 1)
	{
		if (f->fzero && !f->fleft)
		{
			zero_magic(buf, f->width - 1);
			buf_pilot(buf, "%", 1, 0);
			return (f->width);
		}
		return (str_conv_width("%", 1, buf, f));
	}
	return (str_conv("%", 1, buf));
}

int	str_conv(char *s, int len_s, char *buf)
{
	buf_pilot(buf, s, len_s, 0);
	return (len_s);
}

int	str_conv_width(char *s, int len_s, char *buf, t_flags *f)
{
	f->width -= len_s;
	if (f->width > 0)
	{
		if (f->fleft)
		{
			buf_pilot(buf, s, len_s, 0);
			space_magic(buf, f->width);
		}
		else
		{
			space_magic(buf, f->width);
			buf_pilot(buf, s, len_s, 0);
		}
		return ((len_s) + f->width);
	}
	return (f->width);
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
	int			len_s;
	char		*s;
	const char	*nul_str = "(null)";

	s = va_arg(ap, char*);
	if (!s)
	{
		len_s = prec_str((char *)nul_str, f->prec);
		if (f->width > len_s)
			return (str_conv_width((char *)nul_str, len_s, buf, f));
		return (str_conv((char *)nul_str, len_s, buf));
	}
	len_s = prec_str(s, f->prec);
	if (f->width > len_s)
		return (str_conv_width(s, len_s, buf, f));
	return (str_conv(s, len_s, buf));
}
