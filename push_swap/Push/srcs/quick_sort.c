/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:51:20 by mwane             #+#    #+#             */
/*   Updated: 2021/05/18 17:26:56 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/checker.h"

int		find_biggest(t_stack_a *stack)
{
	int i;
	int index;

	index = 0;
	i = 0;
	stack->big = -2147483647;
	while (i <= stack->top)
	{
		if (stack->a_stack[i] > stack->big)
		{
			stack->big = stack->a_stack[i];
			stack->biggest = i;
		}
		i++;
	}
	if (stack->biggest > stack->top / 2)
		return ((stack->top - stack->biggest) * -1);
	else
		return (stack->biggest);
}

int		find_smallest(t_stack_a *stack)
{
	int i;
	int	half;

	i = 0;
	stack->min = 2147483647;
	half = stack->top / 2;
	while (i <= stack->top)
	{
		if (stack->a_stack[i] < stack->min)
		{
			stack->min = stack->a_stack[i];
			stack->smallest = i;
		}
		i++;
	}
	if (stack->smallest > half)
		return ((stack->top - stack->smallest) * -1);
	else
		return (stack->smallest);
}
