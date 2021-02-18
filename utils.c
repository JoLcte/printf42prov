/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 09:46:41 by jlecomte          #+#    #+#             */
/*   Updated: 2021/02/18 17:10:43 by jlecomte         ###   ########.fr       */
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
	char *ptr_s;

	s[n] = 0;
	ptr_s = s;
	while (n--)
	{
		*ptr_s++ = ' ';
	}
	return (s);
}

size_t	prec_str(char *s, int prec)
{
	size_t len;

	len = ft_strlen(s);
	if (prec < len)
	{
		s[prec] = 0;
		return (prec);
	}
	return (len);
}

void	t_init(t_flags *f)
{
	f->fzero = 0;
	f->fleft = 0;
	f->fplus = 0;
	f->fspace = 0;
	f->prefix = 0;
	f->width = -1;
	f->prec = -1;
	f->spec = 0;
}
