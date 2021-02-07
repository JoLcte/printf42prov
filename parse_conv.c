/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 12:30:02 by jlecomte          #+#    #+#             */
/*   Updated: 2021/02/07 16:26:20 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libftprintf.h"

static t_flags	*t_init(t_flags *f)
{
	f->fzero = 0;
	f->fleft = 0;
	f->fplus = 0;
	f->fspace = 0;
	f->prefix = 0;
	f->width = -1;
	f->prec = -1;
	return (f);
}

void			bonus_parse(const char **str, t_flags *f)
{
	const char *s = *str;

	while (1)
	{
		if (*s == '#')
		{
			f->prefix = 1;
			s++;
		}
		else if (*s == '+')
		{
			f->fplus = 1;
			s++;
			if (f->fspace)
				f->fspace = 0;
		}
		else if (*s == ' ' && !f->fplus)
		{
			f->fspace = 1;
			s++;
		}
		else
			break ;
	}
}

void			width_n_prec(const char **str, t_flags *f, va_list ap)
{
	const char *s = *str;

	while (1)
	{
		if (*s == '*')
			neg_width(ap, f, &s);
		else if (*s >= '0' && *s <= '9')
			f->width = ft_atoi(&s);
		else if (*s == '.')
		{
			s++;
			if (*s == '*')
				neg_prec(ap, f, &s);
			else
			{
				f->prec = ft_atoi(&s);
				f->fzero = 0;
			}
		}
		else
			break ;
	}
	*str = s;
}

void			flags_parse(const char **str, t_flags *f, va_list ap)
{
	const char *s = *str;

	while (1)
	{
		if (*s == '0' && !(f->fleft))
		{
			f->fzero = 1;
			s++;
		}
		else if (*s == '-')
		{
			while (*s == '-')
				s++;
			f->fleft = 1;
			if (f->fzero)
				f->fzero = 0;
		}
		else
			break ;
	}
	bonus_parse(&s, f);
	width_n_prec(&s, f, ap);
}

int				parse_conv(const char **s, va_list ap, int len_buf, char *buf)
{
	t_flags *f;
	int		len;

	if (*(*s + 1) == '%')
	{
		len_buf = buf_pilot(buf, (char *)(*s)++, 1, len_buf);
		return (1);
	}
	f = t_init(f);
	flags_parse(s, f, ap);
	len = padd_conv(s, ap, len_buf, buf, f);
	(*s)++;
	return (len);
}
