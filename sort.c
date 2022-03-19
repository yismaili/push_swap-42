/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:21:34 by yismaili          #+#    #+#             */
/*   Updated: 2022/03/16 18:21:46 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_sort(t_data *ptr)
{
	if (ptr->stack_a->next == NULL)
		return (0);
	while (check_sorted(ptr->stack_a, 0) != 0 || ptr->stack_b == NULL)
	{
		ptr->min_getf = ft_get_min(ptr);
		if (ptr->min == ptr->stack_a->next->content)
			ft_ra_move(ptr);
		 else
		 {
			while (ptr->index_min -1 > 0)
			{
				if (ptr->min_getf == -1)
					ft_ra_move(ptr) ;
				else
					ft_rra_move(ptr);
				ptr->index_min--;
			 }
		}
		if (check_sorted(ptr->stack_a, 0) == 0 && ptr->stack_b == NULL)
			break ;
		if (ptr->stack_b != NULL && check_sorted(ptr->stack_a, 0) == 0 && check_sorted(ptr->stack_b, 1) == 0)
			break ;
		ft_pb_move(ptr);
	}
	while (ptr->stack_b != NULL)
		ft_pa_move(ptr);
	return (0);
}
