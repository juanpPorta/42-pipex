/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jporta <jporta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 19:50:37 by marvin            #+#    #+#             */
/*   Updated: 2021/09/16 16:57:25 by jporta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*stack;

	stack = (void *)malloc(num * size);
	if (!stack)
		return (0);
	ft_bzero (stack, (num * size));
	return (stack);
}
