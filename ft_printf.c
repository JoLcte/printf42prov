/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JoLecomte <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 16:56:04 by JoLecomte         #+#    #+#             */
/*   Updated: 2021/01/31 23:08:30 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <unistd.h>
#include "libftprintf.h"

/*
 ** DRAFT VERSION
 */


void ft_cpy(char *dst, char *src, size_t len)
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
	int len_buff;
	va_list ap;

	char_count = 0;
	if (!str && !*str)
		return (0);
	va_start(ap, str);
	while (*str)
	{
		if (*str != '%')
		{
			len_buff = mainstream_parse(&str, buff);
			char_count += len_buff;
		}
		if (*str == '%') // plus tard : essayer d'effacer cette cond sans segfault
			char_count += parse_conv(&str, ap, len_buff, buff);
	}
	if (*buff)
		write(1, buff, len_buff);
	va_end(ap);
	return (char_count);
}
