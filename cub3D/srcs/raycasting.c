/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:11:00 by mwane             #+#    #+#             */
/*   Updated: 2020/02/06 17:00:54 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	draw_pix(t_param *params, int x)
{
	int line_y;

	line_y = 0;
	params->texture->img = (char *)mlx_get_data_addr(params->texture->img_ptr,
	&params->texture->bpp, &params->texture->size_line,
	&params->texture->endian);
	while (line_y < params->ray->drawstart)
	{
		params->map_info->img[(line_y * (params->map_info->size_line) + (x) *
		(params->map_info->bpp / 8))] = params->C;
		line_y++;
	}
	line_y = draw_wall(0, x, line_y, params);
	while (line_y < params->y)
	{
		params->map_info->img[(line_y * (params->map_info->size_line) + (x) *
		(params->map_info->bpp / 8))] = params->F;
		line_y++;
	}
}

void	load_texture_we_ea(t_param *params)
{
	params->ray->sidedistY += params->ray->deltaDistY;
	params->ray->mapY += params->ray->stepY;
	params->ray->side = 1;
	if (params->ray->stepY < 0)
	{
		params->texture->img_ptr = params->texture->south_img_ptr;
		params->texture->sizeX = params->texture->sizeX1;
		params->texture->sizeY = params->texture->sizeY1;
	}
	else
	{
		params->texture->img_ptr = params->texture->north_img_ptr;
		params->texture->sizeX = params->texture->sizeX2;
		params->texture->sizeY = params->texture->sizeY2;
	}
}

void	load_texture_no_so(t_param *params)
{
	params->ray->sidedistX += params->ray->deltaDistX;
	params->ray->mapX += params->ray->stepX;
	params->ray->side = 0;
	if (params->ray->stepX < 0)
	{
		params->texture->img_ptr = params->texture->west_img_ptr;
		params->texture->sizeX = params->texture->sizeX4;
		params->texture->sizeY = params->texture->sizeY4;
	}
	else
	{
		params->texture->img_ptr = params->texture->east_img_ptr;
		params->texture->sizeX = params->texture->sizeX3;
		params->texture->sizeY = params->texture->sizeY3;
	}
}

void	ray(t_param *params, double camerax, int x)
{
	camerax = ((2 * (double)x) / (double)params->x) - 1;
	calcul_ray(params, camerax);
	if (params->ray->rayDirX < 0)
	{
		params->ray->stepX = -1;
		params->ray->sidedistX = (params->ray->posx - params->ray->mapX) *
		params->ray->deltaDistX;
	}
	else
	{
		params->ray->stepX = 1;
		params->ray->sidedistX = (params->ray->mapX + 1.0 - params->ray->posx)
		* params->ray->deltaDistX;
	}
	ray2(params);
}

int		raycast(t_param *params)
{
	int x;

	x = 0;
	init_ray_data(params);
	while (x < params->x)
	{
		ray(params, 0, x);
		while (params->ray->hit == 0)
		{
			if (params->ray->sidedistX < params->ray->sidedistY)
				load_texture_no_so(params);
			else
				load_texture_we_ea(params);
			if (params->map[params->ray->mapX][params->ray->mapY] == '1')
				params->ray->hit = 1;
		}
		get_depth(params);
		draw_pix(params, x);
		x++;
	}
	return (0);
}
