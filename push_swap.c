/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 17:30:36 by yismaili          #+#    #+#             */
/*   Updated: 2022/03/03 17:52:53 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void printList( t_push *node)
{
    while(node != NULL)
    {
        printf("%d ", node->content);
        node = node->next;
    }
}

int	ft_atoi(const char *str)
{
	int	res;
	int	sgn;
	int	i;

	res = 0;
	sgn = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sgn *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * sgn);
}

int main(int argc, char *argv[])
{
    t_push *start = NULL;

	if (argc < 2)
		ft_die("check");
	argc = 1;
	while (argv[argc])
	{
		ft_lstnew(&start, ft_atoi(argv[argc]));
		argc++;
	}

    printf("\n Linked list before calling swapNodes() \n ");
    printList(start);

    ft_swapnodes(&start, 4, 2);

    printf("\n Linked list after  calling swapNodes() \n ");
    printList(start);

    return 0;
}