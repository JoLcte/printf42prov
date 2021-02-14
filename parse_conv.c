/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 12:30:02 by jlecomte          #+#    #+#             */
/*   Updated: 2021/02/14 16:36:47 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

#include <unistd.h>
#include "libftprintf.h"

void	t_init(t_flags *f)
{
	f->fzero = 0;
	f->fleft = 0;
	f->fplus = 0;
	f->fspace = 0;
	f->prefix = 0;
	f->width = -1;
	f->prec = -1;
	//printf("on a init f\n");
}

void			bonus_parse(const char **str, t_flags *f)
{
	const char *s = *str;
//printf("on est dans bonus_parse\n");
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

void			width_n_prec(const char **str, t_flags *f, va_list ap)
{
	const char *s = *str;
	//printf("on est dans width_n_prec\n");
	//printf("*s avant width: %s\n", s);

	if (*s == '*')
		neg_width(ap, f, &s);
	if (*s >= '0' && *s <= '9')
	{
		printf("il a reconnu un chiffre\n");
		f->width = ft_atoi(&s);
		//printf("width: %d\n", f->width);
	}
	if (*s == '.')
	{
		++s;
		if (*s == '*')
			neg_prec(ap, f, &s);
		else
		{
			f->prec = ft_atoi(&s);
			f->fzero = 0;
		}
	}
	*str = s;
}

void			flags_parse(const char **str, t_flags *f, va_list ap)
{
	const char *s = *str;
//printf("on est dans flags_parse\n");
	while (1)
	{
		//printf("on a boucle\n");
		if (*s == '0' && !(f->fleft))
			f->fzero = 1;
		else if (*s == '-')
		{
			//printf("on a bien detect le -\n");
			f->fleft = 1;
			if (f->fzero)
				f->fzero = 0;
		}
		else
		{
			//printf("on abreak\n");
			break ;
		}
		++s;
		//printf("dans la boucle flag: %s\n", s);
	}
	bonus_parse(&s, f);
	width_n_prec(&s, f, ap);
	*str = s;
	//printf("fleft = %d\n", f->fleft);
}

int				parse_conv(const char **s, va_list ap, size_t len_buf,
					char *buf)
{
	t_flags flags;
	int		len;

	//printf("on est dans parse_conv\n");
	if (**s == '%')
	{
		//printf("deuxieme pour cent\n");
		len_buf = buf_pilot(buf, (char *)(*s), 1, len_buf);
		return (1);
	}
	t_init(&flags);
	flags_parse(s, &flags, ap);
	//printf("*s avant padd_conv: |%s|\n", *s);
	len = padd_conv(s, ap, &len_buf, buf, &flags);
	++(*s);
	return (len);
}
