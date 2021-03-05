/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 16:17:32 by jlecomte          #+#    #+#             */
/*   Updated: 2021/03/05 22:06:47 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	buf_prefix(t_flags *f, char *buf)
{
	if (f->fleft)
	{
		if (f->spec == 'X')
			buf_pilot(buf, "0X", 2, 0);
		else
			buf_pilot(buf, "0x", 2, 0);
		f->width -= 2;
	}
	else
	{
		f->width -= 2;
		space_magic(buf, f->width);
		if (f->spec == 'X')
			buf_pilot(buf, "0X", 2, 0);
		else
			buf_pilot(buf, "0x", 2, 0);
	}
	return (2);
}

static int	prewidth_max(unsigned long n, char *buf, t_flags *f, int len)
{
	int			prefix;
	const int	save = f->width;

	prefix = 0;
	f->width -= len;
	if (f->prec > len)
		f->width -= (f->prec - len);
	if ((f->prefix && n) || f->spec == 'p')
		prefix = buf_prefix(f, buf);
	if (f->fleft)
	{
		zero_magic(buf, f->prec - len);
		ultoa_base(buf, n, f);
		space_magic(buf, f->width);
	}
	else
	{
		if (!prefix)
			space_magic(buf, f->width);
		zero_magic(buf, f->prec - len);
		ultoa_base(buf, n, f);
	}
	if (f->width < 0 && prefix)
		return (len + prefix + (f->prec - len) * (f->prec > 0));
	return (save);
}

static int	unsign_conv(unsigned long n, char *buf, t_flags *f, int len)
{
	int prefix;

	prefix = 0;
	if (!f->prec && !n)
		len = 0;
	if (f->width > max(f->prec, len) && !f->fzero)
		return (prewidth_max(n, buf, f, len));
	if ((f->prefix && n) || f->spec == 'p')
	{
		f->fleft = 1;
		prefix = buf_prefix(f, buf);
	}
	if (f->prec >= max(f->width, len) || f->fzero)
	{
		if (f->fzero && f->width >= len)
			f->prec = f->width;
		zero_magic(buf, f->prec - len);
		ultoa_base(buf, n, f);
		if (f->fzero && f->width < len)
			return (len + prefix);
		return (f->prec + prefix);
	}
	ultoa_base(buf, n, f);
	return (len + prefix);
}

static int	sign_conv(long n, char *buf, t_flags *f, int len)
{
	int sign;

	if (f->prec < 0 && n)
		f->prec = 0;
	if (!f->prec && !n)
		len = 0;
	if (f->width > max(len, f->prec) && !f->fzero)
		return (width_max(n, buf, f, len));
	else if (f->fzero && f->width > 0)
		return (zero_max(n, buf, f, len));
	else if (f->prec >= len && f->prec >= f->width)
		return (prec_max(n, buf, f, len));
	if (f->prec > 0)
		f->prec -= len;
	sign = sign_padd(&n, f, buf);
	ltoa(buf, n, f);
	return (len + sign);
}

int			conv_num(va_list ap, char *buf, t_flags *f)
{
	long	n;
	int		len;

	n = num_asign(ap, f->spec);
	if (f->spec == 'd' || f->spec == 'i')
	{
		if (n < 0)
			len = dec_len(-n);
		else
			len = dec_len(n);
		return (sign_conv(n, buf, f, len));
	}
	if (f->prec < 0 && n)
		f->prec = 0;
	len = len_ul(n, f->spec);
	if (f->spec == 'x' || f->spec == 'X' || f->spec == 'u')
		return (unsign_conv((unsigned)n, buf, f, len));
	if (f->spec == 'p')
	{
		f->prefix = 1;
		return (unsign_conv((unsigned long)n, buf, f, len));
	}
	return (0);
}
