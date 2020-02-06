/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 16:55:52 by mwane             #+#    #+#             */
/*   Updated: 2020/02/06 17:02:23 by mwane            ###   ########.fr       */
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
