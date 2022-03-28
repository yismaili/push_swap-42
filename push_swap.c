/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:06:33 by yismaili          #+#    #+#             */
/*   Updated: 2022/03/10 16:07:35 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_die(char *str)
{
	perror(str);
	exit(1);
}

int main(int argc, char **argv)
{
	t_data	data;

	if (argc == 1)
		return (0);
	ft_create_stack(&data, argc, argv);
	t_stack *ptr, *bptr;
	//ft_smoll_sort(&data);
	
	ft_create_temp(&data);
	ft_sort_temp(&data); 
    while (data.stack_a->next != NULL)
    {
	ft_comparet(&data);
 	ft_create_temp(&data);
 	ft_sort_temp(&data);
    }
	
	ft_push_to_a(&data);
	ptr = data.stack_a;
	bptr = data.stack_b;
	// printf("\n------------- stack a ---------------\n");
	// while(ptr)
	// {
	// 	printf("%d\n",ptr->content);
	// 	ptr = ptr->next;
	// }
	// printf("\n--------- move to stack b -----------\n");
	// while(bptr)
	// {
	// 	printf("%d\n",bptr->content);
	// 	bptr = bptr->next;
	// }
	return (0);
}
