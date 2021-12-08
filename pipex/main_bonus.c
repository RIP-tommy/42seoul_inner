/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:04:30 by sungmcho          #+#    #+#             */
/*   Updated: 2021/12/03 11:35:38 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static char	*find_path(char *cmd, char *env[])
{
	char	*res;
	int		i;
	char	**path_env;

	i = 0;
	while (env[i])
		if (ft_strncmp(env[i++], "PATH=", 5) == 0)
			break ;
	path_env = ft_split(ft_split(env[--i], '=')[1], ':');
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

static void	child_process(int *read_fd, int *write_fd, char **arg, char *env[])
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
	execve(find_path(cmd[0], env), cmd, NULL);
}

static void	parent_process(int *read_fd, int *write_fd, char **arg, char *env[])
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
	execve(find_path(cmd[0], env), ft_split(arg[3], ' '), NULL);
}

int	main(int argc, char *argv[], char *env[])
{
	int	fd[2];
	int	pid;
	int	wpid;
	int	i;
	int	status;

	i = 2;
	if (pipe(fd) < 0)
		return (1);
	if (argc < 5)
		handle_error();
	while (argc > 2)
	{
		pid = fork();
		if (pid == -1)
			handle_error();
		// if (pid == 0)
		// 	child_process(&fd[0], &fd[1], argv, env);
		// else
		// {
		// 	waitpid(0, &status, 0);
		// 	parent_process(&fd[0], &fd[1], argv, env);
		// }
		printf("get pid: %d, %d\n", getpid(), getppid());
		printf("pid : %d\n", pid);
		if (pid && WIFEXITED(status))
			wpid = WEXITSTATUS(status);
		else
			wpid = -1;
		i++;
		argc--;
	}
	return (wpid);
}
