/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:51:20 by mwane             #+#    #+#             */
/*   Updated: 2021/06/26 19:12:44 by mwane            ###   ########.fr       */
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

int	find_biggest(t_stack_b *stack_b)
{
	int	i;
	int	index;

	index = 0;
	i = 0;
	stack_b->big = -2147483647;
	while (i <= stack_b->top)
	{
		if (stack_b->b_stack[i] > stack_b->big)
		{
			stack_b->big = stack_b->b_stack[i];
			stack_b->biggest = i;
		}
		i++;
	}
	if (stack_b->biggest > stack_b->top / 2)
		return ((stack_b->top - stack_b->biggest) * -1);
	else
		return (stack_b->biggest);
}

int	find_smallest(t_stack_b *stack_b)
{
	int	i;
	int	half;

	i = 0;
	stack_b->min = 2147483647;
	half = stack_b->top / 2;
	while (i <= stack_b->top)
	{
		if (stack_b->b_stack[i] < stack_b->min)
		{
			stack_b->min = stack_b->b_stack[i];
			stack_b->smallest = i;
		}
		i++;
	}
	if (stack_b->smallest > half)
		return ((stack_b->top - stack_b->smallest) * -1);
	else
		return (stack_b->smallest);
}

void	print_stack(t_stack_a *stack_a, t_stack_b *stack_b)
{
	int i;

	i = stack_a->top;
	system("clear");
	printf("A stack :%d | half = %d\n", stack_a->top, stack_a->half);
	while (i >= 0 && stack_a->top != -1)
	{
		if (stack_a->a_stack[i] == stack_a->min)
			printf("\x1B[31m -> \x1B[37m");
		printf("%d\n", stack_a->a_stack[i--]);
	}
	i = stack_b->top;
	printf("B stack : %d\n", stack_b->top);
	while (i >= 0 && stack_b->top != -1)
		printf("%d\n", stack_b->b_stack[i--]);
	usleep(300000);
}

void	low_rotate(int index, t_stack_a *stack_a, t_stack_b *stack_b)
{
	while (stack_b->b_stack[stack_b->top] != stack_b->min)
	{
		if (index < 0)
		{
			rotate_b(stack_b);
			write(1, "rb\n", 3);
		}
		else
		{
			reverse_rotate_b(stack_b);
			write(1, "rrb\n", 4);
		}
	}
	write(1, "pa\n", 3);
	push_a(stack_a, stack_b);
	rotate_a(stack_a);
}

void	high_rotate(int index, t_stack_a *stack_a, t_stack_b *stack_b)
{
	while (stack_b->b_stack[stack_b->top] != stack_b->big)
	{
		if (index < 0)
		{
			rotate_b(stack_b);
			write(1, "rb\n", 3);
		}
		else
		{
			reverse_rotate_b(stack_b);
			write(1, "rrb\n", 4);
		}
	}
	write(1, "pa\n", 3);
	push_a(stack_a, stack_b);
}

int	find_smallest_chunk(t_stack_a *stack_a)
{
	int	i;
	int j;
	int	half;

	i = 0;
	j = stack_a->top;
	stack_a->min = 2147483647;
	stack_a->smallest = 2147483647;
	stack_a->smallest_1 = 2147483647;
	half = stack_a->top / 2;
	while (i <= stack_a->top)
	{
		if (stack_a->a_stack[i] <= stack_a->half)
		{
			if (stack_a->smallest > i)
			{
				stack_a->min = stack_a->a_stack[i];
				stack_a->smallest = i;
			}
		}
		i++;
	}
	while (j >= 0)
	{
		if (stack_a->a_stack[j] <= stack_a->half)
		{
			if (stack_a->smallest_1 >= stack_a->top - j)
			{
				stack_a->min = stack_a->a_stack[j];
				stack_a->smallest_1 = (stack_a->top - j);
			}
		}
		j--;
	}
	if (stack_a->smallest < stack_a->smallest_1)
		return ((stack_a->top - stack_a->smallest) * -1);
	else
		return (stack_a->smallest);
}