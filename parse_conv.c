/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 12:30:02 by jlecomte          #+#    #+#             */
/*   Updated: 2021/02/03 17:02:57 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libftprintf.h"

void	bonus_parse(const char **s, t_flags *f)
{
	while (1)
	{
		if (**s == '#')
		{
			f->prefix = 1;
			(*s)++;
		}
		else if (**s == '+')
		{
			f->fplus = 1;
			(*s)++;
			if (f->fspace)
				f->fspace = 0;
		}
		else if (**s == ' ' && !f->fplus)
		{
			f->fspace = 1;
			(*s)++;
		}
		else
			break;
	}
}

void width_n_prec(const char **s, t_flags *f)
{
	if (**s == '*')
	{
		f->width = va_arg(ap, int);
		(*s)++;
	}
	if (**s >= '0' && <= '9')
		f->witdh = ft_atoi(s);
	if (**s == '.')
	{
		(*s)++;
		if (**s == '*')
		{
			f->prec = va_arg(ap, int);
			if (f->prec < 0)
				f->prec = -(f->prec);
		}
		else
			f->prec = ft_atoi(s);
	}
}

void	flags_parse(const char **s, t_flags *f)
{
	int w_or_prec;

	while (1)
	{
		if (**s == '0' && !(f->fleft))
		{
			f->fzero = 1;
			(*s)++;
		}
		else if (**s == '-')
		{
			while (**s == '-')
				(*s)++;
			f->fleft = 1;
			if (f->fzero)
				f->fzero = 0;
		}
		else
			break;
	}
	bonus_parse(s, f);
	width_n_prec(s, f);
}

int	padd_conv(const char **s, va_list ap, int len_buf, char *buf, t_flags *f)
{
	char *s;

	s = *s;
	if (*s == 'c' || *s == 's')
		return (str_conv(ap, len_buf, ...));
	else if (*s == 'p')
		return (ptr_conv(xxx));
	else if (*s == 'd' || *s == 'i' || *s == 'u'
			|| *s == 'o' || *s == 'x' || *s == 'X')
		return (num_conv(xxx));
	else
		return (0);
}

int	parse_conv(const char **str, va_list ap, int len_buf, char *buf)
{
	t_flags *f;
	char *s;
	int len;

	s = *str;
	*f = (t_flags){0, 0, 0, 0, 0, -1, -1};
	//SI *s = '%' on fait quoi
	flag_parse(&s, f);
	len = padd_conv(s, ap, len_buf, buf, f);
	return (len);
}
