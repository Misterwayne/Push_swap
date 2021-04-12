/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 22:22:33 by truepath          #+#    #+#             */
/*   Updated: 2021/04/12 17:12:26 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../header/checker.h"

void	error_msg(void)
{
	write(1, "ERROR\n", 6);
	exit(1);
}

int	duplicate(char **stack, char *item, int index)
{
	int		i;

	i = -1;
	while (stack[++i] != NULL)
	{
		if (i != index)
			if (ft_strcmp(stack[i], item) == 0)
				return (1);
	}
	return (0);
}

void	check_args(int i, char **args, s_stack_a *stack)
{
	char	*item;

	i--;
	while (i >= 0)
	{
		item = args[i];
		if (args[i][0] != '0')
			if (ft_atoi(args[i]) == 0)
				error_msg();
		if (ft_atoi(args[i]) > 2147483647 || ft_atoi(args[i]) < -2147483648)
			error_msg();
		if (duplicate(args, item, i))
			error_msg();
		push(stack, ft_atoi(args[i]));
		i--;
	}
}

int	sort_checker(s_stack_a *stack)
{
	int	i;

	i = 0;
	while (i < stack->top)
	{
		if (stack->a_stack[i + 1] >= stack->a_stack[i])
			return (0);
		i++;
	}
	free(stack->a_stack);
	free(stack);
	return (1);
}

void	r_r_r(s_stack_a *stack_a, s_stack_b *stack_b)
{
	reverse_rotate_a(stack_a);
	reverse_rotate_b(stack_b);
}
