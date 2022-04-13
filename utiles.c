/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 20:08:54 by yismaili          #+#    #+#             */
/*   Updated: 2022/04/06 00:22:16 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_temp(t_data *ptr)
{
	int		temp;
	t_stack	*unde;
	int		len;

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

int	len_temp(t_data *ptr)
{
	int		len;
	t_stack	*tmp;

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

void	ft_free_stack_a(t_data *ptr)
{
	t_stack	*node;

	while (ptr->stack_a)
	{
		node = ptr->stack_a->next;
		free(ptr->stack_a);
		ptr->stack_a = node;
	}
}

void	ft_free_stack_temp(t_data *ptr)
{
	t_stack	*node;

	while (ptr->temp)
	{
		node = ptr->temp->next;
		free(ptr->temp);
		ptr->temp = node;
	}
}

long int	ft_atoi(const char *str)
{
	long int	res;
	int			sgn;
	int			i;

	res = 0;
	sgn = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if ((str[i] == '-' || str[i] == '+' ))
	{
		if (str[i] == '-')
			sgn *= -1;
		if (str[i + 1] == '\0')
			ft_die("Error");
		i++;
	}
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			res = (res * 10) + (str[i++] - '0');
		else
			ft_die("Error");
	}
	return (res * sgn);
}
