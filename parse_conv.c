/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 12:30:02 by jlecomte          #+#    #+#             */
/*   Updated: 2021/01/25 17:09:57 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libftprintf.h"

int	flush_buff(char *s, int len_buff)
{
	if (len_buff == BUFSIZ)
	{
		write (1, s, len_buff);
		*buff = 0;
		len_buff = 0;
	}
	return (len_buff);
}

int	flag_parse(const char **str, t_flags *f)
{
	int w_or_prec;

	while (!(**str >= 'E' && **str <= 'x'))
	{
		if (**str == '0' && !(f->fleft))
		{
			f->fzero = 1;
			(*str)++;
		}
		if (**str == '-')
		{
			while (**str == '-')
				(*str)++;
			f->fleft = 1;
			if (f->fzero)
				f->fzero = 0;
		}

	}
	w_or_prec = bonus_parse(str, f);
	if (w_or_prec)
		return (1);
	return (0);
}
//GERER COMMENT ON FAit QUAND IL Y A DES FLAGS BONUS AU MILIEU DES PAS BONUS
int	bonus_parse(const char **str, t_flags *f)
{
	if (**str == '#')
	{
		f->prefix = 1;
		(*str)++;
	}
	if (**str == '+')
	{
		f->fplus = 1;
		(*str)++;
		if (f->fspace)
			f->fspace = 0;
	}
	if (**str == ' ' && !f->fplus)
	{
		f->fspace = 1;
		(*str)++;
	}
	if (**str == '*' || **str == '.' || (**str >= 1 && **str <= '9'))
		return (1);
	return (0);
}


int	parse_conv(const char **str, va_list ap, int len_buff, char *buff)
{
	t_flags *f;
	int w_or_prec;

	*f = (t_flags){0, 0, 0, 0, 0, 0, 0, 0};
	//pacourir char by char et remplir la struct en 3 etapes
	//1) -,0, ' ', #
	if (**(str + 1) && **(str + 1) == '%')
		buff[len_buff++] = '%'; //check si ca marche ca... pas sur
	len_buff = flush_buff(buff, len_buff);
	w_or_prec = flag_parse(str, f);
	//w_or_prec = bonus_parse(str, f); // a changer
	//2) width, precision, *
	//if (w_or_prec)
	//	padd_parse(&str, f);
}

//3) specifier type or 2+3 depending on size
//fonction qui conv en fonction de t_flags *f et specifier, et len_buff
//qui return le nombre de char final -> char_count+= conv_function
//GERER LEN_BUFF pour flush;
return (len_buff);
}
