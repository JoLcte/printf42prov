/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draft_others.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JoLecomte <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 17:08:09 by JoLecomte         #+#    #+#             */
/*   Updated: 2021/01/23 23:54:00 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libftprintf.h"

char	*conv_parse(const char *str, va_list arg_ptr)
{
	char *tmp;
	int size_conv; // pour calculer la size du param de la pile pointé par arg_ptr
	t_flags	*p;

	p = f_parse(str);
	//gérer cas d'erreur ("%234234.coucou" par exemple)
	size_conv = ft_strlen(va_arg(ap, type)); // recup le type dans la fonction parse
	//prendre en charge la structure, voir comment amener va_truc là dedans

	// si autre : remplir flag_conv + si flag_conv.type est num -> ft_conv_num
	// else : ft_conv_str
}

t_flags *f_conv(const char *str)
{
//add '#' ' ' '+'
	t_flags *p;

	*p = {0, 0, 0, 0, 0}
	while (*str)
	{
	if (*str == '-')
	p->fminus = 1;
//... ou alors faire 3 fonctions (-,0),(width precision), (type)
	}
	if (*str == '-')
	{
		while (*str == '-')
			str++;
		p->fminus = 1;
	}
	if (*str == '0')
	{
		p->fzero = 1;
		str++;
	}
	if (*str == '*')
	{
		p->fstar = //va_arg(ap, int);
		str++;
	}
	if (*str == '.')
	{
		str++;
		if (*str == '*' && p->w_star)
		{
			p->prec = ft_atoi(arg + 2);
			str++;
		}
		else if (*str == '*' && !p->w_star)
		{
			p->prec = ft_atoi(arg + 1);
			str++;
		}
		else if (*str >= 0 && *str <= 9)
		{
			p->prec = ft_atoi(str);
			str++;
		}
		else
			p->prec = 0;
	}
//gérer les types
return (p);
}
