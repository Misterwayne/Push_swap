/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 12:19:48 by mwane             #+#    #+#             */
/*   Updated: 2020/01/24 17:08:51 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void     check_ini_pos(char **map, t_data *data)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (map[x] != NULL)
	{
			while (map[x][y] != '\0')
		{
			if (map[x][y] == 'N')
			{
				data->map_posY = y + 0.5;
				data->map_posX = x + 0.5;
			}
			y++;
		}
		x++;
		y = 0;
	}
	// printf("x = %d, y = %d\n",data->map_posX,data->map_posY);
}

int		check_map(char **map)
{
	int i;
	int y;

	i = 0;
	y = 0;
	while (map[i][y] != '\0')
	{
		if (map[i][y] == ' ')
			y++;
		if (map[i][y] != '1')
		{
			// printf("%d = y\n",y);
			return (1);
		}
		y++;
	}
	y--;
	while (map[i] != NULL)
	{
		if (map[i][y] != '1')
			return (2);
		i++;
	}
	i--;
	while (y > 0)
	{
		if (map[i][y] == ' ')
			y--;
		if (map[i][y] != '1')
			return (3);
		y--;	
	}
	return (4);
}