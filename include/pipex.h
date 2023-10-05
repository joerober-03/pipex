/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joerober <joerober@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:10:24 by joerober          #+#    #+#             */
/*   Updated: 2023/02/24 11:24:49 by joerober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>
# include <stdio.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define INFILE 0
# define OUTFILE 1

typedef struct s_var
{
	int		pipefd[2];
	int		fd[2];
	int		status;
	int		i;
	int		len;
	char	*temp;
}				t_var;

int		chr_len(char *path, char c);
char	*strn_dup(char *str, int n);
char	*link_path(char *dir, char *cmd);
char	*get_path(char *cmd, char **env);
void	do_error2(char *str, t_var *v);
void	initiate_values(t_var *v, int argc);
void	here_gnl(char **argv, t_var *v);
void	here_doc(char **argv, t_var *v);
int		strcmp_pip(const char *s1, const char *s2);
void	exec(char *cmd, char **env, t_var *v);

#endif
