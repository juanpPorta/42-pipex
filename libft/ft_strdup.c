/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jporta <jporta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 19:52:18 by marvin            #+#    #+#             */
/*   Updated: 2021/09/16 16:56:00 by jporta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s_dup;

	s_dup = (char *)malloc(ft_strlen(s1) + 1);
	if (!s_dup)
		return (0);
	ft_memcpy(s_dup, s1, ft_strlen(s1) + 1);
	return (s_dup);
}
