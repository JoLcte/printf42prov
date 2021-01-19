/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifier.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiquiau <ggiquiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 11:33:55 by ggiquiau          #+#    #+#             */
/*   Updated: 2021/01/15 11:59:56 by ggiquiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long	get_long(t_conv c, va_list ap)
{
	long long	l;
	void		*ptr;

	l = 0;
	if (c.conv == 'p')
	{
		ptr = va_arg(ap, void*);
		l = ptr ? (unsigned long)ptr : 0;
	}
	else if (c.conv == 'd' || c.conv == 'i')
		l = va_arg(ap, int);
	else if (ft_strchr("uxX", c.conv))
		l = va_arg(ap, unsigned int);
	return (l);
}
