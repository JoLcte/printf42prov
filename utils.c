/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 09:46:41 by jlecomte          #+#    #+#             */
/*   Updated: 2021/02/20 17:09:37 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "libftprintf.h"

void	neg_width(int width, t_flags *f, const char **s)
{
	if (width < 0)
	{
		f->width = -width;
		f->fleft = 1;
	}
	else
		f->width = width;
	++(*s);
}

void	neg_star_prec(int prec, t_flags *f)
{
	if (prec < 0)
	{
		if (f->width == -1)
		{
			f->fleft = 1;
			f->width = -prec;
		}
		f->prec = -1;
	}
	else
	{
		f->prec = prec;
		f->fzero = 0;
	}
}
void	neg_prec(int prec, t_flags *f)
{
	if (prec < 0)
	{
		f->fleft = 1;
		f->width = -prec;
		f->prec = 0;
	}
	else
	{
		f->prec = prec;
		f->fzero = 0;
	}
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
	if (prec < (int)len && prec > -1)
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
