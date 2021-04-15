/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:35:51 by mwane             #+#    #+#             */
/*   Updated: 2021/04/15 17:44:06 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../header/checker.h"
#include <stdio.h>

int		find_smallest(s_stack_a *stack)
{
	int i;
	int	half;
	int	min;
	int	smallest;

	i = 0;
	min  = 2147483647;
	half = stack->top / 2;
	while (i < stack->top)
	{
		if (stack->a_stack[i] < min)
		{
			min = stack->a_stack[i];
			smallest = i;
		}
		i++;
	}
	if (smallest < half)
		return (stack->top - smallest);
	else
		return ((smallest - stack->top) * -1);
}

void	sort_opti(s_stack_a *stack_a, s_stack_b *stack_b)
{
	int	tmp;

	while (stack_a->top != -1)
	{
		tmp = find_smallest(stack_a);
		if (tmp > 0)
		{
			while (tmp > 0)
			{
				rotate_a(stack_a);
				write(1, "ra\n", 3);
				tmp--;
			}
			write(1, "pb\n", 3);
			push_b(stack_b, stack_a);
		}
		else
		{
			tmp *= -1;
			while (tmp <= stack_a->top)
			{
				reverse_rotate_a(stack_a);
				write(1, "rra\n", 4);
				tmp++;
			}
			write(1, "pb\n", 3);
			push_b(stack_b, stack_a);
		}
		if (stack_b->b_stack[stack_b->top] < stack_b->b_stack[stack_b->top - 1])
		{
			swap_b(stack_b);
			write(1, "sb\n", 3);
		}
	}
}

int	main(int argc, char **argv)
{
	s_stack_a	*stack;
	s_stack_b	*stack_b;
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
	check_args(argc, arg, stack);
	sort_opti(stack, stack_b);
	print_stack(stack, stack_b);
	free_stack(stack, stack_b);
	return (0);
}
