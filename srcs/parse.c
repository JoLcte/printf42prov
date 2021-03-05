/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 12:30:02 by jlecomte          #+#    #+#             */
/*   Updated: 2021/03/05 22:11:08 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	clean_flags(t_flags *f)
{
	if (f->fleft && f->fzero)
		f->fzero = 0;
	if (f->fplus && f->fspace)
		f->fspace = 0;
}

static void	flags_parse(const char **str, t_flags *f)
{
	const char *s = *str;

	while (1)
	{
		if (*s == '0')
			f->fzero = 1;
		else if (*s == '-')
			f->fleft = 1;
		else if (*s == '#')
			f->prefix = 1;
		else if (*s == '+')
			f->fplus = 1;
		else if (*s == ' ')
			f->fspace = 1;
		else
			break ;
		if (*s)
			++s;
	}
	*str = s;
	clean_flags(f);
}

static void	width_n_prec(const char **str, t_flags *f, va_list ap)
{
	const char *s = *str;

	if (*s == '*')
		neg_width(va_arg(ap, int), f, &s);
	if (*s >= '1' && *s <= '9')
		f->width = ft_atoi(&s);
	if (*s == '.')
	{
		f->prec = 0;
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

static void	specif_parse(const char **str, t_flags *f)
{
	char c;

	c = **str;
	if (c == 'c' || c == 'd' || c == 'i' || c == 'n' || c == 'p' || c == 's'
			|| c == 'u' || c == 'x' || c == 'X')
		f->spec = c;
}

int			parse_conv(const char **s, va_list ap, char *buf, int char_count)
{
	t_flags		f;
	const char	*save;

	save = *s;
	t_init(&f);
	flags_parse(s, &f);
	width_n_prec(s, &f, ap);
	specif_parse(s, &f);
	if (**s == '%')
	{
		++(*s);
		return (conv_perc(buf, &f));
	}
	if (**s)
		++(*s);
	if (f.spec == 'c')
		return (conv_char(ap, buf, &f));
	else if (f.spec == 's')
		return (conv_str(ap, buf, &f));
	else if (f.spec == 'p' || f.spec == 'u' || f.spec == 'x' || f.spec == 'X'
			|| f.spec == 'd' || f.spec == 'i')
		return (conv_num(ap, buf, &f));
	else if (f.spec == 'n')
		return (n_save(ap, char_count));
	return (*s - save);
}
