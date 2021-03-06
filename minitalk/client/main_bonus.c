/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 22:45:51 by sungmcho          #+#    #+#             */
/*   Updated: 2022/02/03 17:59:53 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/client_bonus.h"

static void	handler(int signo)
{
	write(1, "ACK\n", 4);
	(void)signo;
	exit(0);
}

int	main(int ac, char **av)
{
	signal(SIGUSR1, handler);
	if (ac != 3)
	{
		ft_printf("Check your inputs.\nex)./client pid \"message to send\"\n");
		exit(EXIT_FAILURE);
	}
	else
		send_msg(ft_atoi(av[1]), av[2]);
	pause();
	return (EXIT_SUCCESS);
}
