/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revers_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:13:56 by yismaili          #+#    #+#             */
/*   Updated: 2022/04/05 17:29:53 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rra_move(t_data *ptr, char c)
{
	t_stack	*temp;
	t_stack	*temp_end;

	if (ptr->stack_a != NULL && ptr->stack_a->next != NULL)
	{
		temp = ptr->stack_a;
		temp_end = ptr->stack_end_a;
		while (temp->next != ptr->stack_end_a)
			temp = temp->next;
		ptr->stack_end_a = temp;
		ptr->stack_end_a->next = NULL;
		temp_end->next = ptr->stack_a;
		ptr->stack_a = temp_end;
		if (c == 'a')
			ft_putstr_fd("rra\n", 1);
		return (1);
	}
	return (0);
}

int	ft_rrb_move(t_data *ptr, char c)
{
	t_stack	*temp;
	t_stack	*temp_end;

	if (ptr->stack_b != NULL && ptr->stack_b->next != NULL)
	{
		temp = ptr->stack_b;
		temp_end = ptr->stack_end_b;
		while (temp->next != ptr->stack_end_b)
			temp = temp->next;
		ptr->stack_end_b = temp;
		ptr->stack_end_b->next = NULL;
		temp_end->next = ptr->stack_b;
		ptr->stack_b = temp_end;
		if (c == 'b')
			ft_putstr_fd("rrb\n", 1);
		return (1);
	}
	return (0);
}

void	ft_rrr_move(t_data *ptr)
{
	if (ft_len_stack(ptr) < 2)
	{
		return ;
	}
	ft_rrb_move(ptr, 's');
	ft_rra_move(ptr, 's');
	write(1, "rrr\n", 3);
}
