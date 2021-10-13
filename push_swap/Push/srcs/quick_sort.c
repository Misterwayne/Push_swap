/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:51:20 by mwane             #+#    #+#             */
/*   Updated: 2021/10/08 20:20:21 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/checker.h"

char	**free_tab(char **res, int i)
{
	int	j;

	j = 0;
	while (j <= i)
		free(res[j++]);
	free(res);
	return (NULL);
}

void	find_biggest(t_stack_a *stack_a)
{
	int	i;
	int	index;

	index = 0;
	i = 0;
	stack_a->biggest = -2147483647;
	while (i <= stack_a->top)
	{
		if (stack_a->a_stack[i] > stack_a->biggest)
			stack_a->biggest = stack_a->a_stack[i];
		i++;
	}
}

void	find_smallest(t_stack_a *stack_a)
{
	int	i;

	i = 0;
	stack_a->min = 2147483647;
	while (i <= stack_a->top)
	{
		if (stack_a->a_stack[i] < stack_a->min)
			stack_a->min = stack_a->a_stack[i];
		i++;
	}
	if (i >= stack_a->top / 2)
		stack_a->dir = 1;
	else
		stack_a->dir = 0;
}

void	print_stack(t_stack_a *stack_a, t_stack_b *stack_b)
{
	int	i;

	i = stack_a->top;
	// system("clear");
	printf("CHOISI %d = current | %d = place |%d = nb action dir : %d\n", stack_b->place, stack_a->up_place, stack_b->action, stack_b->dir);
	printf("A stack :%d\n | to place = %d\n", stack_a->top, stack_a->up_place);
	while (i >= 0 && stack_a->top != -1)
	{
		// if (stack_a->a_stack[i] == stack_a->min)
		// 	printf("\x1B[31m -> \x1B[37m");
		printf("%d\n", stack_a->a_stack[i--]);
	}
	i = stack_b->top;
	printf("B stack : %d\n | to place = %d\n", stack_b->top, stack_b->place);
	while (i >= 0 && stack_b->top != -1)
		printf("%d\n", stack_b->b_stack[i--]);
	// printf("min action b = %d, min action a = %d, dir stack_a = %d, dir stack_b = %d\n", stack_b->min, stack_a->min, stack_a->dir, stack_b->dir);
	usleep(50000);
}

void	low_rotate(int index, t_stack_a *stack_a, t_stack_b *stack_b)
{
	while (stack_a->a_stack[stack_a->top] != stack_a->min)
	{
		if (index < 0)
			rotate_a(stack_a, 0);
		else
			reverse_rotate_a(stack_a, 0);
	}
	push_b(stack_b, stack_a);
	rotate_a(stack_a, 0);
}
