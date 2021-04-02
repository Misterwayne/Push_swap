/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 16:19:49 by mwane             #+#    #+#             */
/*   Updated: 2021/04/02 17:27:41 by mwane            ###   ########.fr       */
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

void    check_args(int argc, char **args)
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
		i++;
	}
	printf("OK");
}

int     main(int argc, char **argv)
{
	check_args(argc, argv + 1);

	return (0);
}