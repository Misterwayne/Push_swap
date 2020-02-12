/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 18:12:26 by mwane             #+#    #+#             */
/*   Updated: 2020/02/12 13:26:07 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void    move_forward(t_param *params)
{
	if (params->map[(int)(params->data->map_posX + params->ray->dirX * 0.1)]
	[(int)(params->data->map_posY)] != '1'
	&& params->map[(int)(params->data->map_posX + params->ray->dirX * 0.1)]
	[(int)(params->data->map_posY)] != '2')
		params->data->map_posX += params->ray->dirX * 0.1;
	if (params->map[(int)(params->data->map_posX)]
	[(int)(params->data->map_posY + params->ray->dirY * 0.1)] != '1'
	&& params->map[(int)(params->data->map_posX)]
	[(int)(params->data->map_posY + params->ray->dirY * 0.1)] != '2')	
			params->data->map_posY += params->ray->dirY * 0.1;
}

void    move_back(t_param *params)
{
	if (params->map[(int)(params->data->map_posX - params->ray->dirX * 0.1)]
	[(int)(params->data->map_posY)] != '1'
	&& params->map[(int)(params->data->map_posX - params->ray->dirX * 0.1)]
	[(int)(params->data->map_posY)] != '2')
		params->data->map_posX -= params->ray->dirX * 0.1;
	if (params->map[(int)(params->data->map_posX)]
	[(int)(params->data->map_posY - params->ray->dirY * 0.1)] != '1'
	&& params->map[(int)(params->data->map_posX)]
	[(int)(params->data->map_posY - params->ray->dirY * 0.1)] != '2')	
			params->data->map_posY -= params->ray->dirY * 0.1;
}

void	move_left(t_param *params)
{
	if (params->map[(int)(params->data->map_posX + params->ray->planeX * 0.1)]
	[(int)(params->data->map_posY)] != '1'
	&& params->map[(int)(params->data->map_posX + params->ray->planeX * 0.1)]
	[(int)(params->data->map_posY)] != '2')
		params->data->map_posX -= params->ray->planeX * 0.1;
	if (params->map[(int)(params->data->map_posX)]
	[(int)(params->data->map_posY + params->ray->planeY * 0.1)] != '1'
	&& params->map[(int)(params->data->map_posX)]
	[(int)(params->data->map_posY + params->ray->planeY * 0.1)] != '2')	
			params->data->map_posY -= params->ray->planeY * 0.1;
}

void	move_right(t_param *params)
{
	if (params->map[(int)(params->data->map_posX + params->ray->planeX * 0.1)]
	[(int)(params->data->map_posY)] != '1'
	&& params->map[(int)(params->data->map_posX + params->ray->planeX * 0.1)]
	[(int)(params->data->map_posY)] != '2')
		params->data->map_posX += params->ray->planeX * 0.1;
	if (params->map[(int)(params->data->map_posX)]
	[(int)(params->data->map_posY + params->ray->planeY * 0.1)] != '1'
	&& params->map[(int)(params->data->map_posX)]
	[(int)(params->data->map_posY + params->ray->planeY * 0.1)] != '2')	
		params->data->map_posY += params->ray->planeY * 0.1;
}