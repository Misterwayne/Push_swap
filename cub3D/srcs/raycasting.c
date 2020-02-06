/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:11:00 by mwane             #+#    #+#             */
/*   Updated: 2020/02/06 14:35:41 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int     raycast(t_param *params)
{
	params->ray->posx = params->data->map_posX;
	params->ray->posy = params->data->map_posY;//x and y start position
	
	char *map_img;
	int bpp;
	int size_line;
	int endian;
	params->img_ptr = mlx_new_image(params->mlx_ptr, params->x, params->y);
	map_img = (char *)mlx_get_data_addr(params->img_ptr, &bpp, &size_line, &endian);
	int x = 0;
	double cameraX = 0;
	int w = params->x;
	int h = params->y;
	
	while (x < w)
	{
		cameraX = ((2 * (double)x) / (double)w) - 1;
		params->ray->rayDirX = params->ray->dirX + params->ray->planeX * cameraX;
		params->ray->rayDirY = params->ray->dirY + params->ray->planeY * cameraX;

		params->ray->mapX = (int)params->ray->posx;
		params->ray->mapY = (int)params->ray->posy;
				
		params->ray->deltaDistX = fabs((1 / params->ray->rayDirX));
		params->ray->deltaDistY = fabs((1 / params->ray->rayDirY));

		params->ray->hit = 0;
		
		if (params->ray->rayDirX < 0)
		{
			params->ray->stepX = -1;
			params->ray->sidedistX = (params->ray->posx - params->ray->mapX) * params->ray->deltaDistX;
		}
		else
		{
			params->ray->stepX = 1;
			params->ray->sidedistX = (params->ray->mapX + 1.0 - params->ray->posx) * params->ray->deltaDistX;
		}
		if (params->ray->rayDirY < 0)
		{
			params->ray->stepY = -1;
			params->ray->sidedistY = (params->ray->posy - params->ray->mapY) * params->ray->deltaDistY;
		}
		else
		{
			params->ray->stepY = 1;
			params->ray->sidedistY = (params->ray->mapY + 1.0 - params->ray->posy) * params->ray->deltaDistY;
		}
		while (params->ray->hit == 0)
		{
			if (params->ray->sidedistX < params->ray->sidedistY)
			{
				params->ray->sidedistX += params->ray->deltaDistX;
					params->ray->mapX += params->ray->stepX;
					params->ray->side = 0;
				if (params->ray->stepX < 0 )
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
			else
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
			if (params->map[params->ray->mapX][params->ray->mapY] == '1')
				params->ray->hit = 1;
		}
		if (params->ray->side == 0)
			params->ray->perpWallDist = (double)(((double)params->ray->mapX - params->ray->posx + (1 - (double)params->ray->stepX) / 2) / params->ray->rayDirX);
		else
			params->ray->perpWallDist = (double)(((double)params->ray->mapY - params->ray->posy + (1 - (double)params->ray->stepY) / 2) / params->ray->rayDirY);
		params->ray->lineheight = (int)(h / params->ray->perpWallDist);
		params->ray->drawstart = -params->ray->lineheight / 2 + (h / 2);
		if (params->ray->drawstart < 0)
		    params->ray->drawstart = 0;
		params->ray->drawend = params->ray->lineheight / 2 + h / 2;
		if (params->ray->drawend >= h)
		    params->ray->drawend = h - 1;
		if (params->ray->side == 0)
			params->texture->wallx = params->ray->posy + params->ray->perpWallDist * params->ray->rayDirY;
		else
			params->texture->wallx = params->ray->posx + params->ray->perpWallDist * params->ray->rayDirX;
		params->texture->wallx -= floor(params->texture->wallx);
		int text_y = 0;
		int d;
		int line_y = 0;
		double wally;
		int text_x = (int)(params->texture->wallx * (double)params->texture->sizeX);
		params->texture->img = (char *)mlx_get_data_addr(params->texture->img_ptr, &params->texture->bpp, &params->texture->size_line, &params->texture->endian);
		while (line_y < params->ray->drawstart)
		{
			map_img[(line_y * (size_line) + (x) * (bpp/8))] = params->C;
			line_y++;
		}
			while (line_y < params->ray->drawend)
			{
				wally = (line_y - params->ray->drawstart) / params->ray->lineheight;
				text_y = (int)(wally * (double)params->texture->sizeY);
				d = line_y * (params->texture->size_line) - (h) * (params->texture->size_line) / 2 + (params->ray->drawend - params->ray->drawstart) * (params->texture->size_line) / 2;
				text_y = ((d * (params->texture->sizeY)) / (params->ray->drawend - params->ray->drawstart)) / (params->texture->size_line);
				map_img[(line_y * (size_line) + (x) * (bpp/8))]= params->texture->img [(text_y * params->texture->size_line + (text_x) * (params->texture->bpp/8))];
				map_img[(line_y * (size_line) + (x) * (bpp/8)) + 1]= params->texture->img[(text_y * params->texture->size_line + (text_x) * (params->texture->bpp/8)) + 1];
				map_img[(line_y * (size_line) + (x) * (bpp/8)) + 2]= params->texture->img[(text_y * params->texture->size_line + (text_x) * (params->texture->bpp/8)) + 2];
				line_y++;
			}
		while (line_y < h)
		{
			map_img[(line_y * (size_line) + (x) * (bpp/8))] = params->F;
			line_y++;
		}
		x++;
	}
	/*if (params->sprite == 1)
	{
		save_bitmap(params, map_img);
		destroy_window(params);
	}*/
	return (0);
}