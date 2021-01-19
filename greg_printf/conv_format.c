/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiquiau <ggiquiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 11:43:31 by ggiquiau          #+#    #+#             */
/*   Updated: 2021/01/15 14:21:30 by ggiquiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			c_format(char **res, int ch, t_conv c)
{
	if (!c.ladjust)
		fill_char2(c.padc, res, c.width - 1);
	*(*res)++ = ch;
	return (1);
}

int			perc_format(char **res, t_conv c)
{
	if (!c.ladjust)
		fill_char2(c.padc, res, c.width - 1);
	*(*res)++ = '%';
	return (1);
}

static int	int_setup(long long l, int len, int neg, t_conv *c)
{
	if (l == 0 && c->precision == 0)
		len = 0;
	if (neg)
		c->precision++;
	if (c->precision <= -1)
		c->precision = len;
	if (neg)
		c->sign = '-';
	if (c->conv == 'p')
	{
		len += 2;
		c->precision += 2;
	}
	return (len);
}

static void	add_prefix(char **res, t_conv c)
{
	if (c.sign > 1)
		*(*res)++ = c.sign;
	if (c.conv == 'p')
	{
		ft_strcat("0x", res, 2);
	}
}

int			int_format(char **res, long long l, t_conv c, int prec)
{
	int					len;
	int					neg;
	unsigned long long	u;

	neg = (l < 0);
	if (!c.sign)
		neg = 0;
	if (neg)
		u = -l;
	else
		u = l;
	len = num_len_llu(u, c.base) + neg;
	len = int_setup(l, len, neg, &c);
	if ((c.padc == '0' ||
		!(c.width > len && c.width > c.precision && !c.ladjust)))
		add_prefix(res, c);
	if (!c.ladjust)
		fill_char2(c.padc, res, c.width - max(c.precision, len));
	if (c.padc == ' ' && c.width > len && c.width > c.precision && !c.ladjust)
		add_prefix(res, c);
	fill_char2('0', res, c.precision - len);
	if (!(l == 0 && prec == 0))
		ft_llutoa_base(res, u, str_base(c.conv));
	len = max(c.precision, len);
	return (len);
}
