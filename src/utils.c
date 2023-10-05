/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joerober <joerober@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:20:37 by joerober          #+#    #+#             */
/*   Updated: 2023/02/15 14:23:24 by joerober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/pipex.h"

char	*link_path(char *dir, char *cmd)
{
	char	*path;
	int		i;
	int		j;

	path = malloc((ft_strlen(dir) + ft_strlen(cmd) + 2) * sizeof(char));
	i = 0;
	j = 0;
	while (dir[j] != '\0')
	{
		path[i] = dir[j];
		i++;
		j++;
	}
	path[i] = '/';
	i++;
	j = 0;
	while (cmd[j] != '\0')
	{
		path[i] = cmd[j];
		i++;
		j++;
	}
	path[i] = '\0';
	return (path);
}

char	*strn_dup(char *str, int n)
{
	int		i;
	char	*substr;

	i = 0;
	substr = malloc((n + 1) * sizeof(char));
	while (i < n)
	{
		substr[i] = str[i];
		i++;
	}
	substr[n] = '\0';
	return (substr);
}

int	chr_len(char *path, char c)
{
	int	i;

	i = 0;
	while (path[i] != '\0' && path[i] != c)
		i++;
	if (path[i] == c)
		return (i);
	return (-1);
}
