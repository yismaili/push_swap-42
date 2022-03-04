/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:08:58 by yismaili          #+#    #+#             */
/*   Updated: 2022/03/03 16:43:26 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_addback(t_push **lst, t_push *newlst)
{
	t_push	*lt;

	if (*lst)
	{
		lt = ft_lstlast(*lst);
		lt->next = &*newlst;
	}
	else
	{
		*lst = newlst;
	}
}

void	ft_addfront(t_push **lst, t_push *newlst)
{
	if (lst && newlst)
	{
		newlst->next = *lst;
		*lst = newlst;
	}
}

void ft_lstnew(t_push ** head_ref, int new_data)
{
    t_push* new_node = (t_push*) malloc(sizeof(t_push));

    new_node->content  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}

t_push	*ft_lstlast(t_push *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}
