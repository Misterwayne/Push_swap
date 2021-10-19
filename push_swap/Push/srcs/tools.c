/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truepath <truepath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 19:08:29 by truepath          #+#    #+#             */
/*   Updated: 2021/10/18 21:45:23 by truepath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/checker.h"

void   set_up(t_stack_a *stack_a, t_stack_b *stack_b, int i)
{
    stack_b->dir = 0;
	stack_b->rrb = 0;
	stack_b->rb = 0;
	stack_a->rra = 0;
	stack_a->ra = 0;
	stack_b->place = stack_b->b_stack[i];
	stack_a->up_place = stack_a->place; 
} 

void    make_calcul_a(t_stack_a *stack_a, t_stack_b *stack_b, int i)
{
    if (stack_a->dir == 1)
	{
		stack_a->ra = stack_a->a_action;
		if (stack_a->ra >= stack_b->top / 2 && stack_b->rrb > 0)
	    {
			stack_b->rb = stack_b->top - i;
			stack_b->rrb = 0;
		}
	}
	else if (stack_a->dir == 0)
	{
		stack_a->rra = stack_a->a_action;
		if (stack_a->rra >= stack_b->top / 2 && stack_b->rb > 0)
		{
			stack_b->rrb = i + 1;
			stack_b->rb = 0;
		}
	}
}

void    make_calcul_b(t_stack_a *stack_a, t_stack_b *stack_b, int i)
{
    if (i >= stack_a->top / 2)
	{
		stack_b->rb = stack_b->b_action;
	    if (stack_b->rb >= stack_a->top / 2 && stack_a->rra > 0)
	    {
		    stack_a->ra = stack_a->top - stack_a->half;
	        stack_a->rra = 0;
	    }
	}
	else if (stack_b->dir == 0)
	{
		stack_b->rrb = stack_b->b_action;
		if (stack_b->rb >= stack_a->top / 2 && stack_a->rra > 0)
		{
			stack_a->rra = stack_a->half + 1;
			stack_a->ra = 0;
		}
	}  
}

int     pick(t_stack_a *stack_a, t_stack_b *stack_b, int i)
{
    int     current_action;

    if (i >= stack_a->top / 2)
	{
		stack_b->dir = 1;
		stack_b->b_action = stack_b->top - i;
	}
	else
	{
		stack_b->dir = 0;
		stack_b->b_action = i + 1;
	}
	if (stack_a->a_action >= stack_b->top / 2)
		current_action = stack_a->a_action;
	else if (stack_b->b_action >= stack_a->top / 2)
	    current_action = stack_b->b_action;
	else
		current_action = stack_a->a_action + stack_b->b_action;
    return (current_action);
}

void	matrix(t_stack_a *stack_a, t_stack_b *stack_b, int *model)
{
	int		min_action;
	int		current_action;
	int		i;

	stack_b->b_action = 0;
	stack_a->a_action = 0;
	min_action = 900000;
	i = stack_b->top;
	while (i >= 0)
	{
		stack_a->a_action = place(stack_a, stack_b, stack_b->b_stack[i], model);
		current_action = pick(stack_a, stack_b, i);
		if (min_action > current_action)
		{
			set_up(stack_a, stack_b, i);
			min_action = current_action;
			stack_b->action = min_action;
            make_calcul_b(stack_a, stack_b, i);
            make_calcul_a(stack_a, stack_b, i);
		}
		i--;
	}
}