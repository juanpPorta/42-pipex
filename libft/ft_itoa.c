/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jporta <jporta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 15:13:30 by marvin            #+#    #+#             */
/*   Updated: 2021/09/22 18:47:47 by jporta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_size(int n)
{
	size_t	size;

	if (n > 0)
		size = 0;
	else
		size = 1;
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

static unsigned int	ft_checkn(int n)
{
	unsigned int	nbr;

	if (n > 0)
		nbr = n;
	else
		nbr = -n;
	return (nbr);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	nbr;
	size_t			size;

	nbr = ft_checkn(n);
	size = ft_size(n);
	str = (char *)malloc(size + 1);
	if (!str)
		return (0);
	str[size--] = '\0';
	while (nbr > 0)
	{
		str[size--] = nbr % 10 + '0';
		nbr /= 10;
	}
	if (size == 0 && str[1] == '\0')
		str[size] = '0';
	else if (size == 0 && str[1] != '\0')
		str[size] = '-';
	return (str);
}
