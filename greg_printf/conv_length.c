/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_length.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiquiau <ggiquiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 11:27:03 by ggiquiau          #+#    #+#             */
/*   Updated: 2021/01/15 14:14:14 by ggiquiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ch_len(int ch)
{
	(void)ch;
	return (1);
}

int	s_len(char *s, t_conv c)
{
	int len;

	if (s)
	{
		len = (ft_strlen(s));
	}
	else
		len = (6);
	if (c.precision <= -1)
		c.precision = len;
	len = max(min(c.precision, len), c.width);
	return (len);
}

int	pdiuxx_len(long long l, t_conv c)
{
	int					len;
	int					neg;
	unsigned long long	lu;

	neg = (l < 0);
	if (!c.sign)
		neg = 0;
	if (neg)
		lu = -l;
	else
		lu = l;
	len = num_len_llu(lu, c.base) + neg;
	if (l == 0 && c.precision == 0)
		len = 0;
	if (neg)
		c.precision++;
	len = max(len, c.precision);
	if (c.conv == 'p')
		len += 2;
	return (len);
}
