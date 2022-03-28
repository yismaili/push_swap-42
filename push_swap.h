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
#include "libft/libft.h"
# define MAX_INT 2147483647
# define MIN_INT -2147483647

typedef struct	s_stack
{
	int				content;
	struct s_stack	*next;
}	t_stack;

typedef struct	s_data
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*stack_end_a;
	t_stack	*stack_end_b;
	t_stack	*temp;
	int		min;
	int		max;
	int		index_min;
	int		index_max;
	int		min_getf;
	int		gitf_index;
	int		gits_index;
	int		mx;
	int		len_temp;
	// int		git1;
	// int 	git_s_1;
	// int		git2;
	// int 	git_s_2;
	// int		git3;
	// int 	git_s_3;
	// int		git4;
	// int 	git_s_4;
	// int		git5;
	// int 	git_s_5;
}	t_data;

void	ft_create_stack(t_data *e, int argc, char **argv);
void	ft_die(char *str);
int		ft_sa_move(t_data *ptr);
int 	ft_sb_move(t_data *ptr);
int		ft_rra_move(t_data *ptr);
int		ft_rrb_move(t_data *ptr);
int 	ft_pa_move(t_data *ptr);
int 	ft_pb_move(t_data *ptr);
int		ft_ra_move(t_data *ptr);
int		ft_rb_move(t_data *ptr);
int		ft_smoll_two(t_data *ptr);
int		ft_get_min(t_data *ptr);
int		check_sorted(t_stack *stack, int mode);
int		ft_smoll_sort(t_data *ptr);
int		ft_len_stack(t_data *ptr);
void 	ft_sort_temp(t_data *ptr);
int		len_temp(t_data *ptr);
int 	get_frst_index(t_data *ptr);
int		get_scnd_index(t_data *ptr);
int		ft_comparet(t_data *ptr);
void	ft_create_temp(t_data *data);
int		ft_get_max(t_data *ptr);
int		check(t_stack *stack, int mode);
int		ft_push_to_a(t_data *ptr);
/******************/
// int get_1(t_data *ptr);
// int	get_s_1(t_data *ptr);
// int get_2(t_data *ptr);
// int	get_s_2(t_data *ptr);
// int get_3(t_data *ptr);
// int	get_s_3(t_data *ptr);
// int get_4(t_data *ptr);
// int	get_s_4(t_data *ptr);
// int get_5(t_data *ptr);
// int	get_s_5(t_data *ptr);
// int ft_comparet_1(t_data *ptr);
// int ft_comparet_2(t_data *ptr);
// int ft_comparet_3(t_data *ptr);
// int ft_comparet_4(t_data *ptr);
// int ft_comparet_5(t_data *ptr);

#endif