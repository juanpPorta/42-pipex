/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jporta <jporta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 13:59:43 by marvin            #+#    #+#             */
/*   Updated: 2021/11/29 18:13:18 by jporta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, int (*del)(int *))
{
	t_list	*aux;

	if (!*lst)
		return ;
	while (*lst)
	{
		aux = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = aux;
	}
	*lst = NULL;
}
