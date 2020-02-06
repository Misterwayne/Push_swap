/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:46:12 by mwane             #+#    #+#             */
/*   Updated: 2020/02/06 14:32:36 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int     init_texture(t_param *params)
{
    params->texture->south_img_ptr = 
    mlx_xpm_file_to_image(params->mlx_ptr,params->SO, &params->texture->sizeX1, &params->texture->sizeY1);
    params->texture->north_img_ptr = 
    mlx_xpm_file_to_image(params->mlx_ptr,params->EA, &params->texture->sizeX2, &params->texture->sizeY2);
    params->texture->east_img_ptr = 
    mlx_xpm_file_to_image(params->mlx_ptr,params->NO, &params->texture->sizeX3, &params->texture->sizeY3);
    params->texture->west_img_ptr = 
    mlx_xpm_file_to_image(params->mlx_ptr,params->WE, &params->texture->sizeX4, &params->texture->sizeY4);
    return 0;
}

void    init_data(t_data *data)
{
    data->cam_angle = 0;
    data->cam_height = 0;
    data->cam_posX = 0;
    data->cam_posY = 0;
    data->fov = 0;
    data->screen_size = 0;
    data->map_posX = 0;
    data->map_posY = 0;
}

void    init_ray(t_ray *ray)
{
    ray->dirX = 0;
    ray->dirY = 1;
    ray->planeX = -0.66;
    ray->planeY = 0;
    ray->posx = 0;
    ray->posy = 0;
    ray->x = 0;
    ray->cameraX = 0;
    ray->w = 0;
    ray->h = 0;
    ray->mapX= 0;
    ray->mapX = 0;
    ray->rayDirX = 0;
    ray->rayDirY = 0;
    ray->sidedistX = 0;
    ray->sidedistY = 0;
    ray->deltaDistX = 0;
    ray->deltaDistY = 0;
    ray->perpWallDist = 0;
    ray->stepX = 0;
    ray->stepY = 0;
    ray->hit = 0;
    ray->side = 0;
    ray->lineheight = 0;
    ray->drawstart = 0;
    ray->drawend = 0;
}

int     init_sruct(t_param *params)
{
    params->win_ptr         = 0;
    params->mlx_ptr         = 0;
    params->img_ptr         = 0;
    params->img_ptr2        = 0;
    params->sprite          = 0;
    params->x               = 0;
    params->y               = 0;
    params->NO              = NULL;
    params->SO              = NULL;
    params->WE              = NULL;
    params->EA              = NULL;
    params->S               = NULL;
    params->F               = 0;
    params->r               = 0;
    params->g               = 0;
    params->b               = 0;
    params->C               = 0;
    params->map             = NULL;
    return (0);
}