/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truepath <truepath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 16:47:10 by mwane             #+#    #+#             */
/*   Updated: 2021/04/01 21:13:38 by truepath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include<unistd.h>
#include <stdio.h>
#include<stdlib.h>

typedef struct          t_stack_a
{
    int                 top;
    unsigned int        max;
    int                 *a_stack;
}                       s_stack_a;

typedef struct          t_stack_b
{
    int                 top;
    unsigned int        max;
    int                 *b_stack;
}                       s_stack_b;

void    swap_a(s_stack_a *stack);
void    rotate_a(s_stack_a *stack);
void    swap_a(s_stack_a *stack);
void    swap_b(s_stack_b *stack);
void    sa_sb(s_stack_a *stack_a, s_stack_b *stack_b);
void    push_a(s_stack_a *stack_a, s_stack_b *stack_b);
void    push_b(s_stack_b *stack_b, s_stack_a *stack_a);
void    push(s_stack_a *stack, int nbr);
void       reverse_rotate_a(s_stack_a *stack);