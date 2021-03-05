/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 16:17:53 by jlecomte          #+#    #+#             */
/*   Updated: 2021/03/05 21:33:33 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	empty_static(const char *buf, int *len_buf)
{
	const int save = *len_buf;

	*len_buf = 0;
	if (!buf)
		return (0);
	return (save);
}

int			buf_pilot(char *buf, const char *s, int len, int empty)
{
	static int	len_buf;
	int			rest_len;

	rest_len = BUFSIZ - len_buf;
	while (len > rest_len)
	{
		len -= rest_len;
		ft_cpy(buf + len_buf, s, rest_len);
		s += rest_len;
		write(1, buf, BUFSIZ);
		len_buf = 0;
		rest_len = BUFSIZ;
	}
	if (len)
		ft_cpy(buf + len_buf, s, len);
	len_buf += len;
	if (empty)
		return (empty_static(buf, &len_buf));
	return (len_buf);
}

int			ft_printf(const char *str, ...)
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
		buf_pilot(buf, str, s - str, 0);
		if (*s)
		{
			++s;
			if (*s)
				char_count += parse_conv(&s, ap, buf, char_count);
		}
		str = s;
	}
	write(1, buf, buf_pilot(buf, "", 0, 1));
	va_end(ap);
	return (char_count);
}
