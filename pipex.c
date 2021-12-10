/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jporta <jporta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 00:59:42 by jporta            #+#    #+#             */
/*   Updated: 2021/12/10 18:44:15 by jporta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	luck(char **argv, char **envp, int *fd)
{
	int		filein;

	filein = open(argv[1], O_RDONLY, 0777);
	if (filein == -1)
		printf("error\n");
	dup2(fd[1], STDOUT_FILENO);
	dup2(filein, STDIN_FILENO);
	close(fd[0]);
	execute(argv[2], envp);
}


void	vader(char **argv, char **envp, int *fd)
{
	int		fileout;

	fileout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fileout == -1)
		printf("error\n");
	dup2(fd[0], STDOUT_FILENO);
	close(fd[0]);
	dup2(fileout, STDIN_FILENO);
	execute(argv[3], envp);
}

int main(int argc, char **argv, char **envp)
{
    int fd[2];
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
		close(fd[0]);
		close(fd[1]);
	}
	else
	{
		printf("quiere a cristo rey!!\n");	
		printf("quiere a cristo rey!!\n");	
		printf("quiere a cristo rey!!\n");	
	}
	return (0);
}
