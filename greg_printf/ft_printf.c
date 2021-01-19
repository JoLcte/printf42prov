/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiquiau <ggiquiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 11:54:05 by ggiquiau          #+#    #+#             */
/*   Updated: 2021/01/15 14:25:16 by ggiquiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	final_size(const char *s, int *len, va_list ap)
{
	int i;
	int j;
	int k;

	i = 0;
	while (s[i])
	{
		if (s[i++] == '%')
		{
			j = i;
			while (s[i] && !is_conv(s[i]))
				i++;
			if (s[i] && is_conv(s[i]))
				k = format_len(init_conv((char*)s + j, i++ - j, ap), ap);
			else
				k = i - j + 1;
		}
		else
			k = 1;
		if (k == -1)
			break ;
		else
			(*len) += k;
	}
}

static int	fill_res(const char *str, char *res, va_list ap)
{
	int i;
	int j;

	i = -1;
	while (str[++i])
		if (str[i] == '%')
		{
			j = ++i;
			while (str[i] && !is_conv(str[i]))
				i++;
			if (str[i] && is_conv(str[i]))
			{
				if (!format(init_conv((char*)str + j, i - j, ap), &res, ap))
					return (0);
			}
			else
			{
				ft_strcat((char*)str + j - 1, &res, ft_strlen(str));
				break ;
			}
		}
		else
			*res++ = str[i];
	return (1);
}

int			ft_printf(const char *str, ...)
{
	va_list	ap;
	va_list	ap2;
	int		len;
	char	*res;
	int		err;

	len = 0;
	if (!str)
		return (-1);
	va_start(ap, str);
	va_copy(ap2, ap);
	final_size(str, &len, ap2);
	res = (char*)malloc(len + 1);
	if (!res)
		return (-1);
	res[len] = '\0';
	err = fill_res(str, res, ap);
	va_end(ap);
	write(1, res, len);
	free(res);
	if (!err)
		return (-1);
	return (len);
}
