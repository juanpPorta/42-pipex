/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jporta <jporta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:16:45 by jporta            #+#    #+#             */
/*   Updated: 2021/11/03 20:44:36 by jporta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_error(char *base)
{
	char	*checkbase;
	int		i_base;

	checkbase = base;
	if (*base == 0 || *(base + 1) == 0)
		return (0);
	while (*checkbase)
	{
		if (*checkbase == '+' || *checkbase == '-' || *checkbase <= 32)
			return (0);
		i_base = 1;
		while (*(checkbase + i_base))
		{
			if (*(checkbase + i_base) == *checkbase)
				return (0);
			i_base++;
		}
		checkbase++;
	}
	return (1);
}

int	ft_lentbase(char *base)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	while (base[i] != '\0')
	{
		i++;
		a++;
	}
	return (a);
}

int	ft_putnbr_base(long long nbr, char *base)
{
	unsigned long long	lenbase;
	unsigned long long	nbr_unsigned;
	static int			cont;

	if (!cont)
		cont = 0;
	if (check_error(base))
	{
		if (nbr < 0 && ft_strlen(base) == 10)
		{
			cont += write(1, "-", 1);
			nbr_unsigned = (long long)(-1 * nbr);
		}
		else
			nbr_unsigned = nbr;
		lenbase = ft_strlen(base);
		if (nbr_unsigned >= lenbase)
		{
			ft_putnbr_base(nbr_unsigned / lenbase, base);
			ft_putnbr_base(nbr_unsigned % lenbase, base);
		}
		else
			cont += write(1, base + nbr_unsigned, 1);
	}
	return (cont);
}
