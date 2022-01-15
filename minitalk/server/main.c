#include "../inc/server.h"

void	f(int signum, int *bit, int *cnt)
{
	char	c;
	int		sign;

	if (*cnt % 8 != 0)
	{
		c = *bit;
		c = c * 2;
		cnt += 1;
	}
	else
	{
		ft_printf("%c",c);
		c = 0;
		c = c * 2;
		cnt += 1;
	}
}

void	g(int signum)
{
	exit(SIGUSR2);
}

int	main(void)
{
	char	c;

	ft_printf("%d\n", getpid());
	c = 0;
	while (1)
	{
		if (signal(SIGUSR1, f) == SIG_ERR)
		{
			ft_printf("can't catch SIGUSR1\n");
			exit(EXIT_FAILURE);
		}
		if (signal(SIGUSR2, g) == SIG_ERR)
		{
			ft_printf("cant't catch SIGUSR2\n");
			exit(EXIT_FAILURE);
		}
	}
	return (0);
}
