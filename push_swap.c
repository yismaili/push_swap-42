/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 17:30:36 by yismaili          #+#    #+#             */
/*   Updated: 2022/03/03 17:52:53 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_print(int n)
{
    printf("%d\n", n);
}
void	ft_lstiter(t_push *lst, void (*f)(int))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
int	ft_atoi(const char *str)
{
	int	res;
	int	sgn;
	int	i;

	res = 0;
	sgn = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sgn *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * sgn);
}

int main(int argc, char *argv[])
{
     t_push *n1 = NULL;
      t_push *n2 = NULL;
       t_push *n3 = NULL;
        t_push *n4 = NULL;
        t_push *n5 = NULL;

     n1 = ft_lstnew(10);
    n2 = ft_lstnew(20);
    n3 = ft_lstnew(30);
    n4 = ft_lstnew(40);
    n5 = ft_lstnew(50);
   // int i = 0;
   // while (argv[i])
   // {
    // n1[i] = *ft_lstnew(ft_atoi(argv[i]));
     //ft_addback(&n1[i -1],&n1[i]);
    // i++;
   // }
 ft_addback(&n1,n2);
    ft_addback(&n2,n3);
    ft_addback(&n3,n4);
    ft_addback(&n4,n5);

     ft_lstiter(n1,ft_print);

     return 0;
}
