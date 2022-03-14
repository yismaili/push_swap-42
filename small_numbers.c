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
    if (stk_a > stk_nxt_a && stk_a > stk_end_a && stk_nxt_a > stk_end_a)
    {
        ft_sa_move(ptr);
        ft_rra_move(ptr);
    }
    else if (stk_a < stk_nxt_a && stk_a < stk_end_a && stk_nxt_a > stk_end_a)
    {
        ft_sa_move(ptr);
        ft_ra_move(ptr);
    }
   else if (stk_a > stk_nxt_a && stk_a < stk_end_a && stk_nxt_a < stk_end_a)
        ft_sa_move(ptr);
   else if (stk_a > stk_nxt_a && stk_a > stk_end_a && stk_nxt_a < stk_end_a)
        ft_ra_move(ptr);
    else if (stk_a < stk_nxt_a && stk_a > stk_end_a && stk_nxt_a > stk_end_a)
        ft_rra_move(ptr);
    else if (stk_a > stk_end_a)
        ft_rra_move(ptr);
    return (0);
}

// int ft_len_stack(t_data *ptr)
// {
//     int len;
//     t_stack *data;

//     len = 0;
//     while (ptr->stack_a != NULL)
//     {
//         len++;
//         ptr->stack_a = data->next;
//     }
//     return (len);
// }
void ft_push_tob(t_data *ptr)
{
   while (ptr->len_stack_a > 3)
    {
        ft_pb_move(ptr);
       ptr->len_stack_a--;
    }
}

void ft_sort_nbr(t_data *ptr)
{
    t_stack *temp = ptr->stack_a;
     ft_smoll_nbr(ptr);
     ft_pa_move(ptr);
    //ptr->len_stack_a++;
   if (ptr->stack_a->content > ptr->stack_end_a->content)
   {
        ft_ra_move(ptr);
   }
   if (ptr->stack_a->content > temp->content && ptr->stack_a->content < temp->next->content)
   {
       ft_sa_move(ptr);
   }
    // while (ptr->stack_a)
    // {

    //     if (ptr->stack_a->content > ptr->stack_a->next->content)
    //     {
    //         ft_sa_move(ptr);
    //     }
    //     ptr->stack_a = ptr->stack_a->next;
    //     printf("%d",i);
    // } 
}