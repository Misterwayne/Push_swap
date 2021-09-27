/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:35:51 by mwane             #+#    #+#             */
/*   Updated: 2021/09/27 17:12:43 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/checker.h"

/*
I need to know how many ra or rra to get to the top of stack b
I need to know how many ra or rra to get a value to the right space
Ra goes up
RRa goes down
*/

// int		top_place(int current, t_stack_a *stack_a)
// {
// 	int action;
// 	int	i;
// 	int	j;

// 	action = 0;
// 	i = stack_a->top;
// 	j = 0;
// 	if (current > stack_a->a_stack[0] && current < stack_a->a_stack[stack_a->top])
// 	// while (current > stack_a->a_stack[i])
// 	// {
// 	// 	i--;
// 	// 	action++;
// 	// }
// 	// while (current < stack_a->a_stack[i])
// 	// {
// 	// 	i--;
// 	// 	action++;
// 	// }
// 	// while (current > stack_a->a_stack[j])
// 	// 	j++;
// 	if ((j + 1) > action)
// 		stack_a->place = stack_a->a_stack[i];
// 	else
// 	{
// 		action = j + 1;
// 		stack_a->place = stack_a->a_stack[j];
// 	}
// 	if (action > stack_a->top / 2)
// 		stack_a->dir = 1;
// 	else
// 		stack_a->dir = 0;
// 	printf("TOP %d = current | %d = place |%d = nb action\n", current, stack_a->a_stack[i], action);
// 	stack_a->action = action;
// 	return (action);
// }


int		place(t_stack_a *stack_a, t_stack_b *stack_b, int current, int *model)
{
	int		action;
	int		q;
	int		i;
	int		j;

	i = 0;
	q = 1;
	j = stack_a->top;
	(void)stack_b;
	while (model[i] != current)
		i++;
	while (stack_a->a_stack[j] != model[i - q])
	{
		j--;
		if (j < 0)
		{
			j = stack_a->top;
			q++;
		}
	}
	// printf("%d = model place | %d = where to place\n", model[i], stack_a->a_stack[j]);
	stack_a->place = stack_a->a_stack[j];
	if (j >= stack_a->top / 2)
	{
		action = stack_a->top - j;
		stack_a->dir = 0;
	}
	else
	{
		action = j + 1;
		stack_a->dir = 1;
	}
	return (action);
}

void	matrix(t_stack_a *stack_a, t_stack_b *stack_b, int *model)
{
	int		b_count;
	int 	total_action;
	int		min_action;
	int		current_action;
	int		i;

	b_count = 0;
	total_action = 0;
	min_action = 900000;
	i = stack_b->top;
	while (i >= 0)
	{
		total_action = place(stack_a, stack_b, stack_b->b_stack[i], model);
		if (i > stack_a->top / 2)
		{
			stack_b->dir = 0;
			b_count = stack_a->top - i;
		}
		else
		{
			stack_b->dir = 1;
			b_count = i + 1;
		}
		if (stack_a->dir == stack_b->dir)
		{
			if (total_action > b_count)
				current_action = total_action - b_count;
			else
				current_action = b_count - total_action;
		}
		else
			current_action = b_count + total_action;
		if (min_action > current_action)
		{
			stack_b->rra = 0;
			stack_b->ra = 0;
			stack_b->place = stack_b->b_stack[i];
			stack_a->up_place = stack_a->place;
			if (stack_a->dir == 0)
				stack_a->rra = total_action;
			else if (stack_a->dir == 1)
				stack_a->ra = total_action;
			min_action = current_action;
			stack_b->action = min_action;
			if (i > stack_a->top / 2)
				stack_b->rra = b_count;
			else
				stack_b->ra = b_count;
		}
		i--;
	}
}

void	apply(t_stack_a *stack_a, t_stack_b *stack_b)
{
	while (stack_b->place != stack_b->b_stack[stack_b->top])
	{
		if (stack_b->dir == 0)
		{
			if (stack_a->dir == 0 && stack_a->rra != 0)
			{
				r_r_r(stack_a, stack_b);
				stack_a->rra--;
			}
			else
				reverse_rotate_b(stack_b);
		}
		else if (stack_b->dir == 1)
		{
			if (stack_a->dir == 1 && stack_a->ra != 0)
			{
				ra_rb(stack_a, stack_b);
				stack_a->ra--;
			}
			else
				rotate_b(stack_b);
		}
	}
	while (stack_a->up_place != stack_a->a_stack[0])
	{
		// print_stack(stack_a, stack_b);
		if (stack_a->dir == 1)
			reverse_rotate_a(stack_a);
		else
			rotate_a(stack_a);
	}
	push_a(stack_a, stack_b);
}

void	sort_opti(t_stack_a *stack_a, t_stack_b *stack_b)
{
	int		current;
	int		*model;
	
	model = int_cmp(stack_a);
	quick_sort(model, 0, stack_a->top);
	find_biggest(stack_a);
	find_smallest(stack_a);
	current = 0;
	while (stack_a->top != 2)
	{
		current = stack_a->a_stack[stack_a->top];
		if (stack_a->biggest != current && stack_a->min != current)
			push_b(stack_b, stack_a);
		rotate_a(stack_a);
	}
	sort_3(stack_a);
	while (stack_b->top != -1)
	{
		matrix(stack_a, stack_b, model);
		apply(stack_a, stack_b);
	}
}


void	small_sort(t_stack_a *stack_a, t_stack_b *stack_b)
{
	if (stack_a->max < 4)
		sort_3(stack_a);
	else if (stack_a->max < 8)
		sort_5(stack_a, stack_b);
	exit(0);
}

// void	reset_2(t_stack_a *stack_a, t_stack_b *stack_b)
// {
// 	find_biggest_b(stack_b);
// 	while (stack_b->top != -1)
// 	{
// 		push_a(stack_a, stack_b);
// 		write(1, "pa\n", 3);
// 	}
// 	while (stack_a->a_stack[0] != stack_b->big)
// 	{
// 		rotate_a(stack_a);
// 		write(1, "ra\n", 3);
// 	}
// }

int	count_line(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	t_stack_a	*stack;
	t_stack_b	*stack_b;
	char		**arg;
	int			i;

	i = 0;
	if (argc < 3)
		arg = ft_split(argv[1], ' ');
	else
		arg = argv + 1;
	argc = count_line(arg);
	stack = init_stack(argc);
	stack_b = init_stack(argc);
	check_args(argc, arg, stack, stack_b);
	sort_opti(stack, stack_b);
	// print_stack(stack, stack_b);
	free_stack(stack, stack_b);
	return (0);
}
