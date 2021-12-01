/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:04:30 by sungmcho          #+#    #+#             */
/*   Updated: 2021/12/01 16:21:00 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void handle_error(void)
{
	exit(1);
}

int		main(int argc, char *argv[], char *env[])
{
	int pipes;

	pipes = 0;
	char *temp = env[0];
	printf("%s\n", temp);
	printf("%d\n", argc);
	if (argc < 5)
		handle_error();
	while (*argv)
	{
		printf("%s\n", *argv);
		argv++;
	}
	return (0);
}
