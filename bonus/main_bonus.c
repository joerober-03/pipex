/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joerober <joerober@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:39:30 by joerober          #+#    #+#             */
/*   Updated: 2023/02/24 11:28:42 by joerober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/pipex.h"

char	*get_path(char *cmd, char **env)
{
	int		i;
	char	*path;
	char	*dir;
	char	*bin;

	i = 0;
	if (ft_strnstr(cmd, "/", ft_strlen(cmd)))
		return (cmd);
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

void	do_pipe(t_var *v, char *argv, char **env)
{
	pid_t	pid;

	if (pipe(v->pipefd) < 0)
		do_error2("error executing pipe", v);
	pid = fork();
	if (pid < 0)
		do_error2("error executing fork", v);
	if (pid == 0)
	{
		close(v->pipefd[0]);
		dup2(v->pipefd[1], STDOUT);
		exec(argv, env, v);
	}
	else
	{
		close(v->pipefd[1]);
		dup2(v->pipefd[0], STDIN);
	}
}

void	initiate_here_doc(char **argv, int argc, t_var *v)
{
	if (argc < 6)
		do_error2("wrong number of arguments", v);
	v->i = 3;
	v->fd[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	here_doc(argv, v);
}

void	initiate_normal(char **argv, int argc, t_var *v)
{
	v->i = 2;
	v->fd[0] = open(argv[1], O_RDONLY);
	v->fd[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (v->fd[0] < 0 || v->fd[1] < 0)
		do_error2("no such file or directory", v);
	dup2(v->fd[0], STDIN);
}

int	main(int argc, char **argv, char **env)
{
	t_var	*v;

	if (argc >= 5)
	{
		v = (t_var *)malloc(sizeof(t_var));
		v->temp = ft_strjoin(argv[1], "\n");
		if (strcmp_pip("here_doc", argv[1]) == 0)
			initiate_here_doc(argv, argc, v);
		else
			initiate_normal(argv, argc, v);
		while (v->i < argc - 2)
			do_pipe(v, argv[v->i++], env);
		dup2(v->fd[1], STDOUT);
		exec(argv[argc - 2], env, v);
		free(v);
	}
	else
		ft_putstr_fd("wrong number of arguments\n", 2);
	return (0);
}
