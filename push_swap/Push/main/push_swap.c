/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:35:51 by mwane             #+#    #+#             */
/*   Updated: 2021/04/18 17:05:37 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/checker.h"

int		find_smallest(t_stack_a *stack)
{
	int i;
	int	half;

	i = 0;
	stack->min = 2147483647;
	half = stack->top / 2;
	while (i <= stack->top)
	{
		if (stack->a_stack[i] < stack->min)
		{
			stack->min = stack->a_stack[i];
			stack->smallest = i;
		}
		i++;
	}
	return (stack->smallest);
}

void	sort_opti(t_stack_a *stack_a, t_stack_b *stack_b)
{
	int index;

	while (stack_a->top != -1)
	{
		index = find_smallest(stack_a);
		if (index > stack_a->top / 2)
		{
			while (stack_a->a_stack[stack_a->top] != stack_a->min)
			{
				rotate_a(stack_a);
				write(1, "ra\n", 3);
			}
			write(1, "pb\n", 3);
			push_b(stack_b, stack_a);
		}
		else
		{
			while (stack_a->a_stack[stack_a->top] != stack_a->min)
			{
				reverse_rotate_a(stack_a);
				write(1, "rra\n", 4);
			}
			push_b(stack_b, stack_a);
		}
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
	free_stack(stack, stack_b);
	return (0);
}
