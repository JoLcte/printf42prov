/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 13:38:50 by jlecomte          #+#    #+#             */
/*   Updated: 2021/03/05 22:09:33 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int			ft_strlen(char *s)
{
	const char *const save = s;

	while (*s)
		++s;
	return (s - save);
}

void		ft_cpy(char *dst, const char *src, int len)
{
	while (len--)
		*dst++ = *src++;
}

int			ft_atoi(const char **str)
{
	const char	*s = *str;
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
	return (res * neg);
}

int			max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
