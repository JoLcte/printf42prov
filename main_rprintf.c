#include <stdio.h>
#include <stdlib.h>


int main(int ac, char **av)
{
	//int a = ;
	int res = 0;

	if (ac == 3)
	{
		//return (printf("|%s|\n", ""));
		res = printf(av[1], av[2]);
	}
	printf("%d\n", res);
	return (0);
}
