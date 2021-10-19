/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truepath <truepath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:35:51 by mwane             #+#    #+#             */
/*   Updated: 2021/10/19 00:30:40 by truepath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/checker.h"

int		count_action(t_stack_a *stack_a, int j)
{
	int	action;

	stack_a->place = stack_a->a_stack[j];
	stack_a->half = j;
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
	return (action);
}

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
	stack_a->half = j;
	action = count_action(stack_a, j);
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
	if (stack->top <= 4)
		small_sort(stack, stack_b);
	else
		sort_opti(stack, stack_b);
	free_stack(stack, stack_b);
	return (0);
}
