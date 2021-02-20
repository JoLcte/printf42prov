/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 12:30:02 by jlecomte          #+#    #+#             */
/*   Updated: 2021/02/20 16:53:08 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <unistd.h>
#include "libftprintf.h"

void	bonus_parse(const char **str, t_flags *f)
{
	const char *s = *str;

	while (1)
	{
		if (*s == '#')
			f->prefix = 1;
		else if (*s == '+')
		{
			f->fplus = 1;
			if (f->fspace)
				f->fspace = 0;
		}
		else if (*s == ' ' && !f->fplus)
			f->fspace = 1;
		else
			break ;
		++s;
	}
}

void	width_n_prec(const char **str, t_flags *f, va_list ap)
{
	const char *s = *str;

	if (*s == '*')
		neg_width(va_arg(ap, int), f, &s);
	if (*s >= '0' && *s <= '9')
		f->width = ft_atoi(&s);
	if (*s == '.')
	{
		++s;
		if (*s == '*')
		{
			neg_star_prec(va_arg(ap, int), f);
			++s;
		}
		else
			neg_prec(ft_atoi(&s), f);
	}
	*str = s;
}

void	flags_parse(const char **str, t_flags *f, va_list ap)
{
	const char *s = *str;

	while (1)
	{
		if (*s == '0' && !(f->fleft))
			f->fzero = 1;
		else if (*s == '-')
		{
			f->fleft = 1;
			if (f->fzero)
				f->fzero = 0;
		}
		else
			break ;
		++s;
	}
	bonus_parse(&s, f);
	width_n_prec(&s, f, ap);
	*str = s;
}

void	specif_parse(const char **str, t_flags *f)
{
	char c;

	c = **str;
	if (c == 'c' || c == 'd' || c == 'i' || c == 'o' || c == 'p' || c == 's'
		|| c == 'u' || c == 'x' || c == 'X')
		f->spec = c;
}

int		parse_conv(const char **s, va_list ap, char *buf)
{
	t_flags		f;
	const char	*save;

	save = *s;
	if (**s == '%')
	{
		buf_pilot(buf, *s, 1);
		return (1);
	}
	t_init(&f);
	flags_parse(s, &f, ap);
	specif_parse(s, &f);
	++(*s);
	if (f.spec == 'c')
		return (conv_char(ap, buf, &f));
	if (f.spec == 's')
		return (conv_str(ap, buf, &f));
	else if (f.spec == 'p' || f.spec == 'u' || f.spec == 'o' || f.spec == 'X'
		|| f.spec == 'd' || f.spec == 'i')
		return (conv_num(ap, buf, &f));
	return (*s - save);
}
