/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 16:17:53 by jlecomte          #+#    #+#             */
/*   Updated: 2021/02/20 10:06:21 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "libftprintf.h"

size_t	buf_pilot(char *buf, const char *s, size_t len)
{
	static size_t	len_buf;
	size_t			rest_len;

	rest_len = BUFSIZ - len_buf;
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
	return (len_buf);
}

int		ft_printf(const char *str, ...)
{
	char		buf[BUFSIZ + 1];
	int			char_count;
	const char	*s;
	va_list		ap;

	char_count = 0;
	s = str;
	va_start(ap, str);
	while (*str)
	{
		s = char_chr(str);
		char_count += s - str;
		buf_pilot(buf, str, s - str);
		if (*s)
		{
			s++;
			char_count += parse_conv(&s, ap, buf);
		}
		str = s;
	}
	if (*buf)
		write(1, buf, buf_pilot(buf, "", 0));
	va_end(ap);
	return (char_count);
}
