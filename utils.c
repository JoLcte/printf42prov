/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 16:20:39 by jlecomte          #+#    #+#             */
/*   Updated: 2021/02/03 15:06:13 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libftprintf.h"

char *char_chr(char *s)
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

size_t ft_strlen(char *s)
{
	const char * const save = s;
	while (*s)
		++s;
	return (s - save);
}
