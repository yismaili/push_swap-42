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

int ft_comparet(t_data *ptr)
{
	int i;
	int j;
	int m;

	t_stack *node = ptr->stack_a;
 	int len = ft_len_stack(ptr);
	 i = 0;
	 j = 0;

	while (len)
	{
		if (node->content > ptr->gitf_index)
			i++;
		if (node->content <= ptr->gitf_index)
		{
			while (i)
			{
				ft_ra_move(ptr);
				i--;
			}
			ft_pb_move(ptr);
			node = ptr->stack_a;
			j++;
			if (j >= 2)
			{
				if (ptr->stack_b->content <= ptr->gits_index)
				{
					ft_rb_move(ptr);
				}
			}
		}
		else
			node = node->next;
		len--;
	}
	return (0);
}
int ft_comparet_tow(t_data *ptr)
{
	int i;
	int j;
	int m;

	t_stack *node = ptr->stack_a;
 	int len = ft_len_stack(ptr);
	 i = 0;
	 j = 0;

	while (len)
	{
		if (node->content > ptr->gittree_index)
			i++;
		if (node->content <= ptr->gittree_index)
		{
			while (i)
			{
				ft_ra_move(ptr);
				i--;
			}
			ft_pb_move(ptr);
			node = ptr->stack_a;
			j++;
			if (j >= 2)
			{
				if (ptr->stack_b->content >= ptr->gits_index)
					ft_rb_move(ptr);
			}
		}
		else
			node = node->next;
		len--;
	}
	return (0);
}

int ft_comparet_for(t_data *ptr)
{
	int i;
	int j;

	t_stack *node = ptr->stack_a;
 	int len = ft_len_stack(ptr);
	 i = 0;
	 j = 0;

	while (len)
	{
		if (node->content > 99)
			i++;
		if (node->content <= 99)
		{
			while (i)
			{
				ft_ra_move(ptr);
				i--;
			}
			ft_pb_move(ptr);
			node = ptr->stack_a;
			j++;
			if (j >= 2)
			{
				if (ptr->stack_b->content >= ptr->gitsfor_index)
					ft_rb_move(ptr);
			}
		}
		else
			node = node->next;
		len--;
	}
	return (0);
}