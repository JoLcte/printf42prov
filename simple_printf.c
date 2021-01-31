#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#define BUFFER_SIZE 1024

typedef struct s_conv
{
	int width;
	int prec;
	char conv;
	char *base;
}		t_conv;

size_t ft_strlen(char *str)
{
	size_t i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

int ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int is_conv(char c)
{
	return (c == 's' || c =='d' || c == 'x');
}

void	buf_write(char *buf, char c, int *buf_len)
{
	if (*buf_len == BUFFER_SIZE)
	{
		write (1, buf, BUFFER_SIZE);
		*buf_len = 0;
	}
	buf[*buf_len] = c;
	(*buf_len)++;
}

void	buf_write_str(char *buf, const char *str,int n, int *buf_len)
{
	while (n-- && *str)
		buf_write(buf, *str++, buf_len);
}

void	fill_char(char *buf, char c, int len, int *buf_len)
{
	while (len-- > 0)
		buf_write(buf, c, buf_len);
}

int min(int a, int b)
{
	return a < b ? a :b;
}

int max(int a, int b)
{
	return a > b ? a :b;
}

int ft_atoi(const char **str)
{
	int x = 0;
	while (ft_isdigit(*(*str)))
	{
		x = x * 10 + *(*str) - '0';
		(*str)++;
	}
	return x;
}

t_conv init_conv(const char *str, char conv)
{
	t_conv c;
	c.width = 0;
	c.prec = -1;
	c.conv = conv;
	c.width = ft_atoi(&str);
	if (*str++ == '.')
		c.prec = ft_atoi(&str);
	if (c.conv == 'x')
		c.base = "0123456789abcdef";
	else
		c.base = "0123456789";
	return (c);
}

int num_len(unsigned long long l, int base_len)
{
	int len = 0;
	if (l==0)
		len++;
	while (l)
	{
		len ++;
		l = l/base_len;
	}
	return len;
}

void 	ltoa_base(char *buf, unsigned long long l, char *base, int base_len, int *buf_len)
{
	if (l < (unsigned int)base_len)
	{
		buf_write(buf, base[l], buf_len);
		return ;
	}
	ltoa_base(buf, l/base_len, base,base_len,buf_len);
	buf_write(buf, base[l % base_len], buf_len);
}

int format(char *buf, t_conv c, int *buf_len, va_list ap)
{
	char *s;
	int len;
	int neg = 0;
	long long l;
	len = 0;
	if (c.conv == 's')
	{
		s = va_arg(ap, char*);
		if (!s)
			s = "(null)";
		len = ft_strlen(s);
		if (c.prec == -1)
			c.prec = len;
		len = min (len , c.prec);

		fill_char(buf, ' ', c.width - len, buf_len);
		buf_write_str(buf, (const char*)s, len, buf_len);
		len = max(c.width, len);
		return len;
	}
	else if (c.conv == 'd')
		l = va_arg(ap, int);
	else if (c.conv == 'x')
		l = va_arg(ap, unsigned int);
	if (l < 0)
	{
		neg = 1;
		l = -l;
	}
	len = num_len(l, c.conv == 'x'? 16:10) + neg;
	if (c.prec == 0 && l==0)
		len = 0;
	fill_char(buf, ' ', c.width - max(len,c.prec),buf_len);
	if (neg)
		buf_write(buf, '-', buf_len);
	fill_char(buf,'0', c.prec - len, buf_len);
	len = max (len, c.prec);
	if (!(c.prec == 0 && l==0))
		ltoa_base(buf, l, c.base, c.conv == 'x'? 16:10,buf_len);
	len = max(len,c.width);
	return len;
}

int ft_printf(const char *str, ...)
{
	va_list ap;
	int buf_len = 0;
	int final_len = 0;
	int i = 0, j = 0;
	char buf[BUFFER_SIZE];
	va_start(ap, str);

	while (str[i])
	{
		if (str[i] == '%')
		{
			j = ++i;
			while (str[i] && !is_conv(str[i]))
				i++;
			if (is_conv(str[i]))
				final_len += format(buf, init_conv(str + j, str[i]), &buf_len, ap);
			else
			{
				final_len += i - j + 1;
				buf_write_str(buf, str,final_len, &buf_len);
			}
		}
		else
		{
			buf_write(buf, str[i], &buf_len);
			final_len++;
		}
		i++;
	}


	write(1, buf, buf_len);
	va_end(ap);
	return (final_len);
}
