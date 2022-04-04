/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 21:35:11 by yismaili          #+#    #+#             */
/*   Updated: 2022/03/20 21:35:38 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_get_max(t_data *ptr)
{
	int		count;
	int		index_max;
	t_stack	*node;

	ptr->max = MIN_INT;
	count = 1;
	index_max = 1;
	node = ptr->stack_b;
	while (node != NULL)
	{
		if (ptr->max < node->content) 
			index_max = count;
		if(ptr->max < node->content) 
			ptr->max = node->content;
		node = node->next;
		count++;
	}
	ptr->index_max = index_max;
	if(index_max > (count / 2))
	{
		ptr->index_max = abs((count - index_max + 1));
	} 
	count /= 2;
	if (index_max > count)
		return (1);
	else
		return (-1);
}

int		check(t_stack *stack, int mode)
{
	t_stack	*node;

	node = stack;
	while (node->next != NULL)
	{
		if (mode == 0 && node != NULL)
			return (-1);
		node = node->next;
	}
	return (0);
}

int ft_push_to_a(t_data *ptr)
{
  if (ptr->stack_b->next == NULL)
		return (0);
	while (check(ptr->stack_b, 0) != 0)
	{
		ptr->mx = ft_get_max(ptr);
		if (ptr->max == ptr->stack_b->next->content)
			ft_sb_move(ptr);
		 else
		 {
			while (ptr->index_max  > 1)
			{
				if (ptr->mx == -1)
					ft_rb_move(ptr) ;
				else
					ft_rrb_move(ptr);
				ptr->index_max--;
			 }
		}
		ft_pa_move(ptr);
	}
	ft_pa_move(ptr);
	return (0);
}