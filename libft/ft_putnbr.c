/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jporta <jporta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:00:37 by jporta            #+#    #+#             */
/*   Updated: 2021/11/04 16:07:10 by jporta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putcharfinal(int final, int nb, int divisor)
{
	int	mostrar;

	mostrar = 0;
	while (divisor != 0)
	{
		mostrar = nb / divisor;
		mostrar = mostrar + final;
		write(1, &mostrar, 1);
		nb = nb % divisor;
		divisor = divisor / 10;
	}
}

void	ft_putnbr(long nb)
{
	int			temporal;
	int			divisor;
	int			final;

	divisor = 1;
	final = 48;
	if (nb == -2147483648)
	{
		 write(1, "-", 1);
		 write(1, "2", 1);
		nb = 147483648;
	}
	if (nb < 0)
	{
		nb = nb * -1;
		 write(1, "-", 1);
	}
	temporal = nb;
	while (temporal / 10 != 0)
	{
		temporal = temporal / 10;
		divisor = divisor * 10;
	}
	 ft_putcharfinal(final, nb, divisor);
}
