/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 18:13:47 by jlecomte          #+#    #+#             */
/*   Updated: 2021/03/05 16:41:39 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			dec_len(long n)
{
	if (n < 10)
		return (1);
	if (n < 100)
		return (2);
	if (n < 1000)
		return (3);
	if (n < 10000)
		return (4);
	if (n < 100000)
		return (5);
	if (n < 1000000)
		return (6);
	if (n < 10000000)
		return (7);
	if (n < 100000000)
		return (8);
	if (n < 1000000000)
		return (9);
	if (n >= 1000000000)
		return (10);
	return (0);
}

int			hexa_len(unsigned long n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 16;
		i++;
	}
	return (i);
}

static int	fill_base(char *str_base, char spec)
{
	const char *base = "0123456789abcdef";
	const char *u_base = "0123456789ABCDEF";

	if (spec == 'X')
		ft_cpy(str_base, u_base, 16);
	else
		ft_cpy(str_base, base, 16);
	if (spec == 'u' || spec == 'd' || spec == 'i')
		return (10);
	return (16);
}

void		ltoa(char *buf, long n, t_flags *f)
{
	char	num[11];
	int		i;

	i = 10;
	num[i] = 0;
	if (n == 0)
	{
		if (f->prec)
			buf_pilot(buf, "0", 1, 0);
	}
	while (n)
	{
		num[--i] = n % 10 + '0';
		n /= 10;
	}
	buf_pilot(buf, num + i, 10 - i, 0);
	if (f->prec < 0)
		f->prec = 0;
}

void		ultoa_base(char *buf, unsigned long n, t_flags *f)
{
	char		str_base[16];
	char		num[21];
	int			i;
	int			l_base;

	i = 20;
	num[i] = 0;
	l_base = fill_base(str_base, f->spec);
	if (n == 0)
	{
		if (f->prec || f->spec == 'p')
			buf_pilot(buf, "0", 1, 0);
	}
	while (n)
	{
		num[--i] = str_base[n % l_base];
		n /= l_base;
	}
	buf_pilot(buf, num + i, 20 - i, 0);
	if (f->prec < 0)
		f->prec = 0;
}
