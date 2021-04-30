/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:35:51 by mwane             #+#    #+#             */
/*   Updated: 2021/04/30 17:49:32 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/checker.h"

int		find_biggest_b(t_stack_b *stack)
{
	int i;

	i = 0;
	stack->big = -2147483648;
	while (i <= stack->top)
	{
		if (stack->b_stack[i] > stack->big)
		{
			stack->big = stack->b_stack[i];
			stack->biggest = i;
		}
		i++;
	}
	if (stack->biggest > stack->top / 2)
		return (stack->biggest * -1);
	else
		return (stack->biggest);
}

// int		find_biggest(t_stack_a *stack)
// {
// 	int i;

// 	i = 0;
// 	stack->big = -2147483648;
// 	while (i <= stack->top)
// 	{
// 		if (stack->a_stack[i] > stack->big)
// 		{
// 			stack->big = stack->a_stack[i];
// 			stack->biggest = i;
// 		}
// 		i++;
// 	}
// 	if (stack->biggest > stack->top / 2)
// 		return ((stack->top - stack->biggest) * -1);
// 	else
// 		return (stack->biggest);
// }

// int		find_smallest(t_stack_a *stack)
// {
// 	int i;
// 	int	half;

// 	i = 0;
// 	stack->min = 2147483647;
// 	half = stack->top / 2;
// 	while (i <= stack->top)
// 	{
// 		if (stack->a_stack[i] < stack->min)
// 		{
// 			stack->min = stack->a_stack[i];
// 			stack->smallest = i;
// 		}
// 		i++;
// 	}
// 	if (stack->smallest > stack->top / 2)
// 		return ((stack->top - stack->smallest) * -1);
// 	else
// 		return (stack->smallest);
// }

int		fastest(t_stack_a *stack)
{
	int index;
	int	index2;

	index = find_smallest(stack);
	index2 = find_biggest(stack);
	if (absolute_v(index) > absolute_v(index2))
		return (index2);
	else
		return (index);
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
		{
			while (stack_a->a_stack[stack_a->top] != stack_a->big)
			{
				// print_stack(stack_a, stack_b);
				if (index2 < 0)
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
			if (stack_a->a_stack[stack_a->top] > stack_b->b_stack[stack_b->top])
			{
				write(1, "pb\n", 3);
				push_b(stack_b, stack_a);
				swap_b(stack_b);
				write(1, "sb\n", 4);
				// print_stack(stack_a, stack_b);
				// rotate_b(stack_b);
				// write(1, "rb\n", 4);
			}
			else
			{
				write(1, "pb\n", 3);
				push_b(stack_b, stack_a);
			}
		}
		else
		{
			while (stack_a->a_stack[stack_a->top] != stack_a->min)
			{
				// print_stack(stack_a, stack_b);
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
			// if (stack_a->a_stack[stack_a->top] > stack_b->b_stack[stack_b->top])
			// {
			// 	reverse_rotate_b(stack_b);
			// 	write(1, "rrb\n", 4);
			// }
			write(1, "pb\n", 3);
			push_b(stack_b, stack_a);
		}
	}
}

void	reset_2(t_stack_a *stack_a, t_stack_b *stack_b)
{
	while (stack_b->top != -1)
	{
		write(1, "pa\n", 3);
		push_a(stack_a, stack_b);
	}
}

void	reset(t_stack_a *stack_a, t_stack_b *stack_b)
{
	int index;

	while (stack_b->top != -1)
	{
		index = find_biggest_b(stack_b);
		while (stack_b->b_stack[stack_b->top] != stack_b->big)
		{
			// print_stack(stack_a, stack_b);
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
			if (stack_b->top == -1)
				break ;
		}
		write(1, "pa\n", 3);
		push_a(stack_a, stack_b);
		if (stack_b->top == -1)
				break ;
	}
}

void	sort_2(t_stack_a *stack_a, t_stack_b *stack_b)
{
	int index;

	while (stack_b->top != (int)stack_a->max)
	{
		index = find_biggest(stack_a);
		while (stack_a->a_stack[stack_a->top] != stack_a->big)
		{
			// print_stack(stack_a, stack_b);
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
			if (stack_a->top == -1)
				break ;
		}
		write(1, "pb\n", 3);
		push_b(stack_b, stack_a);
		if (stack_a->top == -1)
				break ;
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
	// quick_sort(stack, stack_b, 0, argc - 1);
	sort_opti(stack, stack_b);
	reset(stack, stack_b);
	// sort_2(stack, stack_b);
	// sort_3(stack, stack_b);
	// reset_2(stack, stack_b);
	// print_stack(stack, stack_b);
	free_stack(stack, stack_b);
	return (0);
}
