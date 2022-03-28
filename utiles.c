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
	int len;

	unde = ptr->temp;
	len = ft_len_stack(ptr);
	while (len)
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
		len--;
	}
	ptr->temp = unde;
}
int len_temp(t_data *ptr)
{
	int len;

	len = 0;
	t_stack *tmp = ptr->temp;
	while (ptr->temp != NULL)
	{
		ptr->temp = ptr->temp->next;
		len++;
	}
	ptr->len_temp = len;
	ptr->temp = tmp;
	return (len);
}

int get_frst_index(t_data *ptr)
{
	int len;

	len = len_temp(ptr);
	len /= 5;
	t_stack *tmp = ptr->temp;
	while (len)
	{
		ptr->temp = ptr->temp->next;
		len --;
	}
	ptr->gitf_index = ptr->temp->content;
	ptr->temp = tmp;
	//free(ptr->temp);
	return (0);
}

int	get_scnd_index(t_data *ptr)
{
	int len;

	len = len_temp(ptr) / 5;
	len /= 2;
	t_stack *tmp = ptr->temp;
	while (len)
	{
		ptr->temp = ptr->temp->next;
		len--;
	}
	ptr->gits_index = ptr->temp->content;
	//ptr->temp = tmp; 
	//free(ptr->temp);
	return (0);
}

int ft_len_stack(t_data *ptr)
{
	int len;

	len = 0;
	t_stack *node;
	node = ptr->stack_a;
	while (node != NULL)
	{
		node = node->next;
		len++;
	}
	return (len);
}

void	ft_create_temp(t_data *data)
{
	int		i;
	t_stack	*nude;
	t_stack *tmp;
	i = 1;

	tmp = data->stack_a;
	nude = (t_stack*)malloc(sizeof(t_stack));
	if (!nude)
		ft_die("error stack\n");
	data->temp = nude;
	while (data->stack_a != NULL)
	{
		nude->content = data->stack_a->content;
		nude->next = NULL;
		if (data->stack_a->next != NULL)
		{
			nude->next = (t_stack*)malloc(sizeof(t_stack));
			if (!nude)
				ft_die("error stack\n");
			nude = nude->next;
		}
		data->stack_a = data->stack_a->next;
	}
	data->stack_a = tmp;
}

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
	if(index_max > (count / 2) )
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
			while (ptr->index_max -1 > 0)
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