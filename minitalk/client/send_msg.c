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

static void	bit_converter(int pid, unsigned char c)
{
	unsigned int	res[50];
	int				i;

	ft_memset(res, 0, sizeof(unsigned int) * 50);
	i = 0;
	while (c != 0)
	{
		res[i] = c % 2;
		c /= 2;
		i++;
	}
	i = 8;
	while (--i > -1)
	{
		if (!res[i])
			send_zero(pid);
		else
			send_one(pid);
		usleep(125);
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
		usleep(125);
	}
}
