/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 16:55:52 by mwane             #+#    #+#             */
/*   Updated: 2020/02/16 15:31:09 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	init_ray_data(t_param *params)
{
	params->ray->posx = params->data->map_posX;
	params->ray->posy = params->data->map_posY;
	params->img_ptr = mlx_new_image(params->mlx_ptr, params->x, params->y);
	params->map_info->img = (char *)mlx_get_data_addr(
	params->img_ptr, &params->map_info->bpp,
	&params->map_info->size_line, &params->map_info->endian);
}

int		draw_celing(int x, int line_y, t_param *params)
{
	int r;
	int g;
	int b;

	r = params->C % 256;
	g = params->C / 256 % 256;
	b = params->C / 256 / 256 % 256;
	while (line_y < params->ray->drawstart)
	{
		params->map_info->img[(line_y * (params->map_info->size_line) + (x) *
		(params->map_info->bpp / 8))] = r;
		params->map_info->img[(line_y * (params->map_info->size_line) + (x) *
		(params->map_info->bpp / 8)) + 1] = g;
		params->map_info->img[(line_y * (params->map_info->size_line) + (x) *
		(params->map_info->bpp / 8)) + 2] = b;
		// params->map_info->img[(line_y * (params->map_info->size_line) + (x) *
		// (params->map_info->bpp / 8)) + 3] = params->C;
		line_y++;
	}
	return (line_y);
}

int		draw_floor(int x, int line_y, t_param *params)
{
	int r;
	int g;
	int b;

	r = params->F % 256;
	g = params->F / 256 % 256;
	b = params->F / 256 / 256 % 256;
	while (line_y < params->y)
	{
		params->map_info->img[(line_y * (params->map_info->size_line) + (x) *
		(params->map_info->bpp / 8))] = r;
		params->map_info->img[(line_y * (params->map_info->size_line) + (x) *
		(params->map_info->bpp / 8)) + 1] = g;
		params->map_info->img[(line_y * (params->map_info->size_line) + (x) *
		(params->map_info->bpp / 8)) + 2] = b;
		line_y++;
	}
	return (line_y);
}

void	ray2(t_param *params)
{
	if (params->ray->rayDirY < 0)
	{
		params->ray->stepY = -1;
		params->ray->sidedistY = (params->ray->posy - params->ray->mapY)
		* params->ray->deltaDistY;
	}
	else
	{
		params->ray->stepY = 1;
		params->ray->sidedistY = (params->ray->mapY + 1.0 - params->ray->posy)
		* params->ray->deltaDistY;
	}
}
