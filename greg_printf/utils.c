/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiquiau <ggiquiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 17:17:36 by ggiquiau          #+#    #+#             */
/*   Updated: 2021/01/12 11:09:55 by ggiquiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			get_index(char *s, char c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

void		ft_strcat(char *str, char **res, int n)
{
	while (n-- && *str)
		*(*res)++ = *str++;
}

void		fill_char2(char c, char **res, int len)
{
	while (len-- > 0)
		*(*res)++ = c;
}

char		*str_base(char conv)
{
	if (conv == 'X')
		return (BASE16_U);
	if (conv == 'x' || conv == 'p')
		return (BASE16_L);
	return (BASE10);
}
