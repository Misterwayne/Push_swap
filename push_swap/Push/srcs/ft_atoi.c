/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 10:08:35 by mwane             #+#    #+#             */
/*   Updated: 2021/07/13 18:58:04 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../header/checker.h"

long	ft_atoi(char *nbr)
{
	long	nb;
	int		i;
	int		nega;
	int		m;

	nb = 0;
	i = 0;
	nega = -1;
	m = 1;
	while (nbr[i] == '\t' || nbr[i] == '\n' || nbr[i] == ' '
		|| nbr[i] == '\f' || nbr[i] == '\r' || nbr[i] == '\v')
		nbr++;
	if (nbr[i] == '+' || nbr[i] == '-')
	{
		nega += (nbr[i] - 44) + 1;
		i++;
	}
	while (nbr[i] && nbr[i] <= '9' && nbr[i] >= '0')
		i++;
	while (i > 0 && nbr[--i] <= '9' && nbr[i] >= '0')
	{
		nb += (nbr[i] - '0') * m;
		m *= 10;
	}
	return (-nb * nega);
}

int     rotate_opti(t_stack_a *stack_a)
{
    int index;
    int index2;
    int i;

    index = 0;
    index2 = 0;
    i = 0;
    while (index == 0)
    {
        if (stack_a->a_stack[i] <= stack_a->half)
            index = i;
        i++;
    }
    i = stack_a->top;
    while (index2 == 0)
    {
        if (stack_a->a_stack[i] <= stack_a->half)
            index2 = i;
        i--;
    }
    if (index > index2)
        return (1);
    else 
        return (0);
}
