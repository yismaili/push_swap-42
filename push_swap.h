/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:19:49 by yismaili          #+#    #+#             */
/*   Updated: 2022/03/03 18:23:21 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_push
{
    int           content;
    struct s_push   *next;
    struct s_push   *prev;
}   t_push;

void    ft_addback(t_push **lst, t_push *newlst);
void    ft_addfront(t_push **lst, t_push *newlst);
t_push  *ft_lstlast(t_push *lst);
void printList( t_push *node);
void ft_lstnew(t_push ** head_ref, int new_data);
void ft_swap( t_push **first, t_push **second );
void ft_swapnodes(t_push **headr, int key1, int key2 );
void	ft_die(char *str);
void ft_sa(t_push **head);
void printList( t_push *node);
int	ft_atoi(const char *str);

#endif
