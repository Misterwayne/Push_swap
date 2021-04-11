/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 16:47:07 by mwane             #+#    #+#             */
/*   Updated: 2021/04/10 17:31:17 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"


void     *init_stack(unsigned int max)
{
    s_stack_a   *stack;

    if (!(stack = (s_stack_a*)malloc(sizeof(s_stack_a))))
        return (NULL);
    stack->max = max;
    stack->top = -1;
    if (!(stack->a_stack = (int*)malloc(stack->max * sizeof(int))))
        return (NULL);
    return (stack);
}

int     is_full(s_stack_a *stack)
{
    return (stack->top == stack->max - 1);
}

int     is_full_b(s_stack_b *stack)
{
    return (stack->top == stack->max - 1);
}

int     is_empty(s_stack_a *stack)
{
    return (stack->top == -1);
}

void    push(s_stack_a *stack, int nbr)
{
    if (is_full(stack))
        return ;
    stack->a_stack[++stack->top] = nbr;
}

void    b_push(s_stack_b *stack, int nbr)
{
    if (is_full_b(stack))
        return ;
    stack->b_stack[++stack->top] = nbr;
}

int     pop_b(s_stack_b *stack)
{
    if (is_empty((s_stack_a *)stack))
        return (0);
    return (stack->b_stack[stack->top--]);
}

int     pop(s_stack_a *stack)
{
    if (is_empty(stack))
        return (0);
    return (stack->a_stack[stack->top--]);
}

void    print_stack(s_stack_a *stack_a, s_stack_b *stack_b)
{
    int i;

    i = 0;
    if (stack_a != NULL)
    {
        printf("A top : %d\n", stack_a->top);
        while (i <= stack_a->top)
            printf("%d\n", stack_a->a_stack[i++]);
    }
    i = 0;
    if (stack_b != NULL)
    {
        printf("B top : %d\n", stack_b->top);
        while (i <= stack_b->top)
            printf("%d\n", stack_b->b_stack[i++]);
    }
}

