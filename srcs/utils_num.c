/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 20:25:55 by jlecomte          #+#    #+#             */
/*   Updated: 2021/03/05 22:13:48 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	sign_padd(long *nb, t_flags *f, char *buf)
{
	long	n;
	int		sign;

	n = *nb;
	sign = 0;
	if (n < 0)
	{
		buf_pilot(buf, "-", ++sign, 0);
		n = -n;
	}
	else
	{
		if (f->fplus)
			buf_pilot(buf, "+", ++sign, 0);
		else if (f->fspace)
			buf_pilot(buf, " ", ++sign, 0);
	}
	*nb = n;
	return (sign);
}

int	width_max(long n, char *buf, t_flags *f, int len)
{
	int			sign;
	const int	save = f->width;

	sign = 0;
	f->width -= len;
	if (f->prec > len)
		f->width -= (f->prec - len);
	if (f->fleft)
	{
		sign = sign_padd(&n, f, buf);
		zero_magic(buf, f->prec - len);
		ltoa(buf, n, f);
		space_magic(buf, f->width - sign);
	}
	else
	{
		if (n < 0 || f->fspace || f->fplus)
			++sign;
		space_magic(buf, f->width - sign);
		sign_padd(&n, f, buf);
		zero_magic(buf, f->prec - len);
		ltoa(buf, n, f);
	}
	return (save);
}

int	zero_max(long n, char *buf, t_flags *f, int len)
{
	int	sign;

	f->width -= len;
	f->width *= (f->width > 0);
	sign = sign_padd(&n, f, buf);
	if (f->width)
		f->width -= sign;
	zero_magic(buf, f->width);
	ltoa(buf, n, f);
	return (f->width + len + sign);
}

int	prec_max(long n, char *buf, t_flags *f, int len)
{
	int	sign;

	sign = sign_padd(&n, f, buf);
	zero_magic(buf, f->prec - len);
	ltoa(buf, n, f);
	return (sign + f->prec);
}
