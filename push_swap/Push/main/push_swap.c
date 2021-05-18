/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:35:51 by mwane             #+#    #+#             */
/*   Updated: 2021/05/18 17:34:27 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/checker.h"

void	high_rotate(int index, t_stack_a *stack_a, t_stack_b *stack_b)
{
	while (stack_a->a_stack[stack_a->top] != stack_a->big)
	{
		if (index < 0)
		{
			rotate_a(stack_a);
			write(1, "ra\n", 3);
		}
		else
		{
			reverse_rotate_a(stack_a);
			write(1, "rra\n", 4);
		}
	}
	write(1, "pb\n", 3);
	push_b(stack_b, stack_a);
	ra_rb(stack_a, stack_b);
	write(1, "rb\n", 4);
}

void	low_rotate(int index, t_stack_a *stack_a, t_stack_b *stack_b)
{
	while (stack_a->a_stack[stack_a->top] != stack_a->min)
	{
		if (index < 0)
		{
			rotate_a(stack_a);
			write(1, "ra\n", 3);
		}
		else
		{
			reverse_rotate_a(stack_a);
			write(1, "rra\n", 4);
		}
	}
	write(1, "pb\n", 3);
	push_b(stack_b, stack_a);
}

void	sort_opti(t_stack_a *stack_a, t_stack_b *stack_b)
{
	int index;
	int index2;

	while (stack_a->top != -1)
	{
		index = find_smallest(stack_a);
		index2 = find_biggest(stack_a);
		if (absolute_v(index) > absolute_v(index2))
			high_rotate(index2, stack_a, stack_b);
		else
			low_rotate(index, stack_a, stack_b);
	}
}

void	reset_2(t_stack_a *stack_a, t_stack_b *stack_b)
{
	find_biggest_b(stack_b);
	while (stack_b->top != -1)
	{
		write(1, "pa\n", 3);
		push_a(stack_a, stack_b);
	}
	while (stack_a->a_stack[0] != stack_b->big)
	{
		rotate_a(stack_a);
		write(1, "ra\n", 3);
	}
}

int		main(int argc, char **argv)
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
	sort_opti(stack, stack_b);
	reset_2(stack, stack_b);
	free_stack(stack, stack_b);
	return (0);
}
