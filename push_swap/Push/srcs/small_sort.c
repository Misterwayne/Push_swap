/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 17:56:29 by mwane             #+#    #+#             */
/*   Updated: 2021/09/27 16:08:41 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/checker.h"

void	case_1(t_stack_a *stack_a)
{
	if ((stack_a->a_stack[stack_a->top - 1] > stack_a->a_stack[0]))
	{
		rotate_a(stack_a);
		swap_a(stack_a);
		reverse_rotate_a(stack_a);
	}	
}

void	case_2(t_stack_a *stack_a)
{
	if (stack_a->a_stack[stack_a->top] > stack_a->a_stack[0])
	{
		rotate_a(stack_a);
		if (stack_a->a_stack[stack_a->top] > stack_a->a_stack[stack_a->top - 1])
			swap_a(stack_a);
	}
	else
	{
		reverse_rotate_a(stack_a);
		swap_a(stack_a);
		reverse_rotate_a(stack_a);
	}	
}

void	case_3(t_stack_a *stack_a)
{
	if (stack_a->a_stack[stack_a->top] > stack_a->a_stack[stack_a->top - 1])
	{
		swap_a(stack_a);
	}
	reverse_rotate_a(stack_a);	
}

int	smallest(t_stack_a *stack_a)
{
	int i;
	int min;
	
	min = INT16_MAX;
	i = 0;
	while (i <= stack_a->top)
	{
		if (stack_a->a_stack[i] < min)
			min = stack_a->a_stack[i];
		i++;
	}
	return (min);
}

void	sort_3(t_stack_a *stack_a)
{
	int min;

	min = smallest(stack_a);
	if (stack_a->a_stack[stack_a->top] == min)
		case_1(stack_a);
	else if (stack_a->a_stack[stack_a->top - 1] == min)
		case_2(stack_a);
	else if (stack_a->a_stack[0] == min)
		case_3(stack_a);
	stack_a->smallest = stack_a->a_stack[stack_a->top];
	stack_a->biggest = stack_a->a_stack[0];
}
