/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truepath <truepath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:35:51 by mwane             #+#    #+#             */
/*   Updated: 2021/10/18 22:20:31 by truepath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/checker.h"

void    first_parsing(t_stack_a *stack_a, t_stack_b *stack_b, int *model, int *tmp)
{
    int i;

	i = 0;
    quick_sort(model, 0, stack_a->top);
	while (stack_a->top != stack_a->score)
	{
		if ((is_inside(stack_a->a_stack[stack_a->top], tmp, stack_a)) || stack_a->a_stack[stack_a->top] == stack_a->biggest)
		{
			rotate_a(stack_a, 0);
			i++;
		}
		else
		{
			push_b(stack_b, stack_a);
			if (stack_b->b_stack[stack_b->top] > model[stack_a->max / 2] && stack_b->top > 2)
				rotate_b(stack_b, 0);
		}
		if (stack_a->top <= 2) 
			break;
	}
}

void    first_matrix(t_stack_a *stack_a, t_stack_b *stack_b, int *model)
{
    int     *tmp;
    int     i;
    int     score;

    i = stack_a->top;
    tmp = NULL;
	score = 0;
    while (i >= 0)
	{
		sorted_chunk(stack_a, i, model);
		if (stack_a->score > score)
		{
			if (tmp != NULL)
				free(tmp);
			tmp = sorted_chunk(stack_a, i, model);
			score = stack_a->score;
		}
		i--;
	}
	first_parsing(stack_a, stack_b, model, tmp);
}

void	sort_opti(t_stack_a *stack_a, t_stack_b *stack_b)
{
	int		current;
	int		score;
	int		*model;
	
	model = int_cmp(stack_a);
	find_biggest(stack_a);
	find_smallest(stack_a);
	reset_strign(stack_a, model);
	current = 0;
	score = 0;
	first_matrix(stack_a, stack_b, model);
	reset_2(stack_a);
	if (stack_a->a_stack[stack_a->top - 1] == stack_a->biggest && stack_a->a_stack[stack_a->top] == stack_a->min)
		swap_a(stack_a);
	while (stack_b->top != -1)
	{
		matrix(stack_a, stack_b, model);
		apply(stack_a, stack_b);
	}
	reset_2(stack_a);
}

int		is_inside(int current, int *tmp, t_stack_a *stack_a)
{
	int i;

	i = 0;
	while (i <= stack_a->len)
	{
		if (current == tmp[i])
			return (1);
		i++;
	}
	return (0);
}

void	small_sort(t_stack_a *stack_a, t_stack_b *stack_b)
{
	if (stack_a->max < 4)
		sort_3(stack_a);
	else if (stack_a->max < 6)
		sort_5(stack_a, stack_b);
	exit(0);
}
