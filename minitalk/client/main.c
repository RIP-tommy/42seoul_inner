#include "../inc/client.h"
#include <signal.h>

int	main(int ac, char **av)
{
	pid_t	pid;

	if (ac < 2)
	{
		ft_printf("Need server pid.");
		exit(EXIT_FAILURE);
	}
	else
		kill(ft_atoi(av[1]), SIGUSR1);
	
	return (0);
}
