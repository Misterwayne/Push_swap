/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 16:47:07 by mwane             #+#    #+#             */
/*   Updated: 2021/04/16 16:19:07 by mwane            ###   ########.fr       */
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

	i = -1;
	usleep(50000);
	system("clear");
	if (stack_a != NULL)
	{
		while (++i <= stack_a->top)
		{
			if (stack_a->a_stack[i] == stack_a->min)
				printf("%s-> ", KRED);
			printf("%d%s\n", stack_a->a_stack[i], KWHT);
		}
	}
	i = -1;
	if (stack_b != NULL)
	{
		printf("B top : %d\n", stack_b->top);
		while (++i <= stack_b->top)
			printf("%d\n", stack_b->b_stack[i]);
	}
}
