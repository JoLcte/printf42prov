/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 16:20:39 by jlecomte          #+#    #+#             */
/*   Updated: 2021/02/07 16:01:32 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	neg_width(va_list ap, t_flags *f, const char **str)
{
	f->width = va_arg(ap, int);
	if (f->width < 0)
	{
		f->width *= -1;
		if (f->left = 1)
			f->left = 0;
		else
			f->left = 1;
	}
	(*s)++;
}

void	neg_prec(va_list ap, t_flags *f, const char **str)
{
	f->prec = va_arg(ap, int);
	if (f->prec < 0)
		f->prec = 0;
	(*s)++;
}
