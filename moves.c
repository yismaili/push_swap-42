/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:08:26 by yismaili          #+#    #+#             */
/*   Updated: 2022/03/10 16:12:12 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_sa_move(t_data *ptr)
{
	int	temp;

	if (ptr->stack_a && ptr->stack_a->next)
	{
		temp = ptr->stack_a->content;
		ptr->stack_a->content = ptr->stack_a->next->content;
		ptr->stack_a->next->content = temp;
		ft_putstr_fd("sa ", 1);
		return (1);
	}
	return (0);
}

int ft_sb_move(t_data *ptr)
{
	int	temp;

	if (ptr->stack_b && ptr->stack_b->next)
	{
		temp = ptr->stack_b->content;
		ptr->stack_b->content = ptr->stack_b->next->content;
		ptr->stack_b->next->content = temp;
		ft_putstr_fd("sb ", 1);
		return (1);
	}
	return (0);
}

int	ft_rra_move(t_data *ptr)
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
		ft_putstr_fd("rra ", 1);
		return (1);
	}
	return (0);
}

int	ft_rrb_move(t_data *ptr)
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
		ft_putstr_fd("rrb ", 1);
		return (1);
	}
	return (0);
}

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
		ft_putstr_fd("pa ", 1);
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
		ft_putstr_fd("pb ", 1);
	}
	return (0);
}

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
		ft_putstr_fd("ra ", 1);
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
		ft_putstr_fd("rb ", 1);
		return (1);
	}
	return (0);
}