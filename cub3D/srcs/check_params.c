/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 12:19:48 by mwane             #+#    #+#             */
/*   Updated: 2020/02/23 19:37:34 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		get_pos(char **map, t_param *params, int x, int y)
{
	if (map[x][y] == 'N')
	{
		if (params->map_y == 0)
		{
			params->map_y = y + 0.5;
			params->map_x = x + 0.5;
			params->ray->vecx = -1;
			params->ray->vecy = 0;
			params->ray->planex = 0;
			params->ray->planey = 0.66;
		}
		else
			error_msg("error spawn point N", params);
		return (1);
	}
	return (get_pos_w(map, params, x, y));
}

int		get_pos_w(char **map, t_param *params, int x, int y)
{
	if (map[x][y] == 'W')
	{
		if (params->map_y == 0)
		{
			params->map_y = y + 0.5;
			params->map_x = x + 0.5;
			params->ray->vecx = 0;
			params->ray->vecy = -1;
			params->ray->planex = -0.66;
			params->ray->planey = 0;
		}
		else
			error_msg("error spawn point W", params);
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
	if (!(params->sprite->sprt_list = malloc(sizeof(char *)
	* params->numsprite + 1)))
		return (0);
	params->sprite->sprt_list[params->numsprite] = NULL;
	while (map[x] != NULL)
	{
		while (map[x] != NULL && map[x][y] != '\0')
		{
			if (map[x][y] == '2')
				get_sprite(params, y, x, i++);
			y++;
		}
		x++;
		y = 0;
	}
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
		while (map[x] != NULL && map[x][y] != '\0')
		{
			if (map[x][y] == '2')
				params->numsprite += 1;
			if (map[x][y] != '1' && map[x][y] != '2'
			&& map[x][y] != '0' && map[x][y] != ' '
			&& get_pos(map, params, x, y) == 0)
				error_msg("error map 3\n", params);
			y++;
		}
		x++;
		y = 0;
	}
	if (params->map_x == 0 && params->map_y == 0)
		error_msg("no spawn point\n", params);
	check_sprt_pos(map, params);
}

int		check_map(char **map)
{
	int i;
	int y;

	i = 0;
	while (i < 14 && map[i] != NULL)
	{
		y = 0;
		if (map[i][y] != '1')
			return (1);
		while (map[i][y])
			y++;
		if (map[i][y - 1] != '1')
			return (1);
		i++;
	}
	return (check_map2(map));
}
