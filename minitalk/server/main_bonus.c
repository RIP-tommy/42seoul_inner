/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 22:45:56 by sungmcho          #+#    #+#             */
/*   Updated: 2022/02/03 19:32:41 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/server_bonus.h"

t_msg_data	g_data;

static void	printer(int signum)
{
	if (signum == SIGUSR1)
	{
		g_data.c = g_data.c * 2 + 1;
		g_data.cnt += 1;
	}
	else if (signum == SIGUSR2)
	{
		g_data.c = g_data.c * 2;
		g_data.cnt += 1;
	}
	if (g_data.cnt == 8 && g_data.c == 0)
	{
		g_data.cnt = 0;
		write(1, "\n", 1);
		if (kill(g_data.pid, SIGUSR1) == -1)
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
		usleep(80);
		g_data.pid = 0;
	}
	if (g_data.cnt == 8)
	{
		g_data.cnt = 0;
		write(1, &g_data.c, 1);
		g_data.c = 0;
	}
}

void	f(int signum, siginfo_t *info, void *context)
{
	if (g_data.pid == 0)
		g_data.pid = info->si_pid;
	if (info == 0)
		exit(EXIT_FAILURE);
	if (context == 0)
		exit(EXIT_FAILURE);
	printer(signum);
}

int	main(void)
{
	struct sigaction	act;

	ft_printf("%d\n", getpid());
	act.sa_sigaction = f;
	act.sa_flags = SA_SIGINFO;
	g_data.c = 0;
	g_data.cnt = 0;
	g_data.pid = 0;
	if (sigaction(SIGUSR1, &act, NULL) != 0)
	{
		ft_printf("can't catch SIGUSR1\n");
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, &act, NULL) != 0)
	{
		ft_printf("cant't catch SIGUSR2\n");
		exit(EXIT_FAILURE);
	}
	while (1)
		;
	return (0);
}
