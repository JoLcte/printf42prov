/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudot <abaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 12:49:30 by abaudot           #+#    #+#             */
/*   Updated: 2021/02/03 16:05:31 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

#define MIN(a,b) a > b ? b : a

/*
**	Utilis Fonctions - simple
*/ 

static const char		*ft_strshr(const char *s)
{
	while (*s)
	{
		if (*s == '%')
			return (s);
		++s;
	}
	return (s);
}

static int		ft_write(const char *s, size_t n)
{
	write (1, s, n);
	return (n);
}

static int 	ft_strlen(const char *s)
{
	const char * const save = s;
	
	while (*s)
		++s;
	return (s - save);
}

static char is_num(unsigned c)
{
	return (c - '0' < 10);
}

static void write_width(int n)
{
	while (n > 0)
	{
		write(1, "          ", n > 10 ? 10 : n);
		n -= 10;
	}
}

static void write_preciz(int n)
{
	while (n > 0)
	{
		write(1, "0000000000", n > 10 ? 10 : n);
		n -= 10;
	}
}

/*
**	atoi for width and preciz handel
*/

static int	ft_atoi(const char **s)
{
	int				res = 0;
	unsigned char	c;

	while (1)
	{
		if ((c = **s - '0') > 9)
			return (res);
		else
			res = (res << 1) + (res << 3) + c;
		++*s;
	}
	return (res);
}

/*
**	Convertions function ---->
*/

static int print_string(const char *s, int width, int preciz)
{
	if (!s)
		return (ft_write("(null)", 6));

	int 		len = ft_strlen(s);
	int 		ans = len;
	if (preciz > 0)
		len = MIN(preciz, len);
	width -= len;
	if (width > 0)
	{
		ans += width;
		write_width(width);
	}
	write(1, s, len);
	return (ans);
}

static int print_num(long int n, int width, int preciz, int base)
{
	char		tmp[21];
	const char	*hex	= "0123456789abcdef";
	const char	signe 	= (n < 0);
	int			ans		= 0;
	int 		i		= 21;
	int			len 	= 0;
	
	if (signe)
		n = -n;
	if (!n)
		tmp[--i] = '0';
	while (n)
	{
		tmp[--i] = hex[n % base];
		n /= base;
	}
	len = 21 - i;
	width -= (len + signe);
	preciz -= len;
	if (preciz > 0)
	{
		width -= preciz;
		ans += preciz;
	}
	if (width  > 0)
	{
		ans += width;
		write_width(width);
	}
	ans += ft_write("-", signe);
	write_preciz(preciz);
	return (ans + ft_write(tmp + i, len));
}
		
/*
**	Parser %s, %d, %x
*/

static int		parse(const char **s, va_list av)
{
	int preciz = -1;
	int width  = 0;
	
	if (is_num(**s))
		width = ft_atoi(s);
	if (**s == '.')
	{
		++*s;
		preciz = ft_atoi(s);
	}
	if (**s == 's')
		return (print_string(va_arg(av, const char *), width, preciz));
	if (**s == 'd')
		return (print_num((long int)va_arg(av, int), width, preciz, 10));
	if (**s == 'x')
		return (print_num((long int )va_arg(av, unsigned int), width, preciz, 16));
	return (ft_write("%", 1));
}

/*
**	Printf function
*/

int		ft_printf(const char *format, ...)
{
	const char	*str 	= NULL;
	int			ans 	= 0;
	va_list		av;

	va_start(av, format);
	while (*(str = ft_strshr(format)))
	{
		ans += ft_write(format, str - format);
		format = str + 1;
		ans += parse(&format, av);
		++format;
	}
	ans += ft_write(format, str - format);
	return (ans);
}
