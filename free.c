/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 01:12:03 by yismaili          #+#    #+#             */
/*   Updated: 2022/04/06 01:30:02 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s || *s == '\0' || fd < 0)
		return ;
	write(fd, s, ft_strlen(s));
}

void	ft_die(char *str)
{
	ft_putstr_fd(str, 1);
	exit(1);
}

size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

long int	ft_atoi_tow(const char *str)
{
	long int	res;
	int			i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			res = (res * 10) + (str[i] - '0');
			i++;
		}
		else
			ft_die("Error");
	}
	return (res);
}
