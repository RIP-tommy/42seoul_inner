#include "../inc/client.h"

static void	send_zero(int pid)
{
	if (kill(pid, SIGUSR2) == -1)
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

static void	send_one(int pid)
{
	if (kill(pid, SIGUSR1) == -1)
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

static void	bit_converter(int pid, char c)
{
	int	res[8];
	int	i;

	ft_memset(res, 0, sizeof(int) * 8);
	i = 0;
	while (i != 8)
	{
		res[i] = c % 2;
		c /= 2;
		i += 1;
	}
	while (--i > -1)
	{
		if (!res[i])
			send_zero(pid);
		else
			send_one(pid);
		usleep(1000);
	}
}

void	send_msg(int pid, char *s)
{
	int	i;

	i = 8;
	while (*s)
	{
		bit_converter(pid, *s);
		s += 1;
	}
	while (i--)
	{
		send_zero(pid);
		usleep(1000);
	}
}

int	main(int ac, char **av)
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
	send_msg(ft_atoi(av[1]), av[2]);
	return (EXIT_SUCCESS);
}
