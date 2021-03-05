/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 09:46:41 by jlecomte          #+#    #+#             */
/*   Updated: 2021/03/04 23:14:19 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	neg_width(int width, t_flags *f, const char **s)
{
	if (width < 0)
	{
		f->width = -width;
		f->fleft = 1;
		f->fzero = 0;
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

int		prec_str(char *s, int prec)
{
	int len;

	len = ft_strlen(s);
	if (prec < len && prec > -1)
		return (prec);
	return (len);
}

void	t_init(t_flags *f)
{
	f->fzero = 0;
	f->fleft = 0;
	f->fplus = 0;
	f->fspace = 0;
	f->prefix = 0;
	f->width = 0;
	f->prec = -1;
	f->spec = 0;
}
