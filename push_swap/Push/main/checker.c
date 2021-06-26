/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 19:35:22 by truepath          #+#    #+#             */
/*   Updated: 2021/06/04 17:13:15 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/checker.h"
#include "../header/get_next_line.h"

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

void	load_instruction(t_stack_a *stack, t_stack_b *stack_b)
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
	if (sort_checker(stack, stack_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_stack_a	*stack;
	t_stack_b	*stack_b;
	int			i;
	char		**arg;

	i = -1;
	arg = argv + 1;
	if (argc < 3)
	{
		arg = ft_split(argv[0], ' ');
		while (arg[++i])
			argc = i;
	}
	else
		argc--;
	stack = init_stack(argc);
	stack_b = init_stack(stack->max);
	if (sort_checker(stack, stack_b))
		write(1, "OK\n", 3);
	else
	{
		check_args(argc, arg, stack, stack_b);
		load_instruction(stack, stack_b);
	}
	return (0);
}
