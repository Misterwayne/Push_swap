/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 09:14:03 by mwane             #+#    #+#             */
/*   Updated: 2020/02/21 20:31:40 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		cam_rotation(int dir, t_param *params)
{
	double olddirx;
	double oldplanex;
	double ms;

	ms = 0.1;
	if (dir == 123)
		ms *= -1;
	olddirx = params->ray->vecx;
	params->ray->vecx =
	params->ray->vecx * cos(-ms) - params->ray->vecy * sin(-ms);
	params->ray->vecy =
	olddirx * sin(-ms) + params->ray->vecy * cos(-ms);
	oldplanex = params->ray->planex;
	params->ray->planex =
	params->ray->planex * cos(-ms) - params->ray->planey * sin(-ms);
	params->ray->planey =
	oldplanex * sin(-ms) + params->ray->planey * cos(-ms);
	return (0);
}

void	error_msg(char *msg, t_param *params)
{
	(void)params;
	write(1, msg, ft_strlen(msg));
	exit(1);
}
