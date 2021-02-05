/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 16:17:53 by jlecomte          #+#    #+#             */
/*   Updated: 2021/02/05 14:59:47 by jlecomte         ###   ########.fr       */
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

int	buf_pilot(char *buf, char *s, int len, size_t len_buf)
{
	size_t rest_len = BUFSIZ - len_buf;
	while (len > rest_len)
	{
		ft_cpy(buf + len_buf, s, rest_len);
		write(1, buf, BUFSIZ);
		*buf = 0;
		len_buf = 0;
		len -= rest_len;
		rest_len = BUFSIZ;
	}
	if (len)
		ft_cpy(buf + len_buf, s, len);
	len_buf += len;
}
return (len_buf);
}

int	ft_printf(const char *str, ...)
{
	char buf[BUFSIZ];
	int char_count;
	char *s;
	size_t len_buf;
	va_list ap;

	char_count = 0;
	len_buf = 0;
	s = /*(char)*/str;
	if (!str && !*str)
	{
		write(1, "(null)", 6); 
		return (0);
	}
	va_start(ap, str);
	while (*str)
	{
		s = char_chr(str);
		char_count = s - str;
		len_buf = buf_pilot(buf, str, char_count, len_buf);
		//dans le cas ou *s = 0 ->;
		if (*s)
		//if faut qu'on reboucle a partir de str qui sera egal a apres le type de conv ou apres le % si echec
		{
			char_count += parse_conv(&s, ap, len_buf, buf);
		}
		str = s;
	}
	if (*buf)
		write(1, buf, len_buf);
	va_end(ap);
	return (char_count);
}
