/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 12:19:48 by mwane             #+#    #+#             */
/*   Updated: 2020/02/14 16:03:24 by mwane            ###   ########.fr       */
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
	get_pos2(map, params, x, y);
}

int		check_sprt_pos(char **map, t_param *params)
{
	int x;
	int y;
	int	i;

	i = 0;
	x = 0;
	y = 0;
	if(!(params->sprite->sprt_list = malloc(sizeof(char*) * params->numsprite + 1)))
		return (0);
	params->sprite->sprt_list[params->numsprite] = NULL;
	while (map[x] != NULL)
	{
		while (map[x][y] != '\0')
		{
			if (map[x][y] == '2')
				get_sprite(params,y ,x,i++);
			y++;
		}
		x++;
		y = 0;
	}
	i = 0;
	return (0);
}

void	check_ini_pos(char **map, t_param *params)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (map[x] != NULL)
	{
		while (map[x][y] != '\0')
		{
			if (map[x][y] == '2')
				params->numsprite += 1;
			get_pos(map,params,x,y);
			y++;
		}
		x++;
		y = 0;
	}
	check_sprt_pos(map, params);
}

int		check_map(char **map)
{
	int i;
	int y;

	i = 0;
	y = 0;
	while (map[i])
	{
		if (map[i][0] != '1')
			return (1);
		while (map[i][y])
			y++;
		if (map[i][y-1] != '1')
			return (1);
		i++;
		y = 0;
	}
	return (check_map2(map));
}

int		check_map2(char **map)
{
	int i;
	int y;

	i = 0;
	y = 0;
	while (map[i][y])
	{
		if (map[0][y] != '1')
			return (1);
		while (map[i] != NULL)
			i++;
		if (map[i - 1][y] != '1')
			return (1);
		y++;
		i = 0;
	}
	return (0);
}