/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:35:51 by mwane             #+#    #+#             */
/*   Updated: 2021/04/11 18:14:01 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"
#include"checker.h"

void    check_args(int argc, char **args, s_stack_a *stack);

void			quick_sort(s_stack_a *stack_a, s_stack_b *stack_b)
{
	int tmp;

	while (stack_a->top != -1)
	{
		tmp = stack_a->a_stack[stack_a->top];
		rotate_a(stack_a);
		write(1, "ra\n", 3);
		while (stack_b->top != -1 && stack_b->b_stack[stack_b->top] > tmp)
		{
			write(1, "pa\n", 3);
			push_a(stack_a, stack_b);
		}
		write(1, "rra\n", 4);
		reverse_rotate_a(stack_a);
		write(1, "pb\n", 3);
		push_b(stack_b, stack_a);
	}
}

int		main(int argc, char **argv)
{
	s_stack_a	*stack;
	s_stack_b	*stack_b;

	stack = init_stack(argc);
	stack_b = init_stack(argc);
	check_args(argc, argv + 1, stack);
	quick_sort(stack, stack_b);
	return (0);
}