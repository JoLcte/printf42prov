#include "libftprintf.h"

int ft_printf(const char *str, ...);

int main(int ac, char **av)
{
	if (ac == 2)
	{
		return (ft_printf(av[1]));
	}
	return (0);
}
