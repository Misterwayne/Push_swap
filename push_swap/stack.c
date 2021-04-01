/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 16:47:07 by mwane             #+#    #+#             */
/*   Updated: 2021/04/01 17:59:28 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"


s_stack_a     *init_stack(unsigned int max)
{
    s_stack_a   *stack;

    stack = (s_stack_a*)malloc(sizeof(s_stack_a));

    stack->max = max;
    stack->top = -1;
    stack->a_stack = (int*)malloc(stack->max * sizeof(int));
    return stack;
}

int     is_full(s_stack_a *stack)
{
    return stack->top == stack->max - 1;
}

int     is_empty(s_stack_a *stack)
{
    return stack->top == -1;
}

void    push(s_stack_a *stack, int nbr)
{
    if (is_full(stack))
        return;
    stack->a_stack[++stack->top] = nbr;
}

int     pop(s_stack_a *stack)
{
    if (is_empty(stack))
        return 0;
    return stack->a_stack[stack->top--];
}

int main()
{
    s_stack_a *stack = init_stack(30);
    s_stack_b *stack_b = init_stack(30);
 
    push(stack, 40);
    push(stack, 20);
    push(stack, 30);
    swap_a(stack);
    push_b(stack_b, stack);
    printf("%d popped from stack b\n", pop(stack_b));
    printf("%d popped from stack\n", pop(stack));
    printf("%d popped from stack\n", pop(stack));
    printf("%d popped from stack\n", pop(stack));
 
 
    return 0;
}