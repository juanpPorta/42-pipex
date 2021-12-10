/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jporta <jporta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:14:00 by marvin            #+#    #+#             */
/*   Updated: 2021/11/29 18:13:38 by jporta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, int (*f)(int *))
{
	if (!lst || !f)
		return ;
	while (lst != NULL)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}
