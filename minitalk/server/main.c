#include "../inc/server.h"

void f(int signum)
{
	ft_printf("Recieved a frog!\n");
	ft_printf("%d, Recieved a frog!\n", signum);
}

void g(int signum)
{
	ft_printf("Recieved a giraffe!\n");
	ft_printf("%d, Recieved a giraffe!\n", signum);
	exit(SIGUSR2);
}

int	main(void)
{
	char	*s1;

	ft_printf("%d\n", getpid());

	if (signal(SIGUSR1, f) == SIG_ERR)
		ft_printf("can't catch SIGUSR1\n");
	if (signal(SIGUSR2, g) == SIG_ERR)
		ft_printf("cant't catch SIGUSR2\n");
	while(1) ;
	return (0);
}
