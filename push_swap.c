/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:06:33 by yismaili          #+#    #+#             */
/*   Updated: 2022/04/05 21:21:57 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_args(char **splited)
{
	check_dup(splited);
	arg_is_int(splited);
}

void	ft_sort(int len, t_data *data)
{
	if (len <= 1)
		exit(1);
	else if (len < 10)
		ft_smoll_sort(data);
	else
	{
		ft_create_temp(data);
		ft_sort_temp(data);
		while (data->stack_a->next != NULL)
		{
			if (len < 300)
				ft_comparet(data);
			if (len >= 300)
				ft_comparet_big(data);
			ft_create_temp(data);
			ft_sort_temp(data);
		}
		ft_free_stack_temp(data);
		ft_push_to_a(data);
	}
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		len;
	char	**splt;

	if (argc <= 1)
		exit (1);
	splt = ft_splited(argv +1);
	check_args(splt);
	ft_create_stack(&data, splt);
	len = ft_len_stack(&data);
	ft_sort(len, &data);
	ft_free_stack_a(&data);
	len = 0;
	while (splt[len])
		free(splt[len++]);
	free(splt);
	return (0);
}
