/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 17:24:26 by mwane             #+#    #+#             */
/*   Updated: 2021/04/01 17:58:42 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void    swap_a(s_stack_a *stack)
{
    int     tmp;
    
    if (stack->top < 1)
        return;
    tmp = stack->a_stack[stack->top];
    stack->a_stack[stack->top] = stack->a_stack[stack->top - 1];
    stack->a_stack[stack->top - 1] = tmp;

}

void    swap_b(s_stack_b *stack)
{
    int     tmp;
    
    if (stack->top < 1)
        return;
    tmp = stack->b_stack[stack->top];
    stack->b_stack[stack->top] = stack->b_stack[stack->top - 1];
    stack->b_stack[stack->top - 1] = tmp;
}

void    sa_sb(s_stack_a *stack_a, s_stack_b *stack_b)
{
    swap_a(stack_a);
    swap_b(stack_b);
}

void    push_a(s_stack_a *stack_a, s_stack_b *stack_b)
{
    if (stack_b->top == -1)
        return;
    push(stack_a, stack_b->b_stack[stack_b->top]);
}

void    push_b(s_stack_b *stack_b, s_stack_a *stack_a)
{
    if (stack_a->top == -1)
        return;
    push(stack_b, stack_a->a_stack[stack_a->top]);
}