/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 12:19:48 by mwane             #+#    #+#             */
/*   Updated: 2019/12/29 13:09:11 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void     check_ini_pos(char **map, t_data *data)
{
	int i;
	int y;

	i = 0;
	y = 0;
	while (map[i] != NULL)
	{
		while (map[i][y] != '\0')
		{
			if (map[i][y] == 'N')
			{
				data->cam_posX = i;
				data->cam_posY = y;
			}
			y++;
		}
		i++;
		y = 0;
	}
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
			printf("%d = y\n",y);
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