/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 20:37:34 by jlecomte          #+#    #+#             */
/*   Updated: 2021/03/05 22:12:31 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	space_magic(char *buf, int width)
{
	int rest;

	while (width > 0)
	{
		if (width > 16)
			rest = 16;
		else
			rest = width;
		buf_pilot(buf, "                ", rest, 0);
		width -= rest;
	}
}

void	zero_magic(char *buf, int prec)
{
	int rest;

	while (prec > 0)
	{
		if (prec > 16)
			rest = 16;
		else
			rest = prec;
		buf_pilot(buf, "0000000000000000", rest, 0);
		prec -= rest;
	}
}

long	num_asign(va_list ap, char spec)
{
	long n;

	n = 0;
	if (spec == 'd' || spec == 'i')
		n = va_arg(ap, int);
	else if (spec == 'x' || spec == 'X' || spec == 'u')
	{
		n = va_arg(ap, unsigned);
	}
	else if (spec == 'p')
		n = va_arg(ap, unsigned long);
	return (n);
}

int		len_ul(unsigned long n, char spec)
{
	if (spec == 'u')
		return (dec_len((unsigned)n));
	else if (spec == 'x' || spec == 'X')
		return (hexa_len((unsigned)n));
	else if (spec == 'p')
		return (hexa_len(n));
	return (0);
}

int		n_save(va_list ap, int count)
{
	int *n_ptr;

	n_ptr = va_arg(ap, int*);
	*n_ptr = count;
	return (0);
}
