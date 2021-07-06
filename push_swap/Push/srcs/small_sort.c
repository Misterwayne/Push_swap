/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 17:56:29 by mwane             #+#    #+#             */
/*   Updated: 2021/07/06 19:00:55 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/checker.h"

int	smallest(t_stack_a *stack_a)
{
	int i;
	int min;
	
	min = INT16_MAX;
	i = 0;
	while (i <= stack_a->top)
	{
		if (stack_a->a_stack[i] < min)
			min = stack_a->a_stack[i];
		i++;
	}
	return (min);
}

void	sort_3(t_stack_a *stack_a, t_stack_b *stack_b)
{
	int min;

	min = smallest(stack_a);

	if (stack_a->a_stack[stack_a->top] == min)
	{
		// 1 -1 0
		write(1, "case 1\n", 7);
		rotate_a(stack_a);
		swap_a(stack_a);
		write(1, "sa\n", 3);
		reverse_rotate_a(stack_a);
	}
	else if (stack_a->a_stack[stack_a->top - 1] == min)
	{
		write(1, "case 2\n", 7);
		rotate_a(stack_a);
		print_stack(stack_a, stack_b);
		swap_a(stack_a);
		write(1, "sa\n", 3);
		print_stack(stack_a, stack_b);
		rotate_a(stack_a);
		print_stack(stack_a, stack_b);
	}
	else if (stack_a->a_stack[0] == min)
	{
		write(1, "case 3\n", 7);
		swap_a(stack_a);
		write(1, "sa\n", 3);
		rotate_a(stack_a);
	}
	// if (stack_a->a_stack[stack_a->top] > stack_a->a_stack[0])
	// 	rotate_a(stack_a);
	// else
	// 	reverse_rotate_a(stack_a);
	print_stack(stack_a, stack_b);
}

void	sort_5(t_stack_a *stack_a, t_stack_b *stack_b)
{
	(void)stack_b;
	(void)stack_a;
	
	return ;
}