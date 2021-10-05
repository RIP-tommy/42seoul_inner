/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho@student.42.kr <sungmcho@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 13:51:33 by sungmcho@st       #+#    #+#             */
/*   Updated: 2021/10/05 15:25:04 by sungmcho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf/ft_printf.h"
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int	main()
{
	pid_t	pid;
	char	ch;
	void	f(int);
	void	g(int);
	int		i;

	if (signal(SIGUSR1, f) == SIG_ERR)
		ft_printF("can't catch SIGUSR1\n");
	if (signal(SIGUSR2, g) == SIG_ERR)
		ft_printf("cant't catch SIGUSR2\n");
	while (1)
		sleep(1);
	// while (read(STDIN_FILENO, &ch, 1) > 0)
	// {
	// 	ft_printf("%c", ch);
	// }
	return (0);
}

void f(int singnum)
{
	ft_printf("Recieved a frog!\n");
}

void g(int singnum)
{
	ft_printf("Recieved a giraffe!\n");
	exit(SIGUSR2);
}
