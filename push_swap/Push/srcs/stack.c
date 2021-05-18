/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 16:47:07 by mwane             #+#    #+#             */
/*   Updated: 2021/05/18 17:28:57 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/checker.h"

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

void	free_stack(t_stack_a *stack, t_stack_b *stack_b)
{
	free(stack->a_stack);
	free(stack_b->b_stack);
	free(stack);
	free(stack_b);
}

void	b_push(t_stack_b *stack, int nbr)
{
	if (is_full_b(stack))
		return ;
	stack->b_stack[++stack->top] = nbr;
}

int		pop_b(t_stack_b *stack)
{
	if (is_empty((t_stack_a *)stack))
		return (0);
	return (stack->b_stack[stack->top--]);
}

int		pop(t_stack_a *stack)
{
	if (is_empty(stack))
		return (0);
	return (stack->a_stack[stack->top--]);
}

int		find_biggest_b(t_stack_b *stack)
{
	int i;

	i = 0;
	stack->big = -2147483648;
	while (i <= stack->top)
	{
		if (stack->b_stack[i] > stack->big)
		{
			stack->big = stack->b_stack[i];
			stack->biggest = i;
		}
		i++;
	}
	if (stack->biggest > stack->top / 2)
		return (stack->biggest * -1);
	else
		return (stack->biggest);
}
