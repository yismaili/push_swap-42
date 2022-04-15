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

int	check_dup( char **number)
{
	int	j;
	int	i;

	i = 1;
	while (number[i])
	{
		j = i + 1;
		while (number[j])
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

int	check_max_min(char *number, char *max, char *min)
{
	char	*num;

	if (ft_strlen(number) >= 10)
	{
		if (number[0] == '-' && ft_strlen(number) >= 11)
		{
			num = ft_itoa(ft_atoi(number));
			if (ft_strncmp(num, number, ft_strlen(min)))
				return (1);
		}
		if (number[0] == '+' && ft_strlen(number) >= 11)
		{
			num = ft_itoa(ft_atoi(number));
			if (ft_strncmp(num, &number[1], 11))
				return (1);
		}
		else if (ft_strlen(number) >= 10)
		{
			num = ft_itoa(ft_atoi(number));
			if (ft_strncmp(num, number, ft_strlen(max)))
				return (1);
		}
		free(num);
	}
	return (0);
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

void	arg_is_int(char **splited)
{
	int	i;

	i = 0;
	if (splited[0] == '\0')
		exit(1);
	while (splited[i])
	{
		if (check_max_min(splited[i], "2147483647", "-2147483648"))
			ft_die("Error");
		i++;
	}
}
