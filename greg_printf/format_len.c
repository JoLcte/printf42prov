/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiquiau <ggiquiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 15:54:01 by ggiquiau          #+#    #+#             */
/*   Updated: 2021/01/15 12:03:27 by ggiquiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_len(t_conv c, va_list ap)
{
	int		len;

	len = 0;
	if (c.conv == 'c')
		len = ch_len(va_arg(ap, int));
	else if (c.conv == 's')
		len = s_len(va_arg(ap, char*), c);
	else if (c.conv == '%')
		len = 1;
	else if (ft_strchr("pdiuxX", c.conv))
		len = pdiuxx_len(get_long(c, ap), c);
	else
		va_arg(ap, void*);
	if (len != -1)
		len = max(len, c.width);
	return (len);
}
