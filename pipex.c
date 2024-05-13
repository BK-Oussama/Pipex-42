/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:21:50 by ouboukou          #+#    #+#             */
/*   Updated: 2024/05/13 23:38:19 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	check_cmd_access(char *paths[], char *argv)
{
	int		i;
	char	*c;
	char	**cmd_args;

	cmd_args = ft_split(argv, ' ');
	if (!cmd_args)
		ft_putstr_fd("Pipex: ft_split failed", 2);
	i = 0;
	while (paths[i])
	{
		c = ft_strjoin(paths[i], "/");
		c = ft_strjoin(c, cmd_args[0]);
		if (access(c, F_OK | X_OK) == 0)
			execve(c, cmd_args, NULL);
		i++;
	}
	(perror(""), exit(127));
}

static void	retrive_paths(char **env, char *argv)
{
	int		i;
	char	*c;
	char	**paths;

	c = NULL;
	while (env && *env)
	{
		if (ft_strnstr(*env, "PATH", 4))
		{
			c = ft_strnstr(*env, "PATH", 4);
			break ;
		}
		env++;
	}
	if (c == NULL)
		ft_putstr_fd("Pipex: There is no $PATH", 2);
	paths = ft_split(c + 5, ':');
	if (!paths)
		ft_putstr_fd("Pipex: ft_split failed", 2);
	check_cmd_access(paths, argv);
}

static void	first_child(char **argv, char **env, int *fd)
{
	int		infile;
	char	**cmd_op;

	infile = open(argv[1], O_RDONLY, 0644);
	if (infile < 0)
		(perror(""), exit(EXIT_FAILURE));
	if (dup2(infile, STDIN_FILENO) == -1 || dup2(fd[1], STDOUT_FILENO) == -1)
		(perror(""), exit(EXIT_FAILURE));
	close(infile);
	close(fd[0]);
	close(fd[1]);
	if (ft_strchr(argv[2], '/') != NULL && access(argv[2], F_OK | X_OK) == 0)
	{
		cmd_op = ft_split(argv[2], ' ');
		execve(cmd_op[0], cmd_op, NULL);
	}
	retrive_paths(env, argv[2]);
}

static void	second_child(char **argv, char **env, int *fd)
{
	int		outfile;
	char	**cmd_op;

	outfile = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (outfile < 0)
		print_err_exit("", EXIT_FAILURE);
	if (dup2(fd[0], STDIN_FILENO) == -1 || dup2(outfile, STDOUT_FILENO) == -1)
		(perror(""), exit(EXIT_FAILURE));
	close(outfile);
	close(fd[0]);
	close(fd[1]);
	if (ft_strchr(argv[2], '/') != NULL && access(argv[2], F_OK | X_OK) == 0)
	{
		cmd_op = ft_split(argv[3], ' ');
		execve(cmd_op[0], cmd_op, NULL);
	}
	retrive_paths(env, argv[3]);
}

int	main(int argc, char *argv[], char *env[])
{
	int		pipe_fd[2];
	pid_t	child_01;
	pid_t	child_02;

	if (argc != 5)
		ft_putstr_fd("Pipex: Please enter a valid Commands or files", 2);
	if (pipe(pipe_fd) == -1)
		print_err_exit("", EXIT_FAILURE);
	child_01 = fork();
	if (child_01 < 0)
		(perror(""), exit(EXIT_FAILURE));
	else if (child_01 == 0)
		first_child(argv, env, pipe_fd);
	child_02 = fork();
	if (child_02 < 0)
		(perror(""), exit(EXIT_FAILURE));
	else if (0 == child_02)
		second_child(argv, env, pipe_fd);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(child_01, NULL, 0);
	waitpid(child_02, NULL, 0);
	return (EXIT_SUCCESS);
}
