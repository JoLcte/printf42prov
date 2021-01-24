(/* ************************************************************************** */
 /*                                                                            */
 /*                                                        :::      ::::::::   */
/*   parse_conv.c                                       :+:      :+:    :+:   */
 /*                                                    +:+ +:+         +:+     */
 /*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
 /*                                                +#+#+#+#+#+   +#+           */
 /*   Created: 2021/01/24 15:29:26 by jlecomte          #+#    #+#             */
/*   Updated: 2021/01/24 23:49:49 by jlecomte         ###   ########.fr       */
 /*                                                                            */
 /* ************************************************************************** */

#include <unistd.h>
#include "libftprintf.h"

 int	flag_parse(const char **str, t_flags *f)
 {
  if (**str == '0')
 {
	 f->fzero = 1;
	 *str++;
 }
if (**str == '-')
 {
 while (**str == '-')
 *str++;
 f->fleft = 1;
 }

 if (**str == '#') 
 {
 }
 if (**str == '+')
 {
 }
 }

int	parse_conv(const char **str, va_list ap, int len_buff)
{
	t_flags *f;
	int w_or_prec;

	*flags = {0, 0, 0, 0, 0};
	w_or_prec = flag_parse(&str, f);
	if (w_or_prec)
	padd_parse(&str, f);
	//pacourir char by char et remplir la struct en 3 etapes
	//1) -,0, ' ', #


	//2) width, precision, *


	//3) specifier type or 2+3 depending on size

	//fonction qui conv en fonction de t_flags *f et specifier, et len_buff
	//qui return le nombre de char final -> char_count+= conv_function

}
