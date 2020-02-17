/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 12:19:48 by mwane             #+#    #+#             */
/*   Updated: 2020/02/17 16:26:08 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int		get_pos(char **map, t_param *params, int x, int y)
{
	if (map[x][y] == 'N')
	{
		if (params->data->map_posY == 0)
		{
			params->data->map_posY = y + 0.5;
			params->data->map_posX = x + 0.5;
			params->ray->dirX = -1;
			params->ray->dirY = 0;
			params->ray->planeX = 0;
    		params->ray->planeY = 0.66;
		}
		else
			error_msg("error spawn point N",params);
		return (1);
	}
	else if (map[x][y] == 'W')
	{
		if (params->data->map_posY == 0)
		{
			params->data->map_posY = y + 0.5;
			params->data->map_posX = x + 0.5;
			params->ray->dirX = 0;
			params->ray->dirY = -1;
			params->ray->planeX = -0.66;
    		params->ray->planeY = 0;
		}
		else
			error_msg("error spawn point W",params);
		return (1);
	}
	if (get_pos2(map, params, x, y) == 1)
		return (1);
	return (0);
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
			// while (map[x][y] == ' ')
			// 	y++;
			if (map[x][y] == '2')
				params->numsprite += 1;
			if (map[x][y] != '1' && map[x][y] != '2'
			&& map[x][y] != '0' && map[x][y] != ' '
			&& get_pos(map,params,x,y) == 0)
				error_msg("error map 3\n",params);
			y++;
		}
		x++;
		y = 0;
	}
	if (params->data->map_posX == 0 && params->data->map_posY == 0)
		error_msg("no spawn point\n",params);
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
		y = 0;
		while (map[i][y] == ' ')
			y++;
		if (map[i][y] != '1')
			return (1);
		while (map[i][y] && map[i][y] != ' ')
			y++;
		if (map[i][y - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}

int		check_map2(char **map)
{
	int i;
	int y;

	i = 0;
	y = 0;
	while (map[i][y])
	{
		while (map[i] != NULL && map[i][y] == ' ')
			i++;
		if (map[i][y] != '1')
			printf(" 3 |%c| in x : %d,y : %d\n",map[i][y],i,y);
		while (map[i] != NULL && map[i][y] == ' ')
			i++;
		if (map[i - 1][y] != '1')
			printf(" 4 |%c| in x : %d,y : %d\n",map[i - 1][y],i,y);
		y++;
		i = 0;
	}
	return (1);
}