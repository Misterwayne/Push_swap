/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 15:05:32 by mwane             #+#    #+#             */
/*   Updated: 2021/04/12 17:06:45 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../checker.h"

void	free_stack(s_stack_a *stack, s_stack_b *stack_b)
{
	free(stack->a_stack);
	free(stack_b->b_stack);
	free(stack);
	free(stack_b);
}

void	*init_stack(unsigned int max)
{
	s_stack_a	*stack;

	stack = (s_stack_a *)malloc(sizeof(s_stack_a));
	if (!(stack))
		return (NULL);
	stack->max = max;
	stack->top = -1;
	stack->a_stack = (int *)malloc(stack->max * sizeof(int));
	if (!(stack->a_stack))
		return (NULL);
	return (stack);
}

int	is_full(s_stack_a *stack)
{
	return (stack->top == (int)stack->max - 1);
}

int	is_full_b(s_stack_b *stack)
{
	return (stack->top == (int)stack->max - 1);
}

int	is_empty(s_stack_a *stack)
{
	return (stack->top == -1);
}

void	push(s_stack_a *stack, int nbr)
{
	if (is_full(stack))
		return ;
	stack->a_stack[++stack->top] = nbr;
}
