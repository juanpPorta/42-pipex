/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jporta <jporta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 04:05:59 by jporta            #+#    #+#             */
/*   Updated: 2021/12/15 04:02:29 by jporta           ###   ########.fr       */
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
	int	sons;
	int	count;
	int	arc;
	int	comand;
	int	filein;
	int	fileout;
}		t_push;

void	execute(char *argv, char **envp);
char	*path(char *cmd, char **envp);
void	ft_errorpipex(int index);
int		init_file(char *argv, int i);
int		get_next_line(char **line);
#endif
