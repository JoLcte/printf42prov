#include <stdlib.h>
#include <stdio.h>

int	ft_printf(const char *str, ...);

int	main(int ac, char **av)
{
	int res = 0;
	if (ac == 3)
	{
		res = ft_printf(av[1], av[2]);
	}
	printf("%d\n", res);
	return (0);
}
