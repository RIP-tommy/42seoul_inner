/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 22:45:56 by sungmcho          #+#    #+#             */
/*   Updated: 2022/01/18 22:46:44 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/server.h"

t_msg_data	g_data;

void	f(int signum, siginfo_t *info, void *context)
{
	if (info == 0)
		exit(EXIT_FAILURE);
	if (context == 0)
		exit(EXIT_FAILURE);
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
		write(1, "\n", 1);
		exit(EXIT_SUCCESS);
	}
	if (g_data.cnt == 8)
	{
		g_data.cnt = 0;
		write(1, &g_data.c, 1);
		g_data.c = 0;
	}
}

int	main(void)
{
	struct sigaction	act;

	ft_printf("%d\n", getpid());
	act.sa_sigaction = f;
	act.sa_flags = SA_SIGINFO;
	g_data.c = 0;
	g_data.cnt = 0;
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
