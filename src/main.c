/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joerober <joerober@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:11:42 by joerober          #+#    #+#             */
/*   Updated: 2023/02/21 11:17:09 by joerober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/pipex.h"

void	do_error(char *str)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}

char	*get_path(char *cmd, char **env)
{
	int		i;
	char	*path;
	char	*dir;
	char	*bin;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5))
		i++;
	path = env[i] + 5;
	while (path && chr_len(path, ':') > -1)
	{
		dir = strn_dup(path, chr_len(path, ':'));
		bin = link_path(dir, cmd);
		free(dir);
		if (access(bin, F_OK) == 0)
			return (bin);
		free (bin);
		path += chr_len(path, ':') + 1;
	}
	return (0);
}

void	child_two(int *pipefd, int *fd, char **argv, char **env)
{
	pid_t	pid;
	char	**args;

	pid = fork();
	if (pid < 0)
		do_error("error executing fork");
	if (pid == 0)
	{
		fd[1] = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd[1] < 0)
			do_error("file couldn't be opened");
		close(pipefd[1]);
		dup2(fd[1], STDOUT);
		dup2(pipefd[0], STDIN);
		args = ft_split(argv[3], ' ');
		if (args[0] && get_path(args[0], env))
			execve(get_path(args[0], env), args, env);
		else
			do_error("command not found");
	}
}

void	child_one(int *pipefd, int *fd, char **argv, char **env)
{
	pid_t	pid;
	char	**args;

	pid = fork();
	if (pid < 0)
		do_error("error executing fork");
	if (pid == 0)
	{
		fd[0] = open(argv[1], O_RDONLY);
		if (fd[0] < 0)
			do_error("file counldn't be opened");
		close(pipefd[0]);
		dup2(fd[0], STDIN);
		dup2(pipefd[1], STDOUT);
		args = ft_split(argv[2], ' ');
		if (args[0] && get_path(args[0], env))
			execve(get_path(args[0], env), args, env);
		else
			do_error("command not found");
	}
}

int	main(int argc, char **argv, char **env)
{
	int		pipefd[2];
	int		fd[2];
	int		status;

	if (argc == 5)
	{
		if (pipe(pipefd) < 0)
		{
			perror("error executing pipe");
			exit(EXIT_FAILURE);
		}
		child_one(pipefd, fd, argv, env);
		child_two(pipefd, fd, argv, env);
		close(pipefd[0]);
		close(pipefd[1]);
		waitpid(-1, &status, 0);
		waitpid(-1, &status, 0);
	}
	else
		ft_putstr_fd("wrong number of arguments\n", 2);
	return (0);
}
