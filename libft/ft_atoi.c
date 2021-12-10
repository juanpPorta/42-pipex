/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jporta <jporta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 15:37:18 by marvin            #+#    #+#             */
/*   Updated: 2021/12/01 19:53:58 by jporta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_error(int num)
{
	if (num == 0)
		printf("Error\n");
	exit (0);
}

int	ft_atoi(char *str)
{
	int				i;
	int				s;
	unsigned int	r;

	i = 0;
	s = 1;
	r = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			s *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = (r * 10) + (str[i] - '0');
		if (r > 2147483647 && s == 1)
			ft_error(0);
		if (r > 2147483648 && s == -1)
			ft_error(0);
		i++;
	}
	return (r * s);
}
