/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jporta <jporta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:21:27 by jporta            #+#    #+#             */
/*   Updated: 2021/12/20 18:37:01 by jporta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_errorpipex(int index, t_push *push)
{
	if (index == 0)
	{
		ft_putstr_fd("u try to fuck me\n", 2);
		free(push);
		exit(EXIT_FAILURE);
	}
	if (index == 1)
	{
		ft_putstr_fd("u try to fuck me\n", 2);
		exit(EXIT_FAILURE);
	}
}

void	ft_errorpipe(int index)
{
	if (index == 0)
	{
		ft_putstr_fd("u try to fuck me\n", 2);
		exit(EXIT_FAILURE);
	}
}
