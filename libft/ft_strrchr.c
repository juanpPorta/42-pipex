/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jporta <jporta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 14:33:19 by marvin            #+#    #+#             */
/*   Updated: 2021/09/22 18:47:01 by jporta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	const char	*last;

	last = s;
	i = ft_strlen(s);
	s += i;
	while (s != last && c != *s)
		s--;
	if ((unsigned char)c == (unsigned char)*s)
		return ((char *)s);
	return (0);
}
