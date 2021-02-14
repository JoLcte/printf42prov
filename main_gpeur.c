#include <stdio.h>
#include "libftprintf.h"

int	ft_printf(const char *str, ...);

int	main(int ac, char **av)
{
	int res;
	int yres;

	if (ac == 3)
	{
		printf("\n- this is real:\n");
		res = printf(av[1], av[2]);
		printf("\n- this is test:\n");
		yres = ft_printf(av[1], av[2]);

		printf("\nreal: %d\n", res);
		printf("test: %d\n", yres);
	}
	return (0);
}
