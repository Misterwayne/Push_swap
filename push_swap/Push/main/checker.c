/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 19:35:22 by truepath          #+#    #+#             */
/*   Updated: 2021/04/15 16:07:26 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../header/checker.h"
#include"../header/get_next_line.h"

int	checker_2(char *instruction, s_stack_a *stack, s_stack_b *stack_b)
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
		error_msg();
	return (0);
}

void	checker(char *instruction, s_stack_a *stack, s_stack_b *stack_b)
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

int	check_2(char *instruction)
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
		error_msg();
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

void	check_space(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == ' ' || buffer[i] == '\n')
			buffer[i] = '\0';
		i++;
	}
}

void	check_instruction(void)
{
	int			ret;
	char		*line;

	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(0, &line);
		check(line);
		free(line);
	}
}

void	load_instruction(s_stack_a *stack, s_stack_b *stack_b)
{
	int			ret;
	char		*line;

	ret = 1;
	check_instruction();
	while (ret > 0)
	{
		ret = get_next_line(0, &line);
		checker(line, stack, stack_b);
		free(line);
	}
	free(stack->a_stack);
	stack->a_stack = stack_b->b_stack;
	stack->top = stack_b->top;
	stack_b->top = -1;
}

int	main(int argc, char **argv)
{
	s_stack_a	*stack;
	s_stack_b	*stack_b;
	int			i;
	char		**arg;

	i = 0;
	if (argc < 3)
	{
		arg = ft_split(argv[1], ' ');
		while (arg[i])
			i++;
		argc = i;
	}
	else
	{
		arg = argv + 1;
		argc--;
	}
	stack = init_stack(argc);
	stack_b = init_stack(stack->max);
	check_args(argc, arg, stack);
	if (sort_checker(stack))
		write(1, "OK\n", 3);
	else
		load_instruction(stack, stack_b);
	if (sort_checker(stack))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}
