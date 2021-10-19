/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truepath <truepath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:35:51 by mwane             #+#    #+#             */
/*   Updated: 2021/10/19 00:22:04 by truepath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/checker.h"

void    case_rrr(t_stack_a *stack_a, t_stack_b *stack_b)
{
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

void	apply(t_stack_a *stack_a, t_stack_b *stack_b)
{
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
        case_rrr(stack_a, stack_b);
	}
	push_a(stack_a, stack_b);
}

void	scoring(t_stack_a *stack_a, int x, int *score)
{
	if (!(is_inside(stack_a->biggest, score, stack_a)))
		x++;
	if (!(is_inside(stack_a->min, score, stack_a)))
		x++;
	if (stack_a->score < x)
		stack_a->score = x;
}

int*	sorted_chunk(t_stack_a *stack_a, int j, int *model)
{
	int		i;
	int		x;
	int		tmp;
	int		*score;

	x = 0;
	score = int_cmp(stack_a);
	stack_a->len = stack_a->top;
	while (x <= stack_a->top)
		score[x++] = 80000;
	i = stack_a->top;
	x = 0;
	tmp = model[stack_a->top];
	while (j >= 0)
	{
		if (model[j] > tmp)
		{
			score[i--] = model[j];
			tmp = model[j];
			x++;
		}
		j--;
	}
	score[i] = model[stack_a->top];
	scoring(stack_a, x, score);
	return (score);
}
