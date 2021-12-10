/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jporta <jporta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 13:46:55 by marvin            #+#    #+#             */
/*   Updated: 2021/11/29 18:11:57 by jporta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*back;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	back = ft_lstlast(*lst);
	back->next = new;
}
