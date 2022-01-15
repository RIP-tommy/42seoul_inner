#include "../inc/client.h"

static void	error_checker(int ac)
{
	if (ac < 3)
	{
		if (ac < 2)
		{
			ft_printf("Need a server pid.\n");
			exit(EXIT_FAILURE);
		}
		else
		{
			ft_printf("Need a string to send.\n");
			exit(EXIT_FAILURE);
		}
	}
	if (ac > 3)
	{
		ft_printf("Too many arguments.\n");
		exit(EXIT_FAILURE);
	}
}

void	kill_server(char *s)
{
	if (kill(ft_atoi(s), SIGUSR2) == -1)
	{
		if (errno == EPERM)
			ft_printf("Process exists, but we don't have "
				"permission to send it a signal\n");
		else if (errno == ESRCH)
			ft_printf("Process does not exist\n");
		else
			ft_printf("kill");
		exit(EXIT_FAILURE);
	}
}

void	send_msg(char *s)
{
	if (kill(ft_atoi(s), SIGUSR1) == -1)
	{
		if (errno == EPERM)
			ft_printf("Process exists, but we don't have "
				"permission to send it a signal\n");
		else if (errno == ESRCH)
			ft_printf("Process does not exist\n");
		else
			ft_printf("kill");
		exit(EXIT_FAILURE);
		kill_server(s);
	}
}

int	main(int ac, char **av)
{
	char	*s;
	char	i;
	int		len;

	error_checker(ac);
	len = ft_strlen(av[2]);
	s = av[2];
	while (len)
	{
		i = *s;
		while (i)
		{
			ft_printf("%d\n", i);
			send_msg(av[1]);
			i -= 1;
		}
		len -= 1;
	}
	kill_server(av[1]);
	return (EXIT_SUCCESS);
}
