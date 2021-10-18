/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 19:50:48 by truepath          #+#    #+#             */
/*   Updated: 2021/10/16 09:39:16 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/checker.h"


int*	reset_strign(t_stack_a *stack, int *model)
{
	int	tmp;
	int	i;

	i = stack->top;
	tmp = model[i];
	while (model[stack->top] != stack->min)
	{
		i = stack->top;
		tmp = model[i];
		while (i > 0)
		{
			model[i] = model[i - 1];
			i--;
		}
		model[0] = tmp;
	}
	return (model);
}


void	rotate_a(t_stack_a *stack, int mode)
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
	if (mode == 0)
		write(1, "ra\n", 3);
}

void	rotate_b(t_stack_b *stack, int mode)
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
	if (mode == 0)
		write(1, "rb\n", 3);
}

void	ra_rb(t_stack_a *stack_a, t_stack_b *stack_b)
{
	rotate_a(stack_a, 1);
	rotate_b(stack_b, 1);
	write(1, "rr\n", 3);
}

void	reverse_rotate_a(t_stack_a *stack, int mode)
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
	if (mode == 0)
		write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_stack_b *stack, int mode)
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
	if (mode == 0)
		write(1, "rrb\n", 4);
}
