/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 01:12:03 by yismaili          #+#    #+#             */
/*   Updated: 2022/04/06 01:30:02 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s || *s == '\0' || fd < 0)
		return ;
	write(fd, s, ft_strlen(s));
}

void	ft_die(char *str)
{
	ft_putstr_fd(str, 1);
	exit(1);
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
