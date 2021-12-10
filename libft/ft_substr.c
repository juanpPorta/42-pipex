/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jporta <jporta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 16:20:58 by jporta            #+#    #+#             */
/*   Updated: 2021/10/27 15:35:39 by jporta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	cont;
	size_t	a;

	a = start;
	cont = 0;
	if (!s)
		return (0);
	cont = 0;
	while (cont < len && s[a++])
		cont++;
	substr = (char *)malloc(cont + 1);
	if (!substr)
		return (0);
	a = start;
	cont = 0;
	while (cont < len && a < ft_strlen(s))
		substr[cont++] = s[a++];
	substr[cont] = '\0';
	return (substr);
}
