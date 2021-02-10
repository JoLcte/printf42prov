/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_specif.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 16:17:32 by jlecomte          #+#    #+#             */
/*   Updated: 2021/02/10 16:53:40 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	str_conv(va_list ap. size_t len_buf, char *buf, t_flags *f)
{
	char *s_conv;
	int len_s;

	s_conv = va_arg(ap, char *);
	len_s = ft_strlen(s_conv);
	if (f->prec > len_s)
	{
		s_conv[f->prec] = 0;
		len_s = ft_strlen(s_conv);
	}
	f->width -= len_s;
	if (f->width > 0)
	{
		if (f->fleft)
		{
			len_buf = buf_pilot(buf, s_conv, len_s, len_buf);
			len_buf = buf_pilot(buf, some_magic("    ", f->width, len_buf);
		}
		else
		{
		len_buf = buf_pilot(buf, some_magic("    ", f->width, len_buf);
				len_buf = buf_pilot(buf, s_conv, len_s, len_buf);
		}
		return (len_s + f->width); // CAS AVEC LEN_S > WIDTH ? Marche pas
// PB : LEN_BUF NE VA PAS ETRE RETURNED
	}

	// creer un char * qui serait modifie avec str;
//appel a buf_pilot
// return len_final
}

int ptr_conv(void *p, va_list ap, size_t len_buf, char *buf, t_flags *f)
{
//ajouter 0x ?
// faire des tests sur un char * par exemple
// ou un *int
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
