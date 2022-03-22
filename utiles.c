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
	len /= 3;
	t_stack *tmp = ptr->temp;
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
	int len;

	len = ptr->len_temp / 3;
	len /= 2;
	t_stack *tmp = ptr->temp;
	while (len)
	{
		ptr->temp = ptr->temp->next;
		len--;
	}
	ptr->gits_index = ptr->temp->content;
	ptr->temp = tmp; 
	return (0);
}

int	get_tree_index(t_data *ptr)
{
	int len;

	len = len_temp(ptr);
	len /= 1.5;
	t_stack *tmp = ptr->temp;
	while (len)
	{
		ptr->temp = ptr->temp->next;
		len --;
	}
	ptr->gittree_index = ptr->temp->content;
	ptr->temp = tmp;
	return (0);
}
int	get_scndtree_index(t_data *ptr)
{
	int len;

	len = ptr->len_temp / 1.5;
	len /= 2;
	t_stack *tmp = ptr->temp;
	while (len)
	{
		ptr->temp = ptr->temp->next;
		len--;
	}
	ptr->gitst_index = ptr->temp->content;
	ptr->temp = tmp; 
	return (0);
}

int	get_scndfor_index(t_data *ptr)
{
	int len;

	len = ptr->len_temp -1;
	len /= 2;
	t_stack *tmp = ptr->temp;
	while (len)
	{
		ptr->temp = ptr->temp->next;
		len--;
	}
	ptr->gitsfor_index = ptr->temp->content;
	ptr->temp = tmp; 
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
	data->stack_b = NULL;
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
