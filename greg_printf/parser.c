/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiquiau <ggiquiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 11:17:39 by ggiquiau          #+#    #+#             */
/*   Updated: 2021/01/15 14:46:31 by ggiquiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		parse_flag(char *str, t_conv *c, int *i, int n)
{
	while (*i < n && is_flag(str[*i]))
	{
		if (str[*i] == '-')
			c->ladjust = 1;
		else if (str[*i] == '0')
			c->padc = '0';
		(*i)++;
	}
}

static void		parse_width(char *str, t_conv *c, int *i, va_list ap)
{
	if (ft_isdigit(str[*i]))
	{
		c->width = ft_atoi(str + *i);
		while (ft_isdigit(str[*i]))
			(*i)++;
	}
	else if (str[*i] == '*')
	{
		c->width = va_arg(ap, int);
		if (c->width < 0)
		{
			c->ladjust = 1;
			c->width = -c->width;
		}
		(*i)++;
	}
}

static void		parse_prec(char *str, t_conv *c, int *i, va_list ap)
{
	if (str[*i] == '.')
	{
		(*i)++;
		if (ft_isdigit(str[*i]))
		{
			c->precision = ft_atoi(str + *i);
			while (ft_isdigit(str[*i]))
				(*i)++;
		}
		else if (str[*i] == '*')
		{
			c->precision = va_arg(ap, int);
			(*i)++;
		}
		else
			c->precision = 0;
		if (ft_strchr("diuxXp", c->conv) && c->precision >= 0)
			c->padc = ' ';
	}
}

static t_conv	init(void)
{
	t_conv	new;

	new.padc = ' ';
	new.ladjust = 0;
	new.width = 0;
	new.precision = -1;
	new.sign = 1;
	new.base = 10;
	return (new);
}

t_conv			init_conv(char *str, int n, va_list ap)
{
	t_conv	new;
	int		i;

	i = 0;
	new = init();
	new.conv = str[n];
	parse_flag(str, &new, &i, n);
	parse_width(str, &new, &i, ap);
	parse_prec(str, &new, &i, ap);
	if (ft_strchr("uXxp", new.conv))
		new.sign = 0;
	if (ft_strchr("xXp", new.conv))
		new.base = 16;
	return (new);
}
