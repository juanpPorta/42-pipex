/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jporta <jporta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:06:16 by jporta            #+#    #+#             */
/*   Updated: 2021/12/14 18:52:31 by jporta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_prueba(int *fd, char **argv, char **envp, t_push *push)
{
	close(fd[1]);
	dup2(fd[0], 0);
	close(fd[0]);
	dup2(fd[1], 1);
	printf("hola\n");
	close(fd[1]);
	printf("error hijo\n");
	dup2(fd[0], 0);
	close(fd[0]);
	execute(argv[push->comand], envp);
	push->comand += 1;
}

void	luck(char **argv, char **envp, int *fd, t_push *push)
{
	int	filein;

	if (push->count == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		close(fd[1]);
		filein = open(argv[1], O_RDONLY, 0777);
		if (filein == -1)
			printf("error hijo\n");
		dup2(filein, 0);
		execute(argv[2], envp);
	}
	else
		ft_prueba(fd, argv, envp, push);
}

void	vader(char **argv, char **envp, int *fd, int argc)
{
	int	fileout;

	fileout = open(argv[argc], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (fileout == -1)
		printf("error padre\n");
	close(fd[1]);
	dup2(fd[0], 0);
	close(fd[0]);
	dup2(fileout, 1);
	execute(argv[argc - 1], envp);
}

void	ft_init(t_push *push)
{
	push->arc = 0;
	push->count = 0;
	push->comand = 0;
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	int		pid;
	t_push	*push;

	push = malloc(sizeof(t_push));
	ft_init(push);
	push->arc = argc;
	push->comand = 3;
	if (push->arc >= 5)
	{
		push->count = 0;
		push->sons = argc - 5;
		while (push->sons-- != 0)
		{
			if (pipe(fd) == -1)
				printf("mal\n");
			pid = fork();
			if (pid < 0)
				printf("mal\n");
			if (pid == 0)
			{
				printf("sons: %d\n", push->sons);
				luck(argv, envp, fd, push);
			}	
		}
		waitpid(pid, NULL, 0);
		vader(argv, envp, fd, argc);
	}
	else
		printf("u try to fuck me\n");
	return (0);
}
