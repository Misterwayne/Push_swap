/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:46:12 by mwane             #+#    #+#             */
/*   Updated: 2020/02/10 18:42:12 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int     init_texture(t_param *params)
{
    params->sprite->img_ptr = mlx_xpm_file_to_image(params->mlx_ptr, params->S,
    &params->sprite->size_x, &params->sprite->size_y);
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

void    init_text(t_texture *tex)
{
    tex = 0;
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
    ray = 0;
}

int     init_sruct(t_param *params, t_sprites *sprite, t_data *data, t_ray *ray)
{
    sprite = 0;
    ray = 0;
    params = 0;
    return (0);
}