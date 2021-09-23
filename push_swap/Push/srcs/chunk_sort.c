/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 16:57:33 by mwane             #+#    #+#             */
/*   Updated: 2021/07/15 21:45:42 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/checker.h"

// void	high_rotate(int index, t_stack_a *stack_a, t_stack_b *stack_b)
// {
// 	while (stack_b->b_stack[stack_b->top] != stack_b->big)
// 	{
// 		if (index < 0)
// 		{
// 			rotate_b(stack_b);
// 			write(1, "rb\n", 3);
// 		}
// 		else
// 		{
// 			reverse_rotate_b(stack_b);
// 			write(1, "rrb\n", 4);
// 		}
// 	}
// 	write(1, "pa\n", 3);
// 	push_a(stack_a, stack_b);
// }

void	swap(int *a, int *b)
{
	int	t;

	t = *a;
	*a = *b;
	*b = t;
}

int	partition(int *stack_a, int low, int high)
{
	int	pivot;
	int	i;
	int	j;
	int	index;

	pivot = stack_a[high];
	i = (low - 1);
	index = 0;
	j = low;
	while (j <= high - 1)
	{
		if (stack_a[j] <= pivot)
		{
			i++;
			swap(&stack_a[j], &stack_a[i]);
		}
		j++;
	}
	swap(&stack_a[i + 1], &stack_a[high]);
	return (i + 1);
}

void	quick_sort(int *stack_a, int low, int high)
{
	int	index;

	if (low < high)
	{
		index = partition(stack_a, low, high);
		quick_sort(stack_a, low, index - 1);
		quick_sort(stack_a, index + 1, high);
	}
}

int	*int_cmp(t_stack_a *stack_a)
{
	int	*copy;
	int	i;

	i = 0;
	copy = malloc(sizeof(int) * stack_a->max);
	while ((unsigned int)i <= stack_a->max)
	{
		copy[i] = stack_a->a_stack[i];
		i++;
	}
	return (copy);
}
