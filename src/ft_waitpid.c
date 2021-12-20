/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_waitpid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jporta <jporta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:40:40 by jporta            #+#    #+#             */
/*   Updated: 2021/12/20 18:28:53 by jporta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_waitpid(int status)
{
	if (WEXITSTATUS(status) == EXIT_FAILURE)
		exit(1);
}

void	ft_pid(int ped)
{
	if (ped < 0)
		ft_errorpipe(0);
}
