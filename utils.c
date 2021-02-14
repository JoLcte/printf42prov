/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 09:46:41 by jlecomte          #+#    #+#             */
/*   Updated: 2021/02/14 16:14:30 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 16:20:39 by jlecomte          #+#    #+#             */
/*   Updated: 2021/02/11 16:56:09 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "libftprintf.h"

void	neg_width(va_list ap, t_flags *f, const char **s)
{
	f->width = va_arg(ap, size_t);
	if (f->width < 0)
	{
		f->width *= -1;
		if (f->fleft == 1)
			f->fleft = 0;
		else
			f->fleft = 1;
	}
	++(*s);
}

void	neg_prec(va_list ap, t_flags *f, const char **s)
{
	f->prec = va_arg(ap, size_t);
	if (f->prec < 0)
		f->prec *= -1;
	++(*s);
}

char	*space_magic(char *s, size_t n)
{
	printf("on est entre dans space magic et n = %zu\n", n);
	char *ptr_s;

	s[n] = 0;
	ptr_s = s;
	while (n--)
	{
		printf("n = %zu\n", n);
		*ptr_s++ = ' ';
	}
	return (s);
}
