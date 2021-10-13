/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_opti.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 18:42:41 by mwane             #+#    #+#             */
/*   Updated: 2021/10/07 10:21:02 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/checker.h"

int     rotate_opti(t_stack_a *stack_a)
{
    int index;
    int index2;
    int i;

    index = 0;
    index2 = 0;
    i = 0;
    while (index == 0)
    {
        if (stack_a->a_stack[i] <= stack_a->half)
            index = i;
        i++;
    }
    i = stack_a->top;
    while (index2 == 0)
    {
        if (stack_a->a_stack[i] <= stack_a->half)
            index2 = i;
        i--;
    }
    if (index > index2)
        return (1);
    else 
        return (0);
}