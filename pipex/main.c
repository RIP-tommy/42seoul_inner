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

#include "pipex.h"

extern char	**environ;

static char	*find_path(char *cmd)
{
	char	*res;
	int		i;
	char	**path_env;

	i = 0;
	while (environ[i])
		if (ft_strncmp(environ[i++], "PATH=", 5) == 0)
			break ;
	path_env = ft_split(ft_split(environ[--i], '=')[1], ':');
	while (*path_env)
	{
		res = ft_strjoin(*path_env, ft_strjoin("/", cmd));
		if (access(res, X_OK) == 0)
			return (res);
		path_env++;
	}
	return (res);
}

static void	handle_error(void)
{
	exit(1);
}

static void	child_process(int *read_fd, int *write_fd, char **arg)
{
	int		file;
	char	**cmd;

	cmd = ft_split(arg[2], ' ');
	file = open(arg[1], O_RDONLY, 0444);
	close(*read_fd);
	if (file == -1)
		handle_error();
	dup2(*write_fd, STDOUT_FILENO);
	dup2(file, STDIN_FILENO);
	close(*write_fd);
	close(file);
	execve(find_path(cmd[0]), cmd, NULL);
}

static void	parent_process(int *read_fd, int *write_fd, char **arg)
{
	int		file;
	char	**cmd;

	cmd = ft_split(arg[3], ' ');
	file = open(arg[4], O_WRONLY | O_CREAT, 0666);
	close(*write_fd);
	dup2(*read_fd, STDIN_FILENO);
	dup2(file, STDOUT_FILENO);
	close(*read_fd);
	close(file);
	execve(find_path(cmd[0]), ft_split(arg[3], ' '), NULL);
}

int	main(int argc, char *argv[])
{
	pid_t	pid;
	pid_t	wpid;
	int		fd[2];
	int		status;

	if (argc < 5)
		exit(1);
	if (pipe(fd) == -1)
		handle_error();
	pid = fork();
	if (pid == -1)
		handle_error();
	if (pid == 0)
		child_process(&fd[0], &fd[1], argv);
	else
	{
		waitpid(0, &status, 0);
		parent_process(&fd[0], &fd[1], argv);
	}
	if (pid && WIFEXITED(status))
			wpid = WEXITSTATUS(status);
	else
		wpid = -1;
	return (wpid);
}
