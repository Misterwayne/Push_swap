/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 14:28:28 by mwane             #+#    #+#             */
/*   Updated: 2020/02/14 16:01:34 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"


int    init_sprite(t_param *params, int i)
{
    if (!(params->sprite->sprite_distance = malloc(sizeof(double) * params->numsprite)))
        return (0);
    params->sprite->sprite_distance[i] =
    ((params->ray->posx - params->sprite->sprt_list[i][0]) * 
    (params->ray->posx - params->sprite->sprt_list[i][0]) +
    (params->ray->posy - params->sprite->sprt_list[i][1]) *
    (params->ray->posy - params->sprite->sprt_list[i][1]));
    return (params->sprite->sprite_distance[i]);
}

void    draw_sprite(t_param *params, int x, double *zbuffer)
{
    int text_y;
    int text_x;
    int stripe;
    int y;
    int d;
    
    stripe = params->sprite->draw_startX;
    while (stripe < params->sprite->draw_endX)
    {
        text_x = (int)(256 * (stripe - (-params->sprite->spriteWidth 
        / 2 + params->sprite->spriteScreenX)) *
        params->sprite->size_x / params->sprite->spriteWidth)
        / 256;
        if (params->sprite->transY > 0 && stripe > 0 &&
        stripe < params->x && params->sprite->transY < zbuffer[stripe])
            print_sprite(y ,stripe, text_x, params);
        stripe++;
    }
}

void    cal_sprite_height(t_param *params, int i)
{
    params->sprite->spriteHeight = fabs((params->y/(params->sprite->transY)));
    params->sprite->draw_startY = (int)(-params->sprite->spriteHeight / 2 + params->y / 2);
    params->sprite->draw_endY = (int)(params->sprite->spriteHeight / 2 + params->y / 2);
    if (params->sprite->draw_endY >= params->y)
        params->sprite->draw_endY = params->y - 1;
    params->sprite->spriteWidth = fabs(params->y/params->sprite->transY);
    params->sprite->draw_startX = -params->sprite->spriteWidth /
    2 + params->sprite->spriteScreenX;
    params->sprite->draw_endX = params->sprite->spriteWidth /
    2 + params->sprite->spriteScreenX;
    if (params->sprite->draw_endX >= params->x)
        params->sprite->draw_endX = params->x - 1;
}

void    cal_sprite_dist(t_param *params, int x)
{
    params->sprite->spriteY = params->sprite->y - params->ray->posy;
    params->sprite->spriteX = params->sprite->x - params->ray->posx;
    params->sprite->indet = 1.0 / ((params->ray->planeX * params->ray->dirY)
    - (params->ray->dirX * params->ray->planeY));
    params->sprite->transX = params->sprite->indet *
    ((params->ray->dirY * params->sprite->spriteX) -
    (params->ray->dirX * params->sprite->spriteY));
    params->sprite->transY = params->sprite->indet *
    (-params->ray->planeY * params->sprite->spriteX +
    params->ray->planeX * params->sprite->spriteY);
    params->sprite->spriteScreenX = (int)(params->x/2) *
    (1 + params->sprite->transX / params->sprite->transY);
    cal_sprite_height(params , 0);
}

int     sprite(t_param *params, int x, double *zbuffer)
{
    if (!(params->sprite->img = mlx_get_data_addr(params->sprite->img_ptr,
    &params->sprite->bpp, &params->sprite->size_line, &params->sprite->endian)))
        error_msg("error texture sprite", params);
    params->sprite->x = params->sprite->sprt_list[x][0] + 0.5;
    params->sprite->y = params->sprite->sprt_list[x][1] + 0.5;
    init_sprite(params, x);
    cal_sprite_dist(params, x);
    draw_sprite(params, 0,zbuffer);
    return (0);
}