/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 13:38:50 by jlecomte          #+#    #+#             */
/*   Updated: 2021/02/07 16:06:39 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*char_chr(char *s)
{
	char *const save = s;

	while (*s)
	{
		if (*s == '%')
			return (s);
		++s;
	}
	return (s);
}

size_t	ft_strlen(char *s)
{
	const char *const save = s;

	while (*s)
		++s;
	return (s - save);
}

void	ft_cpy(char *dst, char *src, size_t len)
{
	while (len--)
		*dst++ = *src++;
}

int		ft_atoi(const char *s)
{
}
