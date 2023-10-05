/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joerober <joerober@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:47:03 by joerober          #+#    #+#             */
/*   Updated: 2023/02/24 11:26:08 by joerober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/pipex.h"

void	do_error2(char *str, t_var *v)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	free(v);
	exit(EXIT_FAILURE);
}

int	strcmp_pip(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	here_gnl(char **argv, t_var *v)
{
	char	*str;
	char	*temp;

	temp = ft_strjoin(argv[2], "\n");
	close(v->pipefd[0]);
	while (1)
	{
		ft_putstr_fd("here_doc> ", STDOUT);
		str = get_next_line(0);
		if (strcmp_pip(temp, str) == 0)
		{
			free(str);
			exit(0);
		}
		ft_putstr_fd(str, v->pipefd[1]);
		free(str);
	}
}

void	here_doc(char **argv, t_var *v)
{
	pid_t	pid;

	if (pipe(v->pipefd) < 0)
		do_error2("error executing pipe", v);
	pid = fork();
	if (pid < 0)
		do_error2("error executing fork", v);
	if (pid == 0)
		here_gnl(argv, v);
	else
	{
		close(v->pipefd[1]);
		dup2(v->pipefd[0], STDIN);
		wait(NULL);
	}
}
