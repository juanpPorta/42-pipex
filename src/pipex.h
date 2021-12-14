/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jporta <jporta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 04:05:59 by jporta            #+#    #+#             */
/*   Updated: 2021/12/14 19:53:24 by jporta           ###   ########.fr       */
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
}		t_push;

void	execute(char *argv, char **envp);
char	*path(char *cmd, char **envp);
void	ft_errorpipex(int index);
#endif
