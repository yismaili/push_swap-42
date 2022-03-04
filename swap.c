/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 21:07:34 by yismaili          #+#    #+#             */
/*   Updated: 2022/03/03 21:10:40 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_swap( t_push **first, t_push **second )
{
     t_push	 *tmp = *first;
    *first = *second;
    *second = tmp;
}

void	ft_die(char *str)
{
	perror(str);
	exit(1);
}
void ft_swapnodes(t_push **headr, int key1, int key2 )
{
    if ( key1 == key2 )
        return;

    t_push **first = headr;

    while ( *first && ( *first )->content != key1 ) 
            first = &( *first )->next;

    if ( *first == NULL ) 
        return;

   t_push **second = headr;

    while ( *second && ( *second )->content != key2 ) 
        second = &( *second )->next;

    if ( *second == NULL ) return;

    ft_swap( first, second );
    ft_swap( &( *first )->next, &( *second )->next );
}