/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:04:30 by sungmcho          #+#    #+#             */
/*   Updated: 2021/12/02 15:17:47 by sungmcho         ###   ########.fr       */
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
	int fd[2];
	int pid;

	pipes = 0;
	char *temp = env[0];
	printf("%s\n", temp);
	if (pipe(fd) < 0)
		return 1;
	if (argc < 5)
		handle_error();
	while (argc < 3)
	{
		pid = fork();
	}
	return (0);
}
