/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_specif.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 16:17:32 by jlecomte          #+#    #+#             */
/*   Updated: 2021/02/07 16:00:54 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	str_conv(const char *s, size_t len_buf, char *buf, t_flags *f)
{
	// creer un char * qui serait modifie avec str;
//appel a buf_pilot
// return len_final
}

int ptr_conv(void *p, size_t len_buf, char *buf, t_flags *f)
{

}

int numsign_conv(int num, size_t len_buf, char *buf, t_flags *f)
{

}

int numunsign_conv(unsigned int num, size_t len_buf, char *buf, t_flags *f)
{

}

int	padd_conv(const char **str, va_list ap, int len_buf, char *buf, t_flags *f)
{
	const char *s = *str;

	if (*s == 'c' || *s == 's')
		return (str_conv(va_arg(ap, const char *), len_buf, buf, f));
	else if (*s == 'p')
		return (ptr_conv(va_arg(ap, void *), len_buf, buf, f));
	else if (*s == 'd' || *s == 'i' || *s == 'u')
		return (numsign_conv(va_arg(ap, int), len_buf, buf, f));
	else if (*s == 'o' || *s == 'x' || *s == 'X')
		return (numunsign_conv(va_arg(ap, unsigned int), len_buf, buf, f));
	else
		return (0);
}
