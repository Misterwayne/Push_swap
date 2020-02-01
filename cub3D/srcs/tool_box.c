/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_box.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 11:28:18 by mwane             #+#    #+#             */
/*   Updated: 2020/01/30 15:03:55 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int    get_real_line(int fd, char **line)
{
	int v;

	v = get_next_line(fd, line);
	while (**line == '\0' && v > 0)
	{   
		free(*line);
		v = get_next_line(fd, line);
	}
	return v;
}

void    printf_struct(t_param *params)
{
	int i;

	i = 0;
	printf("C = %d\n",params->C);
	printf("NO = %s\n",params->NO);
	printf("SO = %s\n",params->SO);
	printf("WE = %s\n",params->WE);
	printf("EA = %s\n",params->EA);
	printf("F = %ld\n",params->F);
	printf("r = %d\n",params->r);
	printf("x = %d\n",params->x);
	printf("y = %d\n",params->y);
	printf("g = %d\n",params->g);
	printf("b = %d\n",params->b);
	while (params->map[i] != NULL)
		printf("map = %s\n",params->map[i++]);
}

int       check_params(t_param *params)
{
	if (params->x == 0 || params->y == 0)
		return (1);
	if (params->F == 0 || params->C == 0)
		return (1);
	else
		return (0);
}