/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 20:08:54 by yismaili          #+#    #+#             */
/*   Updated: 2022/03/19 20:09:01 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_get_min(t_data *ptr)
{
	int		count;
	int		index_min;
	t_stack	*node;

	ptr->min = MAX_INT;
	count = 1;
	index_min = 1;
	node = ptr->stack_a;
	while (node != NULL)
	{
		if (ptr->min > node->content) 
			index_min = count;
		if(ptr->min > node->content) 
			ptr->min = node->content;
		node = node->next;
		count++;
	}
	ptr->index_min = index_min;
	if(index_min > (count / 2) )
	{
		ptr->index_min = abs((count - index_min + 1));
	} 
	count /= 2;
	if (index_min > count)
		return (1);
	else
		return (-1);
}

int		check_sorted(t_stack *stack, int mode)
{
	t_stack	*node;

	node = stack;
	while (node->next != NULL)
	{
		if (mode == 0 && node->content > node->next->content)
			return (-1);
		if (mode == 1 && node->content < node->next->content)
			return (-1);
		node = node->next;
	}
	return (0);
}

void ft_sort_temp(t_data *ptr)
{
	int i;
	int  temp;
	t_stack *unde;
	unde = ptr->temp;
	while (ptr->len_stack)
	{
		ptr->temp = unde;
		while (ptr->temp->next != NULL)
		{
			if (ptr->temp->content > ptr->temp->next->content)
			{
				temp = ptr->temp->content;
				ptr->temp->content = ptr->temp->next->content;
				ptr->temp->next->content = temp;
			}
			ptr->temp = ptr->temp->next;
		}
		ptr->len_stack --;
	}
	ptr->temp = unde;
}