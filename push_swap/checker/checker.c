/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 16:19:49 by mwane             #+#    #+#             */
/*   Updated: 2021/04/11 18:16:26 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"checker.h"

void		checker(char *instruction, s_stack_a *stack, s_stack_b *stack_b)
{
	printf("exec operation %s\n", instruction);
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

void	load_instruction(char **instruction, s_stack_a *stack)
{
	int 			ret;
	char			buffer[5];
	int				i;
	s_stack_b		*stack_b;
	
	i = 0;
	stack_b = init_stack(stack->max);
	if (!(instruction = malloc(sizeof(char*) * 100)))
		return ;
	while ((ret = read(0, &buffer, 3)))
	{
		check_space(buffer);
		if (!(instruction[i] = malloc(sizeof(char) * strlen(buffer))))
			return ;
		instruction[i] = buffer;
		instruction[i][ret] = '\0';
		checker(instruction[i], stack, stack_b);
		i++;
	}
}

int     main(int argc, char **argv)
{
	char		**instruction;
	s_stack_a	*stack;
	int 		i;

	stack = init_stack(argc);
	check_args(argc, argv + 1, stack);
	if (!(instruction = malloc(sizeof(char*) * 100)))
		return (0);
	load_instruction(instruction, stack);
	if (sort_checker(stack))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}