/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 13:38:50 by jlecomte          #+#    #+#             */
/*   Updated: 2021/02/14 15:17:23 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

#include "libftprintf.h"

const char	*char_chr(const char *s)
{
	while (*s)
	{
		if (*s == '%')
			return (s);
		++s;
	}
	return (s);
}

size_t		ft_strlen(char *s)
{
	const char *const save = s;

	while (*s)
		++s;
	return (s - save);
}

void		ft_cpy(char *dst, const char *src, size_t len)
{
	while (len--)
		*dst++ = *src++;
}

int		ft_atoi(const char **str)
{
	const char *s = *str;

	long int	res;
	int			neg;

	res = 0;
	neg = 1;
	while (*s == 32 || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			neg *= -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
		res = res * 10 + *s++ - '0';
	*str = s;
	return ((int)(res * neg));
}
