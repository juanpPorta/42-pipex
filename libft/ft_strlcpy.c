/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jporta <jporta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 12:49:54 by marvin            #+#    #+#             */
/*   Updated: 2021/09/23 14:36:59 by jporta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	indx;

	indx = 0;
	if (!dst || !src)
		return (ft_strlen(src));
	if (size == 0)
		return (ft_strlen(src));
	while (src[indx] != '\0' && indx < (size - 1))
	{
		dst[indx] = src[indx];
		indx++;
	}
	dst[indx] = '\0';
	return (ft_strlen(src));
}
