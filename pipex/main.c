/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:08:08 by sungmcho          #+#    #+#             */
/*   Updated: 2021/11/24 13:08:10 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"
#include <stdio.h>
#include <string.h>

int	main(int ac, char *av[])
{
	int	pid;
	int	err;
	int	fd[2];
	char **new_argv;
	int file;

	new_argv = (char **)malloc(sizeof(char *) * 3);

	pid = fork();
	new_argv[0] = av[2];
	new_argv[1] = av[3];
	if (pipe(fd) == -1)
	{
		perror("pipe");
		exit(1);
	}
	if (pid == -1)
	{
		perror("fork");
		exit(1);
	}
	if (pid == 0)
	{
		close(fd[0]);
		file = open(av[1], O_RDONLY, 0666);
		// dup2(fd[1], STDOUT_FILENO);
		dup2(file, STDIN_FILENO);
		// find_path(av[2]);
		execve("/usr/bin/grep", new_argv, NULL);
	}
	else
	{
		waitpid(pid, NULL, 0);
		close(fd[1]);
		// file = open(av[6], O_WRONLY | O_CREAT, 0666);
		dup2(fd[0], STDIN_FILENO);
		// close(fd[0]);
		// dup2(file, STDOUT_FILENO);
		// close(file);
		new_argv[0] = av[4];
		new_argv[1] = av[5];
		execve("/usr/bin/wc", new_argv, NULL);
	}
	return (0);
}
