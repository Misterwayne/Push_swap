/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 15:05:32 by mwane             #+#    #+#             */
/*   Updated: 2021/06/04 17:33:11 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/checker.h"

void	*init_stack(unsigned int max)
{
	t_stack_a	*stack;

	stack = (t_stack_a *)malloc(sizeof(t_stack_a));
	if (!(stack))
		return (NULL);
	stack->max = max;
	stack->top = -1;
	stack->a_stack = (int *)malloc(stack->max * sizeof(int));
	if (!(stack->a_stack))
		return (NULL);
	return (stack);
}

int	is_full(t_stack_a *stack)
{
	return (stack->top == (int)stack->max - 1);
}

int	is_full_b(t_stack_b *stack)
{
	return (stack->top == (int)stack->max - 1);
}

int	is_empty(t_stack_a *stack)
{
	return (stack->top == -1);
}

void	push(t_stack_a *stack, int nbr)
{
	if (is_full(stack))
		return ;
	stack->a_stack[++stack->top] = nbr;
}
