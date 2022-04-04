/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 03:12:03 by yismaili          #+#    #+#             */
/*   Updated: 2022/03/28 03:12:13 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_dup( char **number, int len)
{
    int j;
    int i;

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
