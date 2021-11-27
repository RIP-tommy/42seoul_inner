/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:08:08 by sungmcho          #+#    #+#             */
/*   Updated: 2021/11/27 20:22:13 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

int main(int argc, char *argv[])
{
	pid_t pid;
	pid_t wpid;
	int fd[2];
	int status;
	// char	**new_argv;
	// int	file;

	// new_argv = (char **)malloc(sizeof(char *) * 3);
	pid = fork();
	if (pid == -1)
	{
		// perror("fork");
		exit(1);
	}
	if (pipe(fd) == -1)
	{
		// perror("pipe");
		exit(1);
	}
	if (pid == 0)
	{
		close(fd[0]);
		char buf[200];
		scanf("%s", buf);
		write(fd[1], &buf, 15);
		close(fd[1]);
		// // file = open(argv[1], O_RDONLY, 0666);
		// dup2(fd[1], STDOUT_FILENO);
		// // dup2(file, STDIN_FILENO);
		// new_argv[0] = argv[2];
		// new_argv[1] = argv[3];
		// new_argv[2] = argv[1];
		// // find_path(argv[2]);
		// execve("/usr/bin/grep", new_argv, NULL);
	}
	else
	{
		waitpid(pid, &status, 0);
		close(fd[1]);
		char buf[200];
		read(fd[0], &buf, 15);
		close(fd[0]);
		printf("%s\n", buf);
		// file = open(argv[6], O_WRONLY | O_CREAT, 0666);
		// dup2(fd[0], STDIN_FILENO);
		// // dup2(file, STDOUT_FILENO);
		// new_argv[0] = argv[4];
		// new_argv[1] = argv[5];
		// execve("/usr/bin/wc", new_argv, NULL);
	}
	return (wpid == pid && WIFEXITED(status) ? WEXITSTATUS(status) : -1);
}
