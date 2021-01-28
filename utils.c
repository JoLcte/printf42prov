/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 16:20:39 by jlecomte          #+#    #+#             */
/*   Updated: 2021/01/28 16:21:35 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libftprintf.h"

int	flush_buff(char *s, int len_buff)
{
	if (len_buff == BUFSIZ)
	{
		write (1, s, len_buff);
		*buff = 0;
		len_buff = 0;
	}
	return (len_buff);
}

