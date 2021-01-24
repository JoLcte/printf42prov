/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 15:29:26 by jlecomte          #+#    #+#             */
/*   Updated: 2021/01/24 16:58:01 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libftprintf.h"

int	flag_parse(const char **str, t flags *f)
{
	if (**str == '-')
		f->fleft = 1;
	
	if 
}

int	parse_conv(const char **str, va_list ap, int *len_buff)
{
	t_flags *f;

	*flags = {0, 0, 0, 0, 0};

	//pacourir char by char et remplir la struct en 3 etapes
	//1) -,0, ' ', #
	
	
	//2) width, precision, *
	
	
	//3) specifier type or 2+3 depending on size
	
//fonction qui conv en fonction de t_flags *f et specifier, et len_buff
//qui return le nombre de char final -> char_count+= conv_function

}
