/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 03:12:03 by yismaili          #+#    #+#             */
/*   Updated: 2022/04/05 20:43:44 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_dup( char **number, int len)
{
	int	j;
	int	i;

	i = 1;
	while (i < len)
	{
		j = i + 1;
		while (j <= len)
		{
			if (ft_atoi(number[i]) == ft_atoi(number[j]))
			{
				write(1, "Error\n", 6);
				exit (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	check_max_min(char **number, int len)
{
	int	i;

	i = 0;
	while (i <= len)
	{
		if (ft_atoi(number[i]) > MAX_INT || ft_atoi(number[i]) < MIN_INT)
		{
			write(1, "Error\n", 6);
			exit (1);
		}
		i++;
	}
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] && i < n)
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i ++;
	}
	if (s2[i] == '\0' || i == n)
		return (0);
	else
		return (-s2[i]);
}
