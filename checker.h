/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 00:01:38 by yismaili          #+#    #+#             */
/*   Updated: 2022/04/06 00:50:24 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			chech_instruction(char *instr, t_data *ptr);
int			ft_sorted(t_data *ptr, int size);
void		ft_ok_ko(t_data *ptr, int size);

#endif
