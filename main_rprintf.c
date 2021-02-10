#include <stdio.h>
#include <stdlib.h>


int main(/*int ac, char **av*/)
{
	//int a = ;
	int res = 0;

	/*if (ac == 4)
	{*/
		res = printf("|%-7.12s|", "coucou bonjour salut");
	//	res = printf(av[1], atoi(av[2]), atoi(av[3]));
	//}
	printf("\n%d\n", res);
	return (0);
}
