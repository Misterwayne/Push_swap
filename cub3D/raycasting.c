/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:11:00 by mwane             #+#    #+#             */
/*   Updated: 2020/01/28 15:16:36 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#define mapWidth 29
#define mapHeight 14

// void    init_data(t_param *params)
// {
// 	char *map_img;
// 	int bpp;
// 	int size_line;
// 	int endian;
// 	void *img_ptr3 = NULL;
// 	int sizeX;
// 	int sizeY;
// 	params->img_ptr = mlx_new_image(params->mlx_ptr, params->x, params->y);
// 	map_img = (char *)mlx_get_data_addr(params->img_ptr, &bpp, &size_line, &endian);
// 	img_ptr3 = mlx_xpm_file_to_image(params->mlx_ptr,"brick.XPM", &sizeX, &sizeY);
// 	int bpp2 = 0;
// 	int size_line2 = 0;
// 	int endian2 = 0;
// 	char *texture;
// 	texture = (char *)mlx_get_data_addr(img_ptr3, &bpp2, &size_line2, &endian2);
// }

// void	draw_stripe(int x, t_param *params)
// {
// 	int text_y = 0;
// 	int line_y = params->ray->drawstart;
// 	double wally;
// 	int h = params->y;
// 	int text_x = (int)(params->texture->wallx * (double)params->texture->sizeX);
// 	int d;
// 	double wallx;
// 		if (params->ray->side == 0)
// 			wallx = params->ray->posy + params->ray->perpWallDist * params->ray->rayDirY;
// 		else
// 			wallx = params->ray->x + params->ray->perpWallDist * params->ray->rayDirX;
// 		wallx -= floor(wallx);
// 	while (line_y <= params->ray->drawend)
// 	{
// 		wally = (line_y - params->ray->drawstart) / params->ray->lineheight;
// 		text_y = (int)(wally * (double)params->texture->sizeY);
// 		d = line_y * (params->texture->size_line) - (h) * (params->texture->size_line) / 2 + (params->ray->drawend - params->ray->drawstart) * (params->texture->size_line) / 2;
// 		text_y = ((d * (params->texture->sizeY)) / (params->ray->drawend - params->ray->drawstart)) / (params->texture->size_line);
// 		// printf("line_y : %d | sizeY : %d | text_y = %d\n", line_y, sizeY, text_y);
// 		// printf("Img : %d\n", (x * (bpp/4) + (size_line/4) * line_y));
// 		// printf("Text : %d\n", (((int)text_y * size_line2/4 + text_x * (bpp2/8))))
// 		map_img[(line_y * (size_line) + (x) * (bpp/8))]= params->texture->img[(text_y * params->texture->size_line + (text_x) * (params->texture->bpp/8))];
// 		map_img[(line_y * (size_line) + (x) * (bpp/8)) + 1]= params->texture->img[(text_y * params->texture->size_line + (text_x) * (params->texture->bpp/8)) + 1];
// 		map_img[(line_y * (size_line) + (x) * (bpp/8)) + 2]= params->texture->img[(text_y * params->texture->size_line + (text_x) * (params->texture->bpp/8)) + 2];
// 		line_y++;
// 	}
// }

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
	// params->texture->img_ptr = params->texture->south_img_ptr;
    // mlx_xpm_file_to_image(params->mlx_ptr,"brick.XPM", &params->texture->sizeX, &params->texture->sizeY);
	
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
				params->texture->img_ptr = params->texture->south_img_ptr;
				params->texture->sizeX = params->texture->sizeX1;
				params->texture->sizeY = params->texture->sizeY1;
			}
			else
			{
				params->ray->sidedistY += params->ray->deltaDistY;
				params->ray->mapY += params->ray->stepY;
				params->ray->side = 1;
				params->texture->img_ptr = params->texture->east_img_ptr;
				params->texture->sizeX = params->texture->sizeX2;
				params->texture->sizeY = params->texture->sizeY2;
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
		// if (params->ray->drawend < 0)
		// 	params->ray->drawend = -params->ray->drawend;
		//Sprite
		// double invDet = 1.0 / (params->ray->planeX * params->ray->dirY - params->ray->dirX * params->ray->planeY);
		// double transformX = invDet * (params->ray->dirY * sizeX - params->ray->dirX * sizeY);
		// double transformY = invDet * (-params->ray->planeY * sizeX + params->ray->planeX * sizeY);
		// int spriteScreenX = (w / 2) * (1 + transformX / transformY);
		// int scale = sizeY;
		if (params->ray->side == 0)
			params->texture->wallx = params->ray->posy + params->ray->perpWallDist * params->ray->rayDirY;
		else
			params->texture->wallx = params->ray->posx + params->ray->perpWallDist * params->ray->rayDirX;
		params->texture->wallx -= floor(params->texture->wallx);
		
		int text_y = 0;
		int d;
		int line_y = params->ray->drawstart;
		double wally;
		int text_x = (int)(params->texture->wallx * (double)params->texture->sizeX);
		params->texture->img = (char *)mlx_get_data_addr(params->texture->img_ptr, &params->texture->bpp, &params->texture->size_line, &params->texture->endian);
		// printf("draw start = %d\ndraw end = %d\n",params->ray->drawstart,params->ray->drawend);
		while (line_y <= params->ray->drawend)
		{
			// printf("ik\n");
			wally = (line_y - params->ray->drawstart) / params->ray->lineheight;
			text_y = (int)(wally * (double)params->texture->sizeY);
			d = line_y * (params->texture->size_line) - (h) * (params->texture->size_line) / 2 + (params->ray->drawend - params->ray->drawstart) * (params->texture->size_line) / 2;
			text_y = ((d * (params->texture->sizeY)) / (params->ray->drawend - params->ray->drawstart)) / (params->texture->size_line);
			map_img[(line_y * (size_line) + (x) * (bpp/8))]= params->texture->img [(text_y * params->texture->size_line + (text_x) * (params->texture->bpp/8))];
			map_img[(line_y * (size_line) + (x) * (bpp/8)) + 1]= params->texture->img[(text_y * params->texture->size_line + (text_x) * (params->texture->bpp/8)) + 1];
			map_img[(line_y * (size_line) + (x) * (bpp/8)) + 2]= params->texture->img[(text_y * params->texture->size_line + (text_x) * (params->texture->bpp/8)) + 2];
			line_y++;
		}
		x++;
	}
	return (0);
}