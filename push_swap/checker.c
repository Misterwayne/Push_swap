/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 16:19:49 by mwane             #+#    #+#             */
/*   Updated: 2021/04/08 18:07:53 by mwane            ###   ########.fr       */
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
		{
			if (strcmp(stack[i], item) == 0)
				return (1);
		}
	}
	return (0);
}

void    check_args(int argc, char **args, s_stack_a *stack)
{
	int		i;
	char	*item;

	i = 0;
	while (args[i])
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
		i++;
	}
}

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
	else
		printf("error %s\n",instruction);
	printf("exec operation %s\n", instruction);
	print_stack(stack, stack_b);
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
	int 	ret;
	char	buffer[5];
	int		i;
	s_stack_b		*stack_b;
	
	i = 0;
	stack_b = init_stack(stack->max);
	instruction = malloc(sizeof(char*) * 100);
	while ((ret = read(0, &buffer, 3)))
	{
		check_space(buffer);
		instruction[i] = malloc(sizeof(char) * strlen(buffer));
		instruction[i] = buffer;
		instruction[i][ret] = '\0';
		printf("%s = %d\n", buffer, ret);
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
	print_stack(stack, NULL);
	instruction = malloc(sizeof(char*) * 100);
	load_instruction(instruction, stack);
	if (i > 0)
		printf("ERROR at instruction %d\n",i);
	return (0);
}