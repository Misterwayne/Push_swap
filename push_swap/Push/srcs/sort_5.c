/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 21:35:19 by mwane             #+#    #+#             */
/*   Updated: 2021/09/27 16:06:54 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/checker.h"

int	find_smallest_a(t_stack_a *stack_a);

void	sort_5(t_stack_a *stack_a, t_stack_b *stack_b)
{
	int min;


	while (stack_b->top < 1)
	{
		min = find_smallest_a(stack_a);
		low_rotate(min, stack_a, stack_b);
	}
	min = smallest(stack_a);
	if (stack_a->a_stack[stack_a->top] == min)
		case_1(stack_a);
	else if (stack_a->a_stack[stack_a->top - 1] == min)
		case_2(stack_a);
	else if (stack_a->a_stack[0] == min)
		case_3(stack_a);
	push_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
	return ;
}

int	find_smallest_a(t_stack_a *stack_a)
{
	int	i;
	int	half;

	i = 0;
	stack_a->min = 2147483647;
	half = stack_a->top / 2;
	while (i <= stack_a->top)
	{
		if (stack_a->a_stack[i] < stack_a->min)
		{
			stack_a->min = stack_a->a_stack[i];
			stack_a->smallest = i;
		}
		i++;
	}
	if (stack_a->smallest > half)
		return ((stack_a->top - stack_a->smallest) * -1);
	else
		return (stack_a->smallest);
}

void	low_rotate_b(int index, t_stack_a *stack_a, t_stack_b *stack_b)
{
	while (stack_b->b_stack[stack_b->top] != stack_b->min)
	{
		if (index < 0)
			rotate_b(stack_b);
		else
			reverse_rotate_b(stack_b);
	}
	push_a(stack_a, stack_b);
	rotate_a(stack_a);
}
