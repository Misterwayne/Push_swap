/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 18:12:26 by mwane             #+#    #+#             */
/*   Updated: 2020/02/21 16:45:04 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	move_forward(t_param *params)
{
	if (params->map[(int)((params->map_x) + params->ray->vecx * 0.2)]
	[(int)(params->map_y - 0)] != '1'
	&& params->map[(int)((params->map_x) + params->ray->vecx * 0.2)]
	[(int)(params->map_y - 0)] != '2')
		params->map_x += params->ray->vecx * 0.2;
	if (params->map[(int)(params->map_x)]
	[(int)((params->map_y - 0) + params->ray->vecy * 0.2)] != '1'
	&& params->map[(int)(params->map_x)]
	[(int)((params->map_y - 0) + params->ray->vecy * 0.2)] != '2')
		params->map_y += params->ray->vecy * 0.2;
}

void	move_back(t_param *params)
{
	if (params->map[(int)((params->map_x) - params->ray->vecx * 0.2)]
	[(int)(params->map_y - 0)] != '1'
	&& params->map[(int)((params->map_x) - params->ray->vecx * 0.2)]
	[(int)(params->map_y - 0)] != '2')
		params->map_x -= params->ray->vecx * 0.2;
	if (params->map[(int)(params->map_x)]
	[(int)(params->map_y - params->ray->vecy * 0.2)] != '1'
	&& params->map[(int)(params->map_x)]
	[(int)((params->map_y - 0) - params->ray->vecy * 0.2)] != '2')
		params->map_y -= params->ray->vecy * 0.2;
}

void	move_left(t_param *params)
{
	if (params->map[(int)((params->map_x) - params->ray->planex * 0.2)]
	[(int)(params->map_y - 0)] != '1'
	&& params->map[(int)((params->map_x) - params->ray->planex * 0.2)]
	[(int)(params->map_y - 0)] != '2')
		params->map_x -= params->ray->planex * 0.2;
	if (params->map[(int)(params->map_x)]
	[(int)((params->map_y - 0) - params->ray->planey * 0.2)] != '1'
	&& params->map[(int)(params->map_x)]
	[(int)((params->map_y - 0) - params->ray->planey * 0.2)] != '2')
		params->map_y -= params->ray->planey * 0.2;
}

void	move_right(t_param *params)
{
	if (params->map[(int)((params->map_x) + params->ray->planex * 0.2)]
	[(int)(params->map_y - 0)] != '1'
	&& params->map[(int)((params->map_x) + params->ray->planex * 0.2)]
	[(int)(params->map_y - 0)] != '2')
		params->map_x += params->ray->planex * 0.2;
	if (params->map[(int)(params->map_x)]
	[(int)((params->map_y - 0) + params->ray->planey * 0.2)] != '1'
	&& params->map[(int)(params->map_x)]
	[(int)((params->map_y - 0) + params->ray->planey * 0.2)] != '2')
		params->map_y += params->ray->planey * 0.2;
}
