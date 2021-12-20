/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jporta <jporta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:06:16 by jporta            #+#    #+#             */
/*   Updated: 2021/12/20 18:41:25 by jporta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_solution(char **argv, int argc, t_push *push)
{
	push->fileout = init_file(argv[argc - 1], 0, push);
	push->delim = ft_strjoin(argv[2], "\n");
}

void	luck(char *argv, char **envp, t_push *push)
{
	pid_t	pid;
	int		fd[2];
	int		status;

	if (pipe(fd) == -1)
		ft_errorpipex(0, push);
	pid = fork();
	if (pid == -1)
		ft_errorpipex(0, push);
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		execute_bonus(argv, envp, push);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, &status, 0);
		ft_waitpid(status);
	}
}

void	heredox(t_push *push, int argc)
{
	pid_t	pid;
	int		fd[2];

	if (argc < 6)
		ft_errorpipex(0, push);
	if (pipe(fd) == -1)
		ft_errorpipex(0, push);
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
			push->fileout = init_file(argv[argc - 1], 1, push);
			push->filein = init_file(argv[1], 2, push);
			dup2(push->filein, STDIN_FILENO);
		}
		while (comand < argc - 2)
			luck(argv[comand++], envp, push);
		dup2(push->fileout, STDOUT_FILENO);
		execute_bonus(argv[argc - 2], envp, push);
	}
	ft_errorpipe(0);
}
