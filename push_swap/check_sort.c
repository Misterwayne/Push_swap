/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truepath <truepath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 22:22:33 by truepath          #+#    #+#             */
/*   Updated: 2021/04/08 22:49:48 by truepath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"checker.h"


int         sort_checker(s_stack_a *stack)
{
	int     i;
	int     tmp;

	i = 0;
	tmp = stack->a_stack[0];
	while (i < stack->top)
	{
		if (stack->a_stack[i + 1] <= stack->a_stack[i])
			return (0);
		i++;
	}
	return (1);
}