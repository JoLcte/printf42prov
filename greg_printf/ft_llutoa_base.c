/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llutoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiquiau <ggiquiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 16:08:20 by ggiquiau          #+#    #+#             */
/*   Updated: 2021/01/15 14:36:58 by ggiquiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_llubtoa(unsigned long long c, char *base, size_t base_len, char *res)
{
	if (c < base_len)
	{
		*res = base[c];
		return ;
	}
	ft_llubtoa(c / base_len, base, base_len, res - 1);
	*res = base[c % base_len];
}

void	ft_llutoa_base(char **res, unsigned long long nbr, char *base_to)
{
	size_t		res_size;
	size_t		len_base_to;

	len_base_to = ft_strlen(base_to);
	res_size = num_len_llu(nbr, len_base_to);
	ft_llubtoa(nbr, base_to, len_base_to, *res + res_size - 1);
	(*res) += res_size;
}
