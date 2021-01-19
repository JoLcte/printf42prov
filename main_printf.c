#include <stdlib.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	int res;
	if (ac == 2)
	{
		//ft_printf("Your printf : |%|\n");
		res = printf("%s", av[1]);
		printf("%d\n", res);
	}
	printf("%d\n", res);
	return (0);
}
