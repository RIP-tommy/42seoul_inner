/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 22:45:51 by sungmcho          #+#    #+#             */
/*   Updated: 2022/02/03 17:57:25 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/client.h"

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		ft_printf("Check your inputs.\nex)./client pid \"message to send\"\n");
		exit(EXIT_FAILURE);
	}
	else
		send_msg(ft_atoi(av[1]), av[2]);
	return (EXIT_SUCCESS);
}
