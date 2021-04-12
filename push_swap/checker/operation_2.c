/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truepath <truepath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 19:50:48 by truepath          #+#    #+#             */
/*   Updated: 2021/04/11 19:40:34 by truepath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"checker.h"

void        rotate_a(s_stack_a *stack)
{
    int     tmp;
    int     i;

    i = stack->top;
    tmp = stack->a_stack[i];
    while (i > 0)
    {
        stack->a_stack[i] = stack->a_stack[i - 1];
        i--;
    }
    stack->a_stack[0] = tmp;
}

void        rotate_b(s_stack_b *stack)
{
    int     tmp;
    int     i;

    if (stack->top < 1)
        return ;
    i = stack->top;
    tmp = stack->b_stack[i];
    while (i > 0)
    {
        stack->b_stack[i] = stack->b_stack[i - 1];
        i--;
    }
    stack->b_stack[0] = tmp;
}

void        ra_rb(s_stack_a *stack_a, s_stack_b *stack_b)
{
    rotate_a(stack_a);
    rotate_b(stack_b);
}

void        reverse_rotate_a(s_stack_a *stack)
{
    int     tmp;
    int     i;

    if (stack->top < 1)
        return ;
    i = 0;
    tmp = stack->a_stack[i];
    while (i < stack->top)
    {
        stack->a_stack[i] = stack->a_stack[i + 1];
        i++;
    }
    stack->a_stack[stack->top] = tmp;
}

void        reverse_rotate_b(s_stack_b *stack)
{
    int     tmp;
    int     i;

    if (stack->top < 1)
        return ;
    i = 0;
    tmp = stack->b_stack[i];
    while (i < stack->top)
    {
        stack->b_stack[i] = stack->b_stack[i + 1];
        i++;
    }
    stack->b_stack[stack->top] = tmp;
}

void        r_r_r(s_stack_a *stack_a, s_stack_b *stack_b)
{
    reverse_rotate_a(stack_a);
    reverse_rotate_b(stack_b);
}