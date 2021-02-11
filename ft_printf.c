/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 16:17:53 by jlecomte          #+#    #+#             */
/*   Updated: 2021/02/11 17:00:36 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	buf_pilot(char *buf, const char *s, size_t len, size_t len_buf)
{
	size_t	rest_len;

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
	char		buf[BUFSIZ];
	int			char_count;
	const char	*s;
	size_t		len_buf;
	va_list		ap;

	char_count = 0;
	len_buf = 0;
	s = str;
	if (!str && !*str)
	{
		write(1, "(null)", 6);
		return (0);
	}
	va_start(ap, str);
	while (*str)
	{
		// till '%'
		s = char_chr(str);
		char_count = s - str;
		len_buf = buf_pilot(buf, str, char_count, len_buf);

		//from '%' : conv
		if (*s) // comme ca si *s = 0 on ne rentre pas dedans
			char_count += parse_conv(&s, ap, len_buf, buf);
		str = s;
	}
	if (*buf)
		write(1, buf, len_buf);
	va_end(ap);
	return (char_count);
}
