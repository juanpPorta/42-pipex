/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jporta <jporta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:06:16 by jporta            #+#    #+#             */
/*   Updated: 2021/12/16 16:35:44 by jporta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_solution(char **argv, int argc, t_push *push)
{
	push->fileout = init_file(argv[argc - 1], 0);
	push->delim = ft_strjoin(argv[2], "\n");
}

void	luck(char *argv, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		ft_errorpipex(0);
	pid = fork();
	if (pid == -1)
		ft_errorpipex(0);
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		execute(argv, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

void	heredox(t_push *push, int argc)
{
	pid_t	pid;
	int		fd[2];

	if (argc < 6)
		ft_errorpipex(0);
	if (pipe(fd) == -1)
		ft_errorpipex(0);
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		while (get_next_line(&push->line))
		{
			if (ft_strncmp(push->line, push->delim,
					ft_strlen(push->delim)) == 0)
				exit(EXIT_SUCCESS);
			write(fd[1], push->line, ft_strlen(push->line));
		}
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		comand;
	t_push	*push;

	if (argc >= 5)
	{
		push = malloc(sizeof(t_push));
		if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		{
			comand = 3;
			ft_solution(argv, argc, push);
			heredox(push, argc);
		}
		else
		{
			comand = 2;
			push->fileout = init_file(argv[argc - 1], 1);
			push->filein = init_file(argv[1], 2);
			dup2(push->filein, STDIN_FILENO);
		}
		while (comand < argc - 2)
			luck(argv[comand++], envp);
		dup2(push->fileout, STDOUT_FILENO);
		execute(argv[argc - 2], envp);
	}
	ft_errorpipex(0);
}
