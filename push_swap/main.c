#include "pushswap.h"

void parser(int ac, char **av, t_pushswap stacks)
{
	stacks.stack_a = (int *)malloc(sizeof(int) * ac);
	stacks.stack_b = (int *)malloc(sizeof(int) * ac);
	
}

int	main(int ac, char **av)
{
	t_pushswap stacks;

	if (ac < 2)
		return (0);
	else
	{
		parser(ac, av, stacks);
		return (0);
	}
}
