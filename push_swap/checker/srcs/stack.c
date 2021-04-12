/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 16:47:07 by mwane             #+#    #+#             */
/*   Updated: 2021/04/12 15:07:27 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	b_push(s_stack_b *stack, int nbr)
{
	if (is_full_b(stack))
		return ;
	stack->b_stack[++stack->top] = nbr;
}

int	pop_b(s_stack_b *stack)
{
	if (is_empty((s_stack_a *)stack))
		return (0);
	return (stack->b_stack[stack->top--]);
}

int	pop(s_stack_a *stack)
{
	if (is_empty(stack))
		return (0);
	return (stack->a_stack[stack->top--]);
}

void	print_stack(s_stack_a *stack_a, s_stack_b *stack_b)
{
	int	i;

	i = 0;
	if (stack_a != NULL)
	{
		printf("A top : %d\n", stack_a->top);
		while (i <= stack_a->top)
			printf("%d\n", stack_a->a_stack[i++]);
	}
	i = 0;
	if (stack_b != NULL)
	{
		printf("B top : %d\n", stack_b->top);
		while (i <= stack_b->top)
			printf("%d\n", stack_b->b_stack[i++]);
	}
}
