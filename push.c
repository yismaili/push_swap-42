/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:13:18 by yismaili          #+#    #+#             */
/*   Updated: 2022/03/10 15:13:22 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_pa_move(t_data *ptr)
{
	t_stack	*temp;

	if (ptr->stack_b != NULL)
	{
		temp = ptr->stack_b;
		ptr->stack_b = ptr->stack_b->next;
		temp->next = ptr->stack_a;
		ptr->stack_a = temp;
		ptr->stack_a->next == NULL ? ptr->stack_end_a = ptr->stack_a : 0;
		ptr->stack_b == NULL ? ptr->stack_end_b = NULL : 0;
		ft_putstr_fd("pa\n", 1);
	}
	return (0);
}

int ft_pb_move(t_data *ptr)
{
	t_stack	*temp;

	if (ptr->stack_a != NULL)
	{
		temp = ptr->stack_a;
		ptr->stack_a = ptr->stack_a->next;
		temp->next = ptr->stack_b;
		ptr->stack_b = temp;
		ptr->stack_b->next == NULL ? ptr->stack_end_b = ptr->stack_b : 0;
		ptr->stack_a == NULL ? ptr->stack_end_a = NULL : 0;
		ft_putstr_fd("pb\n", 1);
	}
	return (0);
}