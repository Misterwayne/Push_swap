/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 16:47:10 by mwane             #+#    #+#             */
/*   Updated: 2021/04/15 17:03:03 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include"../libft2/libft.h"

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


// OPERATION
void                    rotate_a(s_stack_a *stack);
void                    rotate_b(s_stack_b *stack);
void                    swap_a(s_stack_a *stack);
void                    swap_b(s_stack_b *stack);
void                    sa_sb(s_stack_a *stack_a, s_stack_b *stack_b);
void                    push_a(s_stack_a *stack_a, s_stack_b *stack_b);
void                    push_b(s_stack_b *stack_b, s_stack_a *stack_a);
void                    reverse_rotate_a(s_stack_a *stack);
void                    reverse_rotate_b(s_stack_b *stack);
void                    r_r_r(s_stack_a *stack_a, s_stack_b *stack_b);
void                    ra_rb(s_stack_a *stack_a, s_stack_b *stack_b);


// STACK FUNCTION

void                    *init_stack(unsigned int max);
int	                    is_full_b(s_stack_b *stack);
int                     is_full(s_stack_a *stack);
int                     is_empty(s_stack_a *stack);
void                    push(s_stack_a *stack, int nbr);
int                     pop(s_stack_a *stack);
void                    print_stack(s_stack_a *stack_a, s_stack_b *stack_b);
void                    b_push(s_stack_b *stack, int nbr);
int                     pop_b(s_stack_b *stack);
void	                free_stack(s_stack_a *stack, s_stack_b *stack_b);
// CHECKER FUNCTION

int                     sort_checker(s_stack_a *stack);
void	                error_msg(void);
int		                duplicate(char **stack, char *item, int index);
void                    check_args(int argc, char **args, s_stack_a *stack);
char			        **ft_split(char const *s, char c);
