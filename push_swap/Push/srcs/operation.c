/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 17:24:26 by mwane             #+#    #+#             */
/*   Updated: 2021/09/27 16:07:55 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/checker.h"

void	swap_a(t_stack_a *stack)
{
	int	tmp;

	if (stack->top < 1)
		return ;
	tmp = stack->a_stack[stack->top];
	stack->a_stack[stack->top] = stack->a_stack[stack->top - 1];
	stack->a_stack[stack->top - 1] = tmp;
	write(1, "sa\n", 3);
}

void	swap_b(t_stack_b *stack)
{
	int	tmp;

	if (stack->top < 1)
		return ;
	tmp = stack->b_stack[stack->top];
	stack->b_stack[stack->top] = stack->b_stack[stack->top - 1];
	stack->b_stack[stack->top - 1] = tmp;
	write(1, "sa\n", 3);
}

void	sa_sb(t_stack_a *stack_a, t_stack_b *stack_b)
{
	if (stack_a->top == -1)
		return ;
	if (stack_b->top == -1)
		return ;
	swap_a(stack_a);
	swap_b(stack_b);
	write(1, "sa_sb\n", 6);
}

void	push_a(t_stack_a *stack_a, t_stack_b *stack_b)
{
	if (stack_b->top == -1)
		return ;
	push(stack_a, stack_b->b_stack[stack_b->top]);
	pop_b(stack_b);
	write(1, "pa\n", 3);
}

void	push_b(t_stack_b *stack_b, t_stack_a *stack_a)
{
	if (stack_a->top == -1)
		return ;
	b_push(stack_b, stack_a->a_stack[stack_a->top]);
	pop(stack_a);
	write(1, "pb\n", 3);
}
