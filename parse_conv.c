/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 12:30:02 by jlecomte          #+#    #+#             */
/*   Updated: 2021/01/28 16:29:47 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libftprintf.h"

void	bonus_parse(const char **str, t_flags *f)
{
	while (1)
	{
		if (**str == '#')
		{
			f->prefix = 1;
			(*str)++;
		}
		else if (**str == '+')
		{
			f->fplus = 1;
			(*str)++;
			if (f->fspace)
				f->fspace = 0;
		}
		else if (**str == ' ' && !f->fplus)
		{
			f->fspace = 1;
			(*str)++;
		}
		else
			break;
	}
}

void width_n_prec(const char **str, t_flags *f)
{ 
	if (**str == '*')
	{
		f->width = va_arg(ap, int);
	(*str)++;
	}
	if (**str >= '0' && <= '9')
		f->witdh = ft_atoi(str);
	if (**str == '.')
	{
		(*str)++;
		if (**str == '*')
		{
			f->prec = va_arg(ap, int);
			if (f->prec < 0)
				f->prec = -(f->prec);
		}
		else 
			f->prec = ft_atoi(str);
	}
}

void	flags_parse(const char **str, t_flags *f)
{
	int w_or_prec;

	while (1)
	{
		if (**str == '0' && !(f->fleft))
		{
			f->fzero = 1;
			(*str)++;
		}
		else if (**str == '-')
		{
			while (**str == '-')
				(*str)++;
			f->fleft = 1;
			if (f->fzero)
				f->fzero = 0;
		}
		else
			break;
	}
	bonus_parse(str, f);
	width_n_prec(str, f);
}

int	padd_conv(const char **str, va_list ap, int len_buff, char *buff, t_flags *f)
{
	// gestion du specifier
	// envoyer dans conv_str ou dans conv_num
	//gestion du buffer : mettre tout une fois converti dans le buff -> gerer dans parse_conv ?
	//return int (char_count) ou return char *(buff) ?
}

int	parse_conv(const char **str, va_list ap, int len_buff, char *buff)
{
	t_flags *f;

	*f = (t_flags){0, 0, 0, 0, 0, 0, 0};
	if (**(str + 1) && **(str + 1) == '%')
		buff[len_buff++] = '%'; //check si ca marche ca... pas sur
	//1) parsing flags width prec
	len_buff = flush_buff(buff, len_buff);
	flag_parse(str, f);
	//2) specifier and conv
	buff = padd_conv ou len_buf += padd_conv ?
	
}

//3) specifier type or 2+3 depending on size
//fonction qui conv en fonction de t_flags *f et specifier, et len_buff
//qui return le nombre de char final -> char_count+= conv_function
//GERER LEN_BUFF pour flush;
return (len_buff);
}
