/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jporta <jporta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 00:59:42 by jporta            #+#    #+#             */
/*   Updated: 2021/12/13 19:48:30 by jporta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	luck(char **argv, char **envp, int *fd)
{
	int		filein;

	close(fd[0]);
	dup2(fd[1], 1);
	close(fd[1]);
	filein = open(argv[1], O_RDONLY, 0777);
	if (filein == -1)
		printf("error\n");
	dup2(filein, 0);
	execute(argv[2], envp);
	close(filein);
}

void	vader(char **argv, char **envp, int *fd)
{
	int		fileout;

	close(fd[1]);
	dup2(fd[0], 0);
	close(fd[0]);
	fileout = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (fileout == -1)
		printf("error\n");
	dup2(fileout, 1);
	execute(argv[3], envp);
	close(fileout);
}

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];
	int	pid;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			printf("mal\n");
		pid = fork();
		if (pid < 0)
			printf("mal\n");
		if (pid == 0)
			luck(argv, envp, fd);
		waitpid(pid, NULL, 0);
		vader(argv, envp, fd);
	}
	else
		printf("u try to fuck me\n");
	return (0);
}
