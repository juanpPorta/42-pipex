/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jporta <jporta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:06:16 by jporta            #+#    #+#             */
/*   Updated: 2021/12/15 04:22:39 by jporta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_errorpipex(int index)
{
	if (index == 0)
	{
		ft_putstr_fd("u try to fuck me\n", 2);
		exit(EXIT_SUCCESS);
	}
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

void	heredox(char *argv, int argc)
{
	pid_t	pid;
	int		fd[2];
	char	*line;

	if (argc < 6)
		ft_errorpipex(0);
	if (pipe(fd) == -1)
		ft_errorpipex(0);
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		while (get_next_line(&line))
		{
			if (ft_strncmp(line, argv, ft_strlen(argv)) == 0)
				exit(EXIT_SUCCESS);
			write(fd[1], line, ft_strlen(line));
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
			push->fileout = init_file(argv[argc - 1], 0);
			heredox(argv[2], argc);
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
