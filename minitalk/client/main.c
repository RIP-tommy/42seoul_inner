#include "../inc/client.h"
#include <signal.h>

int	main(int ac, char **av)
{
	pid_t	pid;
	// pid_t	pid;
	char	ch;
	void	f(int);
	void	g(int);
	int		i;
	// int		i;

	if (signal(SIGUSR1, f) == SIG_ERR)
		ft_printf("can't catch SIGUSR1\n");
		ft_printf("can't catch SIGUSR1\n");
	if (signal(SIGUSR2, g) == SIG_ERR)
		ft_printf("cant't catch SIGUSR2\n");
	while (1)
		sleep(1);
	// while (read(STDIN_FILENO, &ch, 1) > 0)
	// {
	// 	ft_printf("%c", ch);
	// }
	while (read(STDIN_FILENO, &ch, 1) > 0)
	{
		ft_printf("%c", ch);
	}
	return (0);
}

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
