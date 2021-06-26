/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:35:51 by mwane             #+#    #+#             */
/*   Updated: 2021/06/26 19:12:16 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/checker.h"

void swap(int *a, int *b)
{
	int t; 
	
	t = *a;
  	*a = *b;
  	*b = t;
}

int        partition(int *stack_a, int low, int high)
{
    int     pivot;
    int     i;
    int     j;
    int     index;

    pivot = stack_a[high];
    i = (low - 1);
    index = 0;
    for(j = low; j <= high - 1; j++)
    {
        if (stack_a[j] <= pivot)
        {
            i++;
            swap(&stack_a[j], &stack_a[i]);
        }
    }
    swap(&stack_a[i + 1], &stack_a[high]);
    return (i + 1);
}

void        quick_sort(int *stack_a, int low, int high)
{
    int index;

    if (low < high)
    {
        index = partition(stack_a, low, high);
        quick_sort(stack_a, low, index - 1);
        quick_sort(stack_a, index + 1, high);
    }
}

int		*int_cmp(t_stack_a *stack_a)
{
	int	*copy;
	int i;

	i = 0;
	copy = malloc(sizeof(int) * stack_a->max);
	while ((unsigned int)i <= stack_a->max)
	{
		copy[i] = stack_a->a_stack[i];
		i++;
	}
	return (copy);
}

void	chunck_sort(t_stack_a *stack_a, t_stack_b *stack_b)
{
	int *model;
	int min;

	model = int_cmp(stack_a);
	quick_sort(model, 0, stack_a->top);
	min = stack_a->top / 2;
	stack_a->half = model[min];
	while (min >= 0)
	{
		if (stack_a->a_stack[stack_a->top] <= stack_a->half)
		{
			write(1, "pb\n", 3);
			push_b(stack_b, stack_a);
			--min;
		}
		else
		{
			rotate_a(stack_a);
			write(1, "ra\n", 3);
		}
	}
	free(model);
}

void	sort_opti(t_stack_a *stack_a, t_stack_b *stack_b)
{
	int	index2;

	while (stack_b->top != -1)
	{
		index2 = find_biggest(stack_b);
		high_rotate(index2, stack_a, stack_b);
	}
}

void	reset_2(t_stack_a *stack_a, t_stack_b *stack_b)
{
	find_biggest_b(stack_b);
	while (stack_b->top != -1)
	{
		push_a(stack_a, stack_b);
		write(1, "pa\n", 3);
	}
	while (stack_a->a_stack[0] != stack_b->big)
	{
		rotate_a(stack_a);
		write(1, "ra\n", 3);
	}
}

int	main(int argc, char **argv)
{
	t_stack_a	*stack;
	t_stack_b	*stack_b;
	char		**arg;
	int			i;

	i = 0;
	if (argc < 3)
	{
		arg = ft_split(argv[1], ' ');
		while (arg[i])
			i++;
		argc = i;
	}
	else
	{
		arg = argv + 1;
		argc--;
	}
	stack = init_stack(argc);
	stack_b = init_stack(argc);
	check_args(argc, arg, stack, stack_b);
	while (stack->top >= 1)
		chunck_sort(stack, stack_b);
	if (stack->a_stack[0] < stack->a_stack[stack->top])
	{
		swap_a(stack);
		write(1, "sa\n", 3);
	}
	sort_opti(stack, stack_b);
	free_stack(stack, stack_b);
	return (0);
}
