/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:13:42 by yismaili          #+#    #+#             */
/*   Updated: 2022/03/10 16:13:46 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_ra_move(t_data *ptr)
{
	t_stack	*temp;

	if (ptr->stack_a != NULL && ptr->stack_a->next != NULL)
	{
		temp = ptr->stack_a;
		ptr->stack_a = ptr->stack_a->next;
		ptr->stack_end_a->next = temp;
		temp->next = NULL;
		ptr->stack_end_a = temp;
		ft_putstr_fd("ra\n", 1);
		return (1);
	}
	return (0);
}

int	ft_rb_move(t_data *ptr)
{
	t_stack	*temp;

	if (ptr->stack_b != NULL && ptr->stack_b->next != NULL)
	{
		temp = ptr->stack_b;
		ptr->stack_b = ptr->stack_b->next;
		temp->next = NULL;
		ptr->stack_end_b->next = temp;
		ptr->stack_end_b = temp;
		ft_putstr_fd("rb\n", 1);
		return (1);
	}
	return (0);
}
int	ft_sra_move(t_data *ptr)
{
	t_stack	*temp;

	if (ptr->stack_a != NULL && ptr->stack_a->next != NULL)
	{
		temp = ptr->stack_a;
		ptr->stack_a = ptr->stack_a->next;
		temp->next = NULL;
		ptr->stack_end_a->next = temp;
		ptr->stack_end_a = temp;
		return (1);
	}
	return (0);
}

int	ft_srb_move(t_data *ptr)
{
	t_stack	*temp;

	if (ptr->stack_b != NULL && ptr->stack_b->next != NULL)
	{
		temp = ptr->stack_b;
		ptr->stack_b = ptr->stack_b->next;
		temp->next = NULL;
		ptr->stack_end_b->next = temp;
		ptr->stack_end_b = temp;
		return (1);
	}
	return (0);
}
void ft_rr_move(t_data *ptr)
{
	if (ft_len_stack(ptr) < 2)
	{
		return ;
	}
	//printf("%d\n", ft_len_stack(ptr));
	ft_srb_move(ptr);
	ft_sra_move(ptr);
	write(1,"rr\n", 3);
}