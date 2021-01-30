#include <stdlib.h>
#include <stdio.h>

int	ft_printf(const char *str, ...);

int	main(/*int ac, char **av*/void)
{
	int res;
	int rel;
	/*if (ac == 3)
	{*/
		rel = ft_printf("Your : |%.250f|\n", 0.3);
		res = printf("Real : |%.250f|\n", 0.3;
	//}
	printf("real : %d\n", res);
	printf("your : %d\n", rel);
	return (0);
}
