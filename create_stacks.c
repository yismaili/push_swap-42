/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 21:54:28 by yismaili          #+#    #+#             */
/*   Updated: 2022/04/06 01:39:00 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	emty_str(char *str)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			k++;
		i++;
	}
	if (k == i)
		return (write(2, "Error\n", 6), 0);
	else
		return (1);
}

char	*ft_strjoinn(char *s1, char *s2)
{
	int		i;
	char	*p;
	int		len;

	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!s1 || !s2)
		return (NULL);
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (p == NULL)
		return (NULL);
	while (*s1)
		p[i++] = *s1++;
	while (*s2)
		p[i++] = *s2++;
	p[i] = '\0';
	return (p);
}

char	**ft_splited(char **argv)
{
	char	*num;
	char	*str;
	char	**split;
	int		i;

	i = 0;
	str = malloc(1);
	str[0] = '\0';
	while (argv[i])
	{
		if (emty_str(argv[i]) == 0)
		{
			free(str);
			exit (0);
		}
		num = ft_strjoinn(str, argv[i]);
		free(str);
		str = ft_strjoinn(num, " ");
		free(num);
		i++;
	}
	split = ft_split(str, ' ');
	free(str);
	return (split);
}

void	ft_create_stack(t_data *data, char **splt)
{
	int		i;
	t_stack	*nude;

	i = 0;
	data->stack_b = NULL;
	nude = (t_stack *)malloc(sizeof(t_stack));
	if (!nude)
		ft_die("error stack\n");
	data->stack_a = nude;
	while (splt[i])
	{
		nude->content = ft_atoi(splt[i]);
		nude->next = NULL;
		if (splt[i + 1])
		{
			nude->next = (t_stack *)malloc(sizeof(t_stack));
			if (!nude->next)
				ft_die("error stack\n");
			nude = nude->next;
		}
		i++;
	}
	data->stack_end_a = nude;
}

void	ft_create_temp(t_data *data)
{
	int		i;
	t_stack	*nude;
	t_stack	*tmp;

	i = 1;
	tmp = data->stack_a;
	nude = (t_stack *)malloc(sizeof(t_stack));
	if (!nude)
		ft_die("error stack\n");
	data->temp = nude;
	while (data->stack_a != NULL)
	{
		nude->content = data->stack_a->content;
		nude->next = NULL;
		if (data->stack_a->next != NULL)
		{
			nude->next = (t_stack *)malloc(sizeof(t_stack));
			if (!nude->next)
				ft_die("error stack\n");
			nude = nude->next;
		}
		data->stack_a = data->stack_a->next;
	}
	data->stack_a = tmp;
}
