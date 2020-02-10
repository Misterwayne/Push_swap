/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 14:28:28 by mwane             #+#    #+#             */
/*   Updated: 2020/02/10 19:02:55 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"


void    init_sprite(t_param *params)
{
    int i;

    i = 0;
    while (i < 4)
    {
        // params->sprite->sprite_orders = i;
        params->sprite->sprite_distance =
        ((params->ray->posx - params->ray->mapX) * 
        (params->ray->posx - params->ray->mapX) +
        (params->ray->posy - params->ray->mapY) *
        (params->ray->posy - params->ray->mapY));
        i++;
    }
}

void    draw_sprite(t_param *params, int i, int x)
{
    int text_y;
    int text_x;
    int stripe;
    int y;
    int d;
    
    stripe = params->sprite->draw_startX;
    while (stripe < params->sprite->draw_endX)
    {
        // printf("draw");
        text_x = (int)(256 * (stripe - (-params->sprite->spriteWidth 
        / 2 + params->sprite->spriteScreenX)) *
        params->sprite->size_x / params->sprite->spriteWidth)
        / 256;
        if (params->sprite->transY > 0 && stripe > 0 &&
        stripe < params->x)
        {
            y = params->sprite->draw_startY;
            while (y < params->sprite->draw_startY)
            {
                // printf("pix");
                d = (y) * 256 - params->y * 128 +
                params->sprite->spriteHeight * 128;
                text_y = ((d * params->sprite->size_y) / params->sprite->spriteHeight)
                / 256;
                params->map_info->img[(stripe * (params->map_info->size_line) + (x) *
		        (params->map_info->bpp / 8))] = params->sprite->img[(text_y *
                params->sprite->size_line + (text_x) * (params->sprite->bpp / 8))];
                y++;
            }
        }
        stripe++;
    }
}

void    cal_sprite_height(t_param *params, int i)
{
    params->sprite->spriteHeight = fabs(params->y/params->sprite->transY);
    params->sprite->draw_startY = params->sprite->spriteHeight / 2 + params->y / 2;
    if (params->sprite->draw_startY < 0)
        params->sprite->draw_startY = 0;
    params->sprite->draw_endY = -params->sprite->spriteHeight / 2 + params->y / 2;
    if (params->sprite->draw_endY >= params->y)
        params->sprite->draw_endY = params->y - 1;
    params->sprite->spriteWidth = fabs(params->y/params->sprite->transY);
    params->sprite->draw_startX = -params->sprite->spriteWidth /
    2 + params->sprite->spriteScreenX;
    if (params->sprite->draw_startX < 0)
        params->sprite->draw_startX = 0;
    params->sprite->draw_endX = params->sprite->spriteWidth /
    2 + params->sprite->spriteScreenX;
    if (params->sprite->draw_endX >= params->x)
        params->sprite->draw_endX = params->x - 1;
}

void    cal_sprite_dist(t_param *params, int x)
{
    int i;

    i = 0;
    // while (i < 4)
    // {
        params->sprite->spriteX = params->sprite->x - params->ray->posx;
        params->sprite->spriteY = params->sprite->y - params->ray->posy;
        params->sprite->indet = 1.0 / (params->ray->planeX * params->ray->dirY
        - params->ray->dirX * params->ray->planeY);
        params->sprite->transX = params->sprite->indet *
        (params->ray->dirY * params->sprite->spriteX -
        params->ray->dirX * params->sprite->spriteY);
        params->sprite->transY = params->sprite->indet *
        (-params->ray->planeY * params->sprite->spriteX -
        params->ray->planeX * params->sprite->spriteX);
        params->sprite->spriteScreenX = (int)(params->x/2) *
        (1 + params->sprite->transX / params->sprite->transY);
        cal_sprite_height(params , i);
        // i++;
    // }
}

int     sprite(t_param *params, int x)
{
    // double ZBuffer[params->x];
    int i;

    i = 0;
    params->sprite->img = mlx_get_data_addr(params->sprite->img_ptr,
    &params->sprite->bpp, &params->sprite->size_line, &params->sprite->endian);
    // printf("spriteto");
    // ZBuffer[x] = params->ray->perpWallDist;
    init_sprite(params);
    // sort_sprite(params);
    // printf("spriteto");
    cal_sprite_dist(params, x);
    return (0);
}