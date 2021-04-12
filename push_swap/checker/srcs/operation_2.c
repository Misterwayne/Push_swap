/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 19:50:48 by truepath          #+#    #+#             */
/*   Updated: 2021/04/12 17:11:55 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../header/checker.h"

void	rotate_a(s_stack_a *stack)
{
	int	tmp;
	int	i;

	i = stack->top;
	tmp = stack->a_stack[i];
	while (i > 0)
	{
		stack->a_stack[i] = stack->a_stack[i - 1];
		i--;
	}
	stack->a_stack[0] = tmp;
}

void	rotate_b(s_stack_b *stack)
{
	int	tmp;
	int	i;

	if (stack->top < 1)
		return ;
	i = stack->top;
	tmp = stack->b_stack[i];
	while (i > 0)
	{
		stack->b_stack[i] = stack->b_stack[i - 1];
		i--;
	}
	stack->b_stack[0] = tmp;
}

void	ra_rb(s_stack_a *stack_a, s_stack_b *stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
}

void	reverse_rotate_a(s_stack_a *stack)
{
	int	tmp;
	int	i;

	if (stack->top < 1)
		return ;
	i = 0;
	tmp = stack->a_stack[i];
	while (i < stack->top)
	{
		stack->a_stack[i] = stack->a_stack[i + 1];
		i++;
	}
	stack->a_stack[stack->top] = tmp;
}

void	reverse_rotate_b(s_stack_b *stack)
{
	int	tmp;
	int	i;

	if (stack->top < 1)
		return ;
	i = 0;
	tmp = stack->b_stack[i];
	while (i < stack->top)
	{
		stack->b_stack[i] = stack->b_stack[i + 1];
		i++;
	}
	stack->b_stack[stack->top] = tmp;
}
