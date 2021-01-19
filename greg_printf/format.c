/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiquiau <ggiquiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 11:50:06 by ggiquiau          #+#    #+#             */
/*   Updated: 2021/01/15 14:15:22 by ggiquiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		s_format(char **res, char *s, t_conv c)
{
	int len;

	if (s)
	{
		len = ft_strlen(s);
	}
	else
		len = 6;
	if (c.precision <= -1)
		c.precision = len;
	len = min(c.precision, len);
	if (!c.ladjust)
		fill_char2(c.padc, res, c.width - len);
	ft_strcat(s ? s : "(null)", res, len);
	return (len);
}

int		format(t_conv c, char **res, va_list ap)
{
	int len;

	len = 0;
	if (c.conv == 'c')
		len = c_format(res, va_arg(ap, int), c);
	else if (c.conv == '%')
		len = perc_format(res, c);
	else if (c.conv == 's')
		len = s_format(res, va_arg(ap, char*), c);
	else if (ft_strchr("pdiuxX", c.conv))
		len = int_format(res, get_long(c, ap), c, c.precision);
	else
		va_arg(ap, void*);
	if (len != -1 && c.ladjust)
		fill_char2(' ', res, c.width - len);
	return (len != -1);
}
