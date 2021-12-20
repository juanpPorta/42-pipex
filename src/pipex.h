/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jporta <jporta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 04:05:59 by jporta            #+#    #+#             */
/*   Updated: 2021/12/20 18:39:49 by jporta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct s_push
{
	int		sons;
	int		count;
	int		arc;
	int		comand;
	int		filein;
	int		fileout;
	char	*line;
	char	*delim;
}		t_push;

void	execute(char *argv, char **envp);
void	execute_bonus(char *argv, char **envp, t_push *push);
char	*path(char *cmd, char **envp);
char	*path_bonus(char *cmd, char **envp, t_push *push);
void	ft_errorpipex(int index, t_push *push);
void	ft_errorpipe(int index);
int		init_file(char *argv, int i, t_push *push);
int		get_next_line(char **line);
void	ft_waitpid(int status);
void	ft_pid(pid_t pid);
#endif
