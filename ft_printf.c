/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JoLecomte <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 16:56:04 by JoLecomte         #+#    #+#             */
/*   Updated: 2021/01/25 17:08:04 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <unistd.h>
#include "libftprintf.h"

/*
 ** DRAFT VERSION
 */

//MAIN FUNCTION

int	start_parse(const char **str, char *buff)
{
	int len_buff;

	len_buff = 0;
	while (**str && **str != '%' && len_buff < BUFSIZ)
		buff[len_buff++] = *(*str)++;
	buff[len_buff] = 0;
	if (len_buff == BUFSIZ)
	{
		write(1, buff, len_buff);
		*buff = 0;
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
			len_buff = start_parse(&str, buff);
			char_count += len_buff;
		}
		if (*str == '%') // plus tard : essayer d'effacer cette cond sans segfault
			char_count += parse_conv(&str, ap, len_buff, buff);
	}
	if (*buff)
		write(1, buff, len_buff);
	write(1, "\n", 1);
	va_end(ap);
	return (char_count);
}
