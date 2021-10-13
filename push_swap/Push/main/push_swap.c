/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:35:51 by mwane             #+#    #+#             */
/*   Updated: 2021/10/12 21:48:32 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/checker.h"

/*
I need to know how many ra or rra to get to the top of stack b
I need to know how many ra or rra to get a value to the right space
Ra goes up
RRa goes down
*/


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
	stack_a->dir = 0;
	while (model[i] != current)
		i++;
	while (stack_a->a_stack[j] != model[i + q])
	{
		j--;
		if (j < 0)
		{
			j = stack_a->top;
			q++;
		}
	}
	stack_a->place = stack_a->a_stack[j];
	if (j >= stack_a->top / 2)
	{
		action = stack_a->top - j;
		stack_a->dir = 1;
	}
	else
	{
		action = j + 1;
		stack_a->dir = 0;
	}
	// if (action == stack_a->top)
	// 	action = 0;
	return (action);
}

void	reset_2(t_stack_a *stack_a)
{
	find_smallest(stack_a);
	while (stack_a->a_stack[stack_a->top] != stack_a->min)
	{
		if (stack_a->dir == 1)
			rotate_a(stack_a, 0);
		else
			reverse_rotate_a(stack_a, 0);
	}
}

void	matrix(t_stack_a *stack_a, t_stack_b *stack_b, int *model)
{
	int		b_action;
	int 	a_action;
	int		min_action;
	int		current_action;
	int		i;

	b_action = 0;
	a_action = 0;
	min_action = 900000;
	i = stack_b->top;
	while (i >= 0)
	{
		a_action = place(stack_a, stack_b, stack_b->b_stack[i], model);
		if (i >= stack_a->top / 2)
		{
			stack_b->dir = 1;
			b_action = stack_b->top - i;
		}
		else
		{
			stack_b->dir = 0;
			b_action = i + 1;
		}
		if (stack_a->dir == stack_b->dir)
		{
			if (a_action > b_action)
				current_action = a_action - b_action;
			else
				current_action = b_action - a_action;
		}
		else
			current_action = b_action + a_action;
		if (min_action > current_action)
		{
			stack_b->dir = 0;
			stack_b->rrb = 0;
			stack_b->rb = 0;
			stack_a->rra = 0;
			stack_a->ra = 0;
			stack_b->place = stack_b->b_stack[i];
			stack_a->up_place = stack_a->place;
			min_action = current_action;
			stack_b->action = min_action;
			if (stack_a->dir == 1)
				stack_a->ra = a_action;
			else if (stack_a->dir == 0)
				stack_a->rra = a_action;
			if (i >= stack_a->top / 2)
				stack_b->rb = b_action;
			else if (stack_b->dir == 0)
				stack_b->rrb = b_action;
		}
		i--;
	}
}

void	apply(t_stack_a *stack_a, t_stack_b *stack_b)
{
	// printf("dir b : %d | dir a : %d\nB rb : %d | A ra : %d\nB rrb : %d | A rra : %d\n",stack_b->dir, stack_a->dir, stack_b->rb, stack_a->ra, stack_b->rrb, stack_a->rra);
	while (stack_b->rrb > 0 || stack_b->rb > 0 || stack_a->rra > 0 || stack_a->ra > 0)
	{
		if (stack_a->rra > 0 && stack_b->rrb > 0)
		{
			r_r_r(stack_a, stack_b);
			stack_a->rra--;
			stack_b->rrb--;
		}
		if (stack_a->ra > 0 && stack_b->rb > 0)
		{
			ra_rb(stack_a, stack_b);
			stack_a->ra--;
			stack_b->rb--;
		}
		if (stack_b->rrb > 0 && stack_a->rra == 0)
		{
			reverse_rotate_b(stack_b, 0);
			stack_b->rrb--;
		}
		else if (stack_b->rb > 0 && stack_a->ra == 0)
		{
			rotate_b(stack_b, 0);
			stack_b->rb--;
		}
		if (stack_a->rra > 0 && stack_b->rrb == 0)
		{
			reverse_rotate_a(stack_a, 0);
			stack_a->rra--;
		}
		else if (stack_a->ra > 0 && stack_b->rb == 0)
		{
			rotate_a(stack_a, 0);
			stack_a->ra--;
		}
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
	stack_a->half = model[stack_a->top];
	while (stack_a->top != 2)
	{
		current = stack_a->a_stack[stack_a->top];
		if (stack_a->biggest != current && stack_a->min != current)
			push_b(stack_b, stack_a);
		rotate_a(stack_a, 0);
	}
	// sort_3(stack_a);
	while (stack_b->top != -1)
	{
		matrix(stack_a, stack_b, model);
		apply(stack_a, stack_b);
	}
	reset_2(stack_a);
}


void	small_sort(t_stack_a *stack_a, t_stack_b *stack_b)
{
	if (stack_a->max < 4)
		sort_3(stack_a);
	else if (stack_a->max < 8)
		sort_5(stack_a, stack_b);
	exit(0);
}

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
	if (stack->top <= 6)
		small_sort(stack, stack_b);
	else
		sort_opti(stack, stack_b);
	// print_stack(stack, stack_b);
	free_stack(stack, stack_b);
	return (0);
}
