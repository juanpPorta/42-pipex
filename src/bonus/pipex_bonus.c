/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jporta <jporta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:06:16 by jporta            #+#    #+#             */
/*   Updated: 2021/12/15 02:10:49 by jporta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_errorpipex(int index)
{
	if (index == 0)
	{
		printf("u try to fuck me\n");
		exit(EXIT_SUCCESS);
	}
}

int	luck(char **argv, char **envp, int *fd)
{
	int	filein;

	close(fd[0]);
	dup2(fd[1], 1);
	close(fd[1]);
	filein = open(argv[1], O_RDONLY);
	if (filein < 0)
		ft_errorpipex(0);
	dup2(filein, 0);
	execute(argv[2], envp);
	close(filein);
	return (0);
}

int	luck2(char **argv, char **envp, int *fd, t_push *push)
{
	close(fd[1]);
	dup2(fd[0], 0);
	close(fd[0]);
	dup2(fd[1], 1);
	close(fd[1]);
	execute(argv[push->comand], envp);
	return (0);
}

int	vader(char **argv, char **envp, int *fd, t_push *push)
{
	int				fileout;

	close(fd[1]);
	dup2(fd[0], 0);
	close(fd[0]);
	fileout = open(argv[push->file], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (fileout == -1)
		ft_errorpipex(0);
	dup2(fileout, 1);
	printf("polla en culo bb\n");
	execute(argv[push->file - 1], envp);
	close(fileout);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	int		pid;
	t_push	*push;

	if (argc >= 5)
	{
		push = malloc(sizeof(t_push));
		push->sons = argc - 5;
		push->count = -1;
		push->arc = -1;
		push->file = 1;
		push->comand = 1;
		push->file = argc - 1;
		while (push->count < push->sons)
		{
			if (pipe(fd) == -1)
				ft_errorpipex(0);
			pid = fork();
			push->count++;
			push->arc++;
			push->comand++;
			printf("comand %d\n", push->comand);
			if (pid < 0)
				ft_errorpipex(0);
			if (pid == 0)
			{
				if (push->arc == 0)
				{
					printf("pid1: %d\n", pid);
					luck(argv, envp, fd);
				}
				else if (push->arc > 0)
				{
					printf("pid2: %d\n", pid);
					luck2(argv, envp, fd, push);
				}
			}
			waitpid(pid, NULL, 0);
		}
		printf("pid3: %d\n", pid);
		waitpid(pid, NULL, 0);
		vader(argv, envp, fd, push);
	}
	else
		ft_errorpipex(0);
	return (0);
}
