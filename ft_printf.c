/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JoLecomte <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 16:56:04 by JoLecomte         #+#    #+#             */
/*   Updated: 2021/01/19 16:18:36 by jlecomte         ###   ########.fr       */
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
	int char_count;

	char_count = 0;
	while (**str && **str != '%' && char_count < BUFSIZ)
		buff[char_count++] = *(*str)++;
	buff[char_count] = 0;
	if (char_count == BUFSIZ)
	{
		write(1, buff, char_count);
		*buff = 0;
	}
	printf("\nstr apres flush |%s|\n", *str);
	return (char_count);
}

int	ft_printf(const char *str, ...)
{
	char buff[BUFSIZ];
	//char tmp;
	int char_count;
	int len_buff;
	va_list ap;

	char_count = 0;
	if (!str && !*str)
		return (0);
	va_start(ap, str);
	while (*str)
	{
		len_buff = start_parse(&str, buff);
		char_count += len_buff;
		if (*str == '%')
			return 0; //char_count += ft_parse(str, ap); //ft_parse qui appelle conv ...
	}
	if (*buff)
		write(1, buff, len_buff);
	write(1, "\n", 1);
	printf("printf apres tout : |%s|\n", str);
	va_end(ap);
	return (char_count);
}
