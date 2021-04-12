/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truepath <truepath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 19:35:22 by truepath          #+#    #+#             */
/*   Updated: 2021/04/11 21:42:39 by truepath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"checker.h"
#include"get_next_line.h"

void		checker(char *instruction, s_stack_a *stack, s_stack_b *stack_b)
{
	if (strcmp(instruction, "sa") == 0)
		swap_a(stack);
	else if (strcmp(instruction, "sb") == 0)
		swap_b(stack_b);
	else if (strcmp(instruction, "ss") == 0)
		sa_sb(stack, stack_b);
	else if (strcmp(instruction, "pa") == 0)
		push_a(stack, stack_b);
	else if (strcmp(instruction, "pb") == 0)
		push_b(stack_b, stack);
	else if (strcmp(instruction, "ra") == 0)
		rotate_a(stack);
	else if (strcmp(instruction, "rb") == 0)
		rotate_b(stack_b);
	else if (strcmp(instruction, "rr") == 0)
		ra_rb(stack, stack_b);
	else if (strcmp(instruction, "rra") == 0)
		reverse_rotate_a(stack);
	else if (strcmp(instruction, "rrb") == 0)
		reverse_rotate_b(stack_b);
	else if (strcmp(instruction, "rrr") == 0)
		r_r_r(stack, stack_b);
	else if (instruction[0] == '\0')
		return ;
	else
		error_msg();
}

void		check_space(char*buffer)
{
	int 	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == ' ' || buffer[i] == '\n')
			buffer[i] = '\0';
		i++;
	}
}

void	load_instruction(s_stack_a *stack)
{
	int 			ret;
	char			*line;
	s_stack_b		*stack_b;
	
	ret = 1;
	stack_b = init_stack(stack->max);
	while (ret > 0)
	{
		ret = get_next_line(0, &line);
		checker(line, stack, stack_b);
	}
	free(stack->a_stack);
	stack->a_stack = stack_b->b_stack;
	stack->top = stack_b->top;

}

int     main(int argc, char **argv)
{
	s_stack_a	*stack;
	int			i;
	char		**arg;

	i = 0;
	arg = ft_split(argv[1], ' ');
	while (arg[i])
		i++;
	argc = i;
	stack = init_stack(argc);
	check_args(argc, arg, stack);
	load_instruction(stack);
	print_stack(stack, NULL);
	if (sort_checker(stack))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}