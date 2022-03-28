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
	int		len;
	t_stack *tmp;

	len = 0;
	tmp = ptr->temp;
	while (ptr->temp != NULL)
	{
		ptr->temp = ptr->temp->next;
		len++;
	}
	ptr->len_temp = len;
	ptr->temp = tmp;
	return (len);
}
