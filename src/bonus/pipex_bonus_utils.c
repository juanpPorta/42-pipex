/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jporta <jporta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:16:44 by jporta            #+#    #+#             */
/*   Updated: 2021/12/21 16:04:48 by jporta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	get_next_line(char **line)
{
	char	*buffer;
	int		i;
	int		r;
	char	c;

	i = 0;
	r = 0;
	buffer = (char *)malloc(10000);
	if (!buffer)
		return (-1);
	r = read(0, &c, 1);
	while (r && c != '\n' && c != '\0')
	{
		if (c != '\n' && c != '\0')
			buffer[i] = c;
		i++;
		r = read(0, &c, 1);
	}
	buffer[i] = '\n';
	buffer[++i] = '\0';
	*line = ft_strdup(buffer);
	free(buffer);
	return (r);
}

int	init_file(char *argv, int i, t_push *push)
{
	int	file;

	file = 0;
	if (i == 0)
		file = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0777);
	else if (i == 1)
		file = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (i == 2)
		file = open(argv, O_RDONLY, 0777);
	if (file == -1)
		ft_errorpipex(0, push);
	return (file);
}

char	*path_bonus(char *cmd, char **envp, t_push *push)
{
	char	**paths;
	char	*path;
	char	*part_path;
	int		i;

	i = 0;
	while (envp[i] != NULL && ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	if (envp[i] == NULL)
		ft_errorpipex(0, push);
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, X_OK) == 0)
		{
			free(paths[i]);
			return (path);
		}
		i++;
	}
	return (0);
}

void	execute_bonus(char *argv, char **envp, t_push *push)
{
	char	**cmd;
	int		i;

	cmd = ft_split(argv, ' ');
	i = -1;
	if (cmd[0][0] == '/' || cmd[0][0] == '.' || cmd[0][0] == '~'
		|| access(cmd[0], X_OK) == 0)
	{
		if (execve(cmd[0], cmd, envp) == -1)
		{
			while (cmd[++i])
				free(cmd[i]);
			free(cmd);
			ft_errorpipex(0, push);
		}
	}
	if (execve(path_bonus(cmd[0], envp, push), cmd, envp) == -1)
	{
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
		ft_errorpipex(0, push);
	}
}
