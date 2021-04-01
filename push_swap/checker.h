/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 16:47:10 by mwane             #+#    #+#             */
/*   Updated: 2021/04/01 17:59:02 by mwane            ###   ########.fr       */
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