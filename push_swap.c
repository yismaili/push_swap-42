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
			if (!nude)
				ft_die("error stack\n");
			nude = nude->next;
		}
		i++;
	}
	data->stack_end_a = nude;
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
	get_frst_index(&data);
	get_scnd_index(&data);
	get_tree_index(&data);
	get_scndtree_index(&data);
	//get_scndfor_index(&data);
	// printf("first %d\n", data.gitf_index);
	// printf("second %d\n",data.gits_index);
	// printf("tree %d\n",data.gittree_index);
	// printf("second tree %d\n",data.gitst_index);
	// //printf("for tree %d\n",data.gitsfor_index);

	ft_comparet(&data); 
	ft_comparet_tow(&data);
	ft_comparet_for(&data);
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
