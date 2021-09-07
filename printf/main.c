#include <stdio.h>
#include "ft_printf.h"


int main(int ac, char **av)
{
	char *c = "Hello World!";
	char *nu = 0;

	ft_printf("%x\n", 3* 16 * 16 + 16);
	printf("%x\n", 3* 16 * 16 + 16);

	if (ac > 1)
	{
		ft_printf("%d\n", ac);
		printf("%d\n", ac);
		ft_printf("%s\n", av[1]);
		printf("%s\n", av[1]);
		ft_printf("%p\n", nu);
		printf("%p\n", nu);
		ft_printf("%p\n", 1);
		printf("%p\n", 1);
		ft_printf("%p\n", c);
		printf("%p\n", c);
		ft_printf("%p\n", av[1]);
		printf("%p\n", av[1]);
	}
	else
	{
		ft_printf("%d\n", ac);
		printf("%d\n", ac);
		ft_printf("%s\n", av[0]);
		printf("%s\n", av[0]);
		ft_printf("%p\n", nu);
		printf("%p\n", nu);
		ft_printf("%p\n", c);
		printf("%p\n", c);
		ft_printf("%p\n", av[0]);
		printf("%p\n", av[0]);
	}
	return 0;
}
