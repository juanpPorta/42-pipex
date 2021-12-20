/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jporta <jporta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 00:59:42 by jporta            #+#    #+#             */
/*   Updated: 2021/12/20 18:29:43 by jporta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	luck(char **argv, char **envp, int *fd, int filein)
{
	close(fd[0]);
	dup2(fd[1], 1);
	close(fd[1]);
	dup2(filein, 0);
	execute(argv[2], envp);
	close(filein);
	return (0);
}

int	vader(char **argv, char **envp, int *fd)
{
	int		fileout;

	close(fd[1]);
	dup2(fd[0], 0);
	close(fd[0]);
	fileout = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (fileout == -1)
		ft_errorpipe(0);
	dup2(fileout, 1);
	close(fileout);
	execute(argv[3], envp);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	int		pid;
	int		filein;
	int		status;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			ft_errorpipe(0);
		pid = fork();
		ft_pid(pid);
		if (pid == 0)
		{
			filein = open(argv[1], O_RDONLY);
			if (filein < 0)
				ft_errorpipe(0);
			luck(argv, envp, fd, filein);
		}
		waitpid(pid, &status, 0);
		ft_waitpid(status);
		vader(argv, envp, fd);
	}
	else
		ft_errorpipe(0);
	return (0);
}
