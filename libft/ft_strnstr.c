/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jporta <jporta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 15:27:55 by marvin            #+#    #+#             */
/*   Updated: 2021/09/16 14:59:12 by jporta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	stack;

	if (*to_find == '\0')
		return ((char *)str);
	stack = ft_strlen((char *)to_find);
	while (*str != '\0' && len-- >= stack)
	{
		if (*str == *to_find && ft_memcmp(str, to_find, stack) == 0)
			return ((char *)str);
		str++;
	}
	return (NULL);
}
