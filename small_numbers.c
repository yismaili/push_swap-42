/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:36:57 by yismaili          #+#    #+#             */
/*   Updated: 2022/03/11 16:37:04 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_smoll_nbr(t_data *ptr)
{
    int stk_a;
    int stk_nxt_a;
    int stk_end_a;

    stk_a = ptr->stack_a->content;
    stk_end_a = ptr->stack_end_a->content;
    stk_nxt_a = ptr->stack_a->next->content;
    if (stk_a > stk_nxt_a && stk_a < stk_end_a && stk_nxt_a < stk_end_a)
        ft_sa_move(ptr);
   else if (stk_a > stk_nxt_a && stk_a > stk_end_a && stk_nxt_a > stk_end_a)
    {
        ft_sa_move(ptr);
        ft_rra_move(ptr);
    }
   else if (stk_a > stk_nxt_a && stk_a > stk_end_a && stk_nxt_a < stk_end_a)
        ft_ra_move(ptr);
    else if (stk_a > stk_nxt_a && stk_a > stk_end_a && stk_nxt_a < stk_end_a)
    {
        ft_sa_move(ptr);
        ft_ra_move(ptr);
    }
    else if (stk_a < stk_nxt_a && stk_a > stk_end_a && stk_nxt_a > stk_end_a)
        ft_rra_move(ptr);
    else if (stk_a > stk_end_a)
        ft_rra_move(ptr);
    return (0);
}