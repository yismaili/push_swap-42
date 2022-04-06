/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 21:49:52 by yismaili          #+#    #+#             */
/*   Updated: 2022/04/05 22:25:18 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_len_stack(t_data *ptr)
{
	int		len;
	t_stack	*node;

	len = 0;
	node = ptr->stack_a;
	while (node != NULL)
	{
		node = node->next;
		len++;
	}
	return (len);
}

int	get_frst_index(t_data *ptr)
{
	int		len;
	t_stack	*tmp;

	len = len_temp(ptr);
	len /= 3;
	tmp = ptr->temp;
	while (len)
	{
		ptr->temp = ptr->temp->next;
		len --;
	}
	ptr->gitf_index = ptr->temp->content;
	ptr->temp = tmp;
	return (0);
}

int	get_scnd_index(t_data *ptr)
{
	int		len;
	t_stack	*tmp;

	len = len_temp(ptr) / 3;
	len /= 2;
	tmp = ptr->temp;
	while (len)
	{
		ptr->temp = ptr->temp->next;
		len--;
	}
	ptr->gits_index = ptr->temp->content;
	ptr->temp = tmp;
	return (0);
}

int	ft_comparet(t_data *ptr)
{
	int		i;
	int		len;
	t_stack	*node;

	i = 0;
	get_frst_index(ptr);
	get_scnd_index(ptr);
	node = ptr->stack_a;
	len = ft_len_stack(ptr);
	while (len)
	{
		if (node->content > ptr->gitf_index)
			i++;
		if (node->content <= ptr->gitf_index)
		{
			while (i)
			{
				ft_ra_move(ptr, 'a');
				i--;
			}
			ft_pb_move(ptr, 'b');
			node = ptr->stack_a;
			if (ptr->stack_b->next)
			{
				if (ptr->stack_b->content < ptr->gits_index)
				{
					if (node->content > ptr->gitf_index)
					{
						ft_rr_move(ptr);
						node = ptr->stack_a;
					}
					else
						ft_rb_move(ptr, 'b');
				}
			}
		}
		else
			node = node->next;
		len--;
	}
	ft_free_stack_temp(ptr);
	return (0);
}
