/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:29:31 by yismaili          #+#    #+#             */
/*   Updated: 2022/04/05 20:49:25 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_args(char **splited)
{
	check_dup(splited);
	arg_is_int(splited);
}

int	chech_instruction(char *instr, t_data *ptr)
{
	if (!ft_strncmp(instr, "sa\n", 3))
		ft_sa_move(ptr, 's');
	else if (!ft_strncmp(instr, "sb\n", 3))
		ft_sb_move(ptr, 's');
	else if (!ft_strncmp(instr, "ss\n", 3))
		ft_ss_move(ptr);
	else if (!ft_strncmp(instr, "pa\n", 3))
		ft_pa_move(ptr, 's');
	else if (!ft_strncmp(instr, "pb\n", 3))
		ft_pb_move(ptr, 's');
	else if (!ft_strncmp(instr, "ra\n", 3))
		ft_ra_move(ptr, 's');
	else if (!ft_strncmp(instr, "rb\n", 3))
		ft_rb_move(ptr, 's');
	else if (!ft_strncmp(instr, "rr\n", 3))
		ft_rr_move(ptr);
	else if (!ft_strncmp(instr, "rra\n", 3))
		ft_rra_move(ptr, 's');
	else if (!ft_strncmp(instr, "rrb\n", 3))
		ft_rrb_move(ptr, 's');
	else if (!ft_strncmp(instr, "rrr\n", 3))
		ft_rrr_move(ptr);
	else
		write(2, "Error\n", 6);
	return (0);
}

int	ft_sorted(t_data *ptr, int size)
{
	t_stack	*node;
	int		i;

	i = ft_len_stack(ptr);
	if (size != i)
		return (1);
	node = ptr->stack_a;
	while (node && node->next && node->content < node->next->content)
	{
		i--;
		node = node->next;
	}
	if (i == 1)
		return (0);
	else
		return (1);
}

void	ft_ok_ko(t_data *ptr, int size)
{
	if (!ft_sorted(ptr, size))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_data	data;
	char	*buf;
	char	**splt;
	int		len;

	if (argc <= 1)
		exit (1);
	splt = ft_splited(argv +1);
	check_args(splt);
	ft_create_stack(&data, splt);
	len = ft_len_stack(&data);
	buf = get_next_line(0);
	while (buf != NULL)
	{
		chech_instruction(buf, &data);
		free(buf);
		buf = get_next_line(0);
	}
	ft_ok_ko(&data, len);
	ft_free_stack_a(&data);
	len = 0;
	while (splt[len])
		free(splt[len++]);
	free(splt);
	return (0);
}
