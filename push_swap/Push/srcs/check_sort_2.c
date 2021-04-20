/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 16:04:03 by mwane             #+#    #+#             */
/*   Updated: 2021/04/19 17:15:56 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/checker.h"

int		absolute_v(int nbr)
{
	if (nbr < 0)
		return (nbr * -1);
	else
		return (nbr);
}

int		checker_2(char *instruction, t_stack_a *stack, t_stack_b *stack_b)
{
	if (ft_strcmp(instruction, "rb") == 0)
		rotate_b(stack_b);
	else if (ft_strcmp(instruction, "rr") == 0)
		ra_rb(stack, stack_b);
	else if (ft_strcmp(instruction, "rra") == 0)
		reverse_rotate_a(stack);
	else if (ft_strcmp(instruction, "rrb") == 0)
		reverse_rotate_b(stack_b);
	else if (ft_strcmp(instruction, "rrr") == 0)
		r_r_r(stack, stack_b);
	else if (instruction[0] == '\0')
		return (1);
	else
		error_msg(4);
	return (0);
}

void	checker(char *instruction, t_stack_a *stack, t_stack_b *stack_b)
{
	if (ft_strcmp(instruction, "sa") == 0)
		swap_a(stack);
	else if (ft_strcmp(instruction, "sb") == 0)
		swap_b(stack_b);
	else if (ft_strcmp(instruction, "ss") == 0)
		sa_sb(stack, stack_b);
	else if (ft_strcmp(instruction, "pa") == 0)
		push_a(stack, stack_b);
	else if (ft_strcmp(instruction, "pb") == 0)
		push_b(stack_b, stack);
	else if (ft_strcmp(instruction, "ra") == 0)
		rotate_a(stack);
	else if (checker_2(instruction, stack, stack_b))
		return ;
}

int		check_2(char *instruction)
{
	if (ft_strcmp(instruction, "rb") == 0)
		return (0);
	else if (ft_strcmp(instruction, "rr") == 0)
		return (0);
	else if (ft_strcmp(instruction, "rra") == 0)
		return (0);
	else if (ft_strcmp(instruction, "rrb") == 0)
		return (0);
	else if (ft_strcmp(instruction, "rrr") == 0)
		return (0);
	else if (instruction[0] == '\0')
		return (1);
	else
		error_msg(4);
	return (0);
}

void	check(char *instruction)
{
	if (ft_strcmp(instruction, "sa") == 0)
		return ;
	else if (ft_strcmp(instruction, "sb") == 0)
		return ;
	else if (ft_strcmp(instruction, "ss") == 0)
		return ;
	else if (ft_strcmp(instruction, "pa") == 0)
		return ;
	else if (ft_strcmp(instruction, "pb") == 0)
		return ;
	else if (ft_strcmp(instruction, "ra") == 0)
		return ;
	else if (check_2(instruction))
		return ;
}
