/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JoLecomte <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 16:56:04 by JoLecomte         #+#    #+#             */
/*   Updated: 2021/02/02 16:27:07 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <unistd.h>
#include "libftprintf.h"

/*
 ** DRAFT VERSION
 */


static void ft_cpy(char *dst, char *src, size_t len)
{
	while (len--)
		*dst++ = *src++;
}

int	buff_pilot(char *buf, char *s, int len, int len_buff)
{
	size_t rest_len = BUFSIZ - len_buff;
	while (len > rest_len)  // <---- revoir ou ....
	{
		ft_cpy(buff + len_buff, s, rest_len);
		write(1, buff, BUFSIZ);
		len_buff = 0;
		len -= rest_len;
		rest_len = BUFSIZ;
	}
	while (len)
		*(buff + len_buff)++ = *s++;
	len_buff += len;
}
return (len_buff);
}

int	ft_printf(const char *str, ...)
{
	char buff[BUFSIZ];
	int char_count;
	char *s;
	int len_buff;
	va_list ap;

	char_count = 0;
	len_buff = 0;
	s = str;
	if (!str && !*str)
		return (0);
	va_start(ap, str);
	while (*str)
	{
		s += index_chr(str, '%');
		char_count = s - str - 1; // check pour le -1 si ca prend le % ou non
		len_buff = buff_pilot(buff, str, char_count, len_buff);

		// parsing a partir du %
		str = s;
		//str++; // a gerer car on veut que char_count += len_conv
		// que char_count ne compte pas le premier "%" s'il y en a deux -> peut etre gerer un +1 dans parse_conv dans ce cas ?
		//  qu'on reboucle a partir de str qui sera egal a apres le type de conv ou apres le % si echec
		//  qu'on enregistre dans s la conversion pour pouvoir la mettre dans le buffer  
		char_count += parse_conv(&s, ap);
		len_buff = buff_pilot(buff, s, ... , len_buff);

		//  2) return len(s)
		//
		//buf_pilot de len(str + char_count)
		if (*str == '%') // plus tard : essayer d'effacer cette cond sans segfault
			char_count += parse_conv(&str, ap, len_buff, buff);
	}
	if (*buff)
		write(1, buff, len_buff);
	va_end(ap);
	return (char_count);
}
