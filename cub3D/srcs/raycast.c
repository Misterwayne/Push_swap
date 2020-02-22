/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 16:55:52 by mwane             #+#    #+#             */
/*   Updated: 2020/02/21 16:43:50 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_ray_data(t_param *params)
{
	params->ray->posx = params->map_x;
	params->ray->posy = params->map_y;
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

	r = params->c % 256;
	g = params->c / 256 % 256;
	b = params->c / 256 / 256 % 256;
	while (line_y < params->ray->drawstart)
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

int		draw_floor(int x, int line_y, t_param *params)
{
	int r;
	int g;
	int b;

	r = params->f % 256;
	g = params->f / 256 % 256;
	b = params->f / 256 / 256 % 256;
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
	if (params->ray->raydiry < 0)
	{
		params->ray->stepy = -1;
		params->ray->sidedisty = (params->ray->posy - params->ray->map_y)
		* params->ray->deltadisty;
	}
	else
	{
		params->ray->stepy = 1;
		params->ray->sidedisty = (params->ray->map_y + 1.0 - params->ray->posy)
		* params->ray->deltadisty;
	}
}
