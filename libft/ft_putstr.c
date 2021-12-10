/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jporta <jporta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:12:02 by jporta            #+#    #+#             */
/*   Updated: 2021/11/03 17:35:46 by jporta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char *str)
{
	int	cont;
	int	i;

	cont = 0;
	i = 0;
	if (str == 0)
	{
		write (1, "(", 1);
		write (1, "n", 1);
		write (1, "u", 1);
		write (1, "l", 1);
		write (1, "l", 1);
		write (1, ")", 1);
		return (6);
	}
	while (str[i] != '\0')
	{
		cont += write(1, &str[i], 1);
		i++;
	}
	return (cont);
}
