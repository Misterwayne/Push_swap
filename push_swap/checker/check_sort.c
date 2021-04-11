/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 22:22:33 by truepath          #+#    #+#             */
/*   Updated: 2021/04/11 18:13:18 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"checker.h"

void	error_msg(void)
{
	write(1, "ERROR\n", 6);
	exit(1);
}

int		duplicate(char **stack, char *item, int index)
{
	int		i;

	i = -1;
	while (stack[++i] != NULL)
	{
		if (i != index)
			if (strcmp(stack[i], item) == 0)
				return (1);
	}
	return (0);
}

void    check_args(int argc, char **args, s_stack_a *stack)
{
	int		i;
	char	*item;

	i = argc - 2;
	while (i >= 0)
	{
		item = args[i];
		if (args[i][0] != '0')
			if (atoi(args[i]) == 0)
				error_msg();
		if (atol(args[i]) > 2147483647 || atol(args[i]) < -2147483648)
			error_msg();
		if (duplicate(args, item, i))
			error_msg();
		push(stack, atoi(args[i]));
		i--;
	}
}

int         sort_checker(s_stack_a *stack)
{
	int     i;

	i = 0;
	while (i < stack->top)
	{
		if (stack->a_stack[i + 1] <= stack->a_stack[i])
			return (0);
		i++;
	}
	return (1);
}