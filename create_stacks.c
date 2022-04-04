/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 21:54:28 by yismaili          #+#    #+#             */
/*   Updated: 2022/03/10 21:54:40 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_create_stack(t_data *data, int argc, char **argv)
{
	int		i;
	t_stack	*nude;
	i = 1;

	data->stack_b = NULL;
	nude = (t_stack*)malloc(sizeof(t_stack));
	if (!nude)
		ft_die("error stack\n");
	data->stack_a = nude;
	while (i < argc)
	{
		nude->content = ft_atoi(argv[i]);
		nude->next = NULL;
		if (i + 1 < argc)
		{
			nude->next = (t_stack*)malloc(sizeof(t_stack));
			if (!nude->next)
				ft_die("error stack\n");
			nude = nude->next;
		}
		i++;
	}
	data->stack_end_a = nude;
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
			if (!nude->next)
				ft_die("error stack\n");
			nude = nude->next;
		}
		data->stack_a = data->stack_a->next;
	}
	data->stack_a = tmp;
}

