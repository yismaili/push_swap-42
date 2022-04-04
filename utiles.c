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

void ft_free_stack_a(t_data *ptr)
{
	while(ptr->stack_a)
	{
		t_stack *node;
		
		node = ptr->stack_a->next;
		free(ptr->stack_a);
		ptr->stack_a = node;
	}
}
void ft_free_stack_temp(t_data *ptr)
{
	while(ptr->temp)
	{
		t_stack *node;
		
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
		{
				write(1, "Error\n", 6);
			     exit (1);
		}
		i++;
	}
	while (str[i])
	{
		if  (str[i] >= '0' && str[i] <= '9')
		{
			res = (res * 10) + (str[i] - '0');
			i++;
		}
		else
		{
			write(1, "Error\n", 6);
			exit (1);
		}
	}
	return (res * sgn);
}

size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s || *s == '\0' || fd < 0)
		return ;
	write(fd, s, ft_strlen(s));
}