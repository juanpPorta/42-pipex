/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jporta <jporta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:22:47 by marvin            #+#    #+#             */
/*   Updated: 2021/11/29 18:09:05 by jporta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, int *(*f)(int *), int (*del)(int *))
{
	t_list	*list;
	t_list	*elem;

	if (!lst)
		return (0);
	list = 0;
	while (lst)
	{
		elem = ft_lstnew((*f)(lst->content));
		if (!elem)
		{
			ft_lstclear(&lst, del);
			return (0);
		}
		ft_lstadd_back(&list, elem);
		lst = lst->next;
	}
	return (list);
}
