/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truepath <truepath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 16:47:07 by mwane             #+#    #+#             */
/*   Updated: 2021/05/12 22:38:08 by truepath         ###   ########.fr       */
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

void	print_stack(t_stack_a *stack_a, t_stack_b *stack_b)
{
	int	i;

	i = stack_a->top + 1;
	usleep(10000);
	system("clear");
	if (stack_a != NULL)
	{
		printf("A top : %d | key = %d\n", stack_a->top, stack_a->key);
		while (--i > -1)
		{
			if (absolute_v(stack_a->biggest) < absolute_v(stack_a->smallest))
			{
				if (stack_a->a_stack[i] == stack_a->big)
					printf("%s-> ", KRED);
			}
			if (stack_a->a_stack[i] == stack_a->min)
					printf("%s-> ", KBLU);
			printf("%d%s\n", stack_a->a_stack[i], KWHT);
		}
	}
	i = stack_b->top + 1;
	if (stack_b != NULL)
	{
		printf("B top : %d\n", stack_b->top);
		while (--i > -1)
		{
			if (absolute_v(stack_b->biggest) < absolute_v(stack_b->smallest))
			{
				if (stack_b->b_stack[i] == stack_b->big)
					printf("%s-> ", KRED);
			}	
			else
			{
				if (stack_b->b_stack[i] == stack_b->min)
					printf("%s-> ", KBLU);
			}
			printf("%d%s\n", stack_b->b_stack[i], KWHT);
		}
	}
}
