/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiquiau <ggiquiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 15:59:14 by ggiquiau          #+#    #+#             */
/*   Updated: 2021/01/15 11:54:16 by ggiquiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	num_len_llu(unsigned long long nbr, size_t len_base_to)
{
	size_t len;

	len = 0;
	if (nbr == 0)
		len++;
	while (nbr)
	{
		nbr = nbr / len_base_to;
		len++;
	}
	return (len);
}
