/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:21:34 by yismaili          #+#    #+#             */
/*   Updated: 2022/03/16 18:21:46 by yismaili         ###   ########.fr       */
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

int		ft_sort(t_data *ptr)
{
	if (ptr->stack_a->next == NULL)
		return (0);
	while (check_sorted(ptr->stack_a, 0) != 0 || ptr->stack_b == NULL)
	{
		ptr->min_getf = ft_get_min(ptr);
		if (ptr->min == ptr->stack_a->next->content)
			ft_ra_move(ptr);
		 else
		 {
			while (ptr->index_min -1 > 0)
			{
				if (ptr->min_getf == -1)
					ft_ra_move(ptr) ;
				else
					ft_rra_move(ptr);
				ptr->index_min--;
			 }
		}
		if (check_sorted(ptr->stack_a, 0) == 0 && ptr->stack_b == NULL)
			break ;
		if (ptr->stack_b != NULL && check_sorted(ptr->stack_a, 0) == 0 && check_sorted(ptr->stack_b, 1) == 0)
			break ;
		ft_pb_move(ptr);
	}
	while (ptr->stack_b != NULL)
		ft_pa_move(ptr);
	return (0);
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
