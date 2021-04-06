/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 16:19:49 by mwane             #+#    #+#             */
/*   Updated: 2021/04/06 15:44:51 by mwane            ###   ########.fr       */
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

char	**load_instruction(char **instruction)
{
	int 	ret;
	char	buffer[3];
	int		i;
	
	i = 0;
	while ((ret = read(0, &buffer, 3)))
	{
		buffer[ret] = '\0';
		instruction[i] = malloc(sizeof(char) * strlen(buffer));
		instruction[i] = buffer;
		instruction[i][strlen(buffer)] = '\0';
		printf("%s = %d\n", instruction[i], i);
		i++;
	}
	instruction[i] = NULL;
	return (instruction);
}

int		checker(char **instruction, s_stack_a *stack)
{
	int 			i;
	s_stack_b		*stack_b;

	i = 0;
	stack_b = init_stack(stack->top);
	while (instruction[i] != NULL)
	{
		if (strcmp(instruction[i], "sa") == 0)
			swap_a(stack);
		else if (strcmp(instruction[i], "sb") == 0)
			swap_b(stack_b);
		else if (strcmp(instruction[i], "ss") == 0)
			sa_sb(stack, stack_b);
		else if (strcmp(instruction[i], "ss") == 0)
			push_a(stack, stack_b);
		else if (strcmp(instruction[i], "ss") == 0)
			push_b(stack_b, stack);
		else if (strcmp(instruction[i], "ss") == 0)
			rotate_a(stack);
		else if (strcmp(instruction[i], "ss") == 0)
			rotate_b(stack_b);
		else if (strcmp(instruction[i], "ss") == 0)
			ra_rb(stack, stack_b);
		else if (strcmp(instruction[i], "ss") == 0)
			reverse_rotate_a(stack);
		else if (strcmp(instruction[i], "ss") == 0)
			reverse_rotate_b(stack_b);
		else if (strcmp(instruction[i], "ss") == 0)
			r_r_r(stack, stack_b);
		else
			return (i); 
		i++;
	}
	return (0);
}

int     main(int argc, char **argv)
{
	char		**instruction;
	s_stack_a	*stack;
	int 		i;

	instruction = malloc(sizeof(char*) * 100);
	instruction = load_instruction(instruction);
	stack = init_stack(argc);
	check_args(argc, argv + 1, stack);
	print_stack(stack, NULL);
	printf("ERROR %s\n",instruction[2]);
	i = checker(instruction, stack);
	if (i > 0)
	{
		printf("ERROR at instruction %d\n",i);
	}
	print_stack(stack, NULL);
	
	return (0);
}