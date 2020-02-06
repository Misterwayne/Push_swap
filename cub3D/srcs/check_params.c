/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 12:19:48 by mwane             #+#    #+#             */
/*   Updated: 2020/02/06 14:31:31 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	get_pos(char **map, t_param *params, int x, int y)
{
	if (map[x][y] == 'N')
	{
		params->data->map_posY = y;
		params->data->map_posX = x;
		params->ray->dirX = -1;
		params->ray->dirY = 0;
		params->ray->planeX = 0;
    	params->ray->planeY = 0.66;

	}
	else if (map[x][y] == 'W')
	{
		params->data->map_posY = y;
		params->data->map_posX = x;
		params->ray->dirX = 0;
		params->ray->dirY = -1;
		params->ray->planeX = -0.66;
    	params->ray->planeY = 0;
	}
	else if (map[x][y] == 'S')
	{
		params->data->map_posY = y;
		params->data->map_posX = x;
		params->ray->dirX = 1;
		params->ray->dirY = 0;
		params->ray->planeX = 0;
    	params->ray->planeY = -0.66;
	}
	else if (map[x][y] == 'E')
	{
		params->data->map_posY = y;
		params->data->map_posX = x;
		params->ray->dirX = 0;
		params->ray->dirY = 1;
		params->ray->planeX = 0.66;
    	params->ray->planeY = 0.0;
	}
}

void     check_ini_pos(char **map, t_param *params)
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
				params->data->map_posY = y;
				params->data->map_posX = x;
			}
			get_pos(map,params,x,y);
			y++;
		}
		x++;
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
			return (1);
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