/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 15:48:45 by mwane             #+#    #+#             */
/*   Updated: 2020/02/12 13:40:00 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	get_depth2(t_param *params)
{
	params->ray->lineheight = (int)(params->y / params->ray->perpWallDist);
	params->ray->drawstart = -params->ray->lineheight / 2 + (params->y / 2);
	params->ray->drawend = params->ray->lineheight / 2 + params->y / 2;
	if (params->ray->drawend >= params->y)
		params->ray->drawend = params->y - 1;
	if (params->ray->side == 0)
	{
		params->texture->wallx = params->ray->posy + params->ray->perpWallDist *
		params->ray->rayDirY;
	}
	else
	{
		params->texture->wallx = params->ray->posx + params->ray->perpWallDist *
		params->ray->rayDirX;
	}
}

void	adjust_dist(t_param *params, int *d, int *text_y, int line_y)
{
	*d = line_y * (params->texture->size_line) - (params->y) *
	(params->texture->size_line) / 2 +
	(params->ray->drawend - params->ray->drawstart) *
	(params->texture->size_line) / 2;
	*text_y = ((*d * (params->texture->sizeY)) /
	(params->ray->drawend - params->ray->drawstart)) /
	(params->texture->size_line);
}

void	calcul_ray(t_param *params, double camerax)
{
	params->ray->rayDirX = params->ray->dirX + params->ray->planeX * camerax;
	params->ray->rayDirY = params->ray->dirY + params->ray->planeY * camerax;
	params->ray->mapX = (int)params->ray->posx;
	params->ray->mapY = (int)params->ray->posy;
	params->ray->deltaDistX = fabs((1 / params->ray->rayDirX));
	params->ray->deltaDistY = fabs((1 / params->ray->rayDirY));
	params->ray->hit = 0;
}

void	get_depth(t_param *params)
{
	if (params->ray->side == 0)
	{
		params->ray->perpWallDist =
		(double)(((double)params->ray->mapX - params->ray->posx +
		(1 - (double)params->ray->stepX) / 2) / params->ray->rayDirX);
	}
	else
	{
		params->ray->perpWallDist =
		(double)(((double)params->ray->mapY - params->ray->posy +
		(1 - (double)params->ray->stepY) / 2) / params->ray->rayDirY);
	}
	get_depth2(params);
	params->texture->wallx -= floor(params->texture->wallx);
}

int		draw_wall(int text_x, int x, int line_y, t_param *params)
{
	int		text_y;
	int		d;
	double	wally;

	text_x = (int)(params->texture->wallx * (double)params->texture->sizeX);
	while (line_y < params->ray->drawend)
	{
		wally = (line_y - params->ray->drawstart) / params->ray->lineheight;
		text_y = (int)(wally * (double)params->texture->sizeY);
		adjust_dist(params, &d, &text_y, line_y);
		params->map_info->img[(line_y * (params->map_info->size_line) +
		(x) * (params->map_info->bpp / 8))] =
		params->texture->img[(text_y * params->texture->size_line +
		(text_x) * (params->texture->bpp / 8))];
		params->map_info->img[(line_y * (params->map_info->size_line) +
		(x) * (params->map_info->bpp / 8)) + 1] =
		params->texture->img[(text_y * params->texture->size_line +
		(text_x) * (params->texture->bpp / 8)) + 1];
		params->map_info->img[(line_y * (params->map_info->size_line) +
		(x) * (params->map_info->bpp / 8)) + 2] =
		params->texture->img[(text_y * params->texture->size_line +
		(text_x) * (params->texture->bpp / 8)) + 2];
		line_y++;
	}
	return (line_y);
}
