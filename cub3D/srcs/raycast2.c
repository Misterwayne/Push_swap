/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 15:48:45 by mwane             #+#    #+#             */
/*   Updated: 2020/02/21 16:41:48 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	get_depth2(t_param *params)
{
	params->ray->lineheight = (int)(params->y / params->ray->perpwalldist);
	params->ray->drawstart = (-params->ray->lineheight / 2) + (params->y / 2);
	params->ray->drawend = (params->ray->lineheight - 1) / 2 + params->y / 2;
	if (params->ray->drawend >= params->y)
		params->ray->drawend = params->y - 1;
	if (params->ray->drawstart < 0)
		params->ray->drawstart = 1;
}

void	calcul_ray(t_param *params, double camerax)
{
	params->ray->raydirx = params->ray->vecx + params->ray->planex * camerax;
	params->ray->raydiry = params->ray->vecy + params->ray->planey * camerax;
	params->ray->map_x = (int)params->ray->posx + 0.0;
	params->ray->map_y = (int)params->ray->posy + 0.0;
	params->ray->deltadistx = fabs((1 / params->ray->raydirx));
	params->ray->deltadisty = fabs((1 / params->ray->raydiry));
	params->ray->hit = 0;
}

void	get_depth(t_param *params)
{
	if (params->ray->side == 0)
	{
		params->ray->perpwalldist =
		(double)(((double)params->ray->map_x - params->ray->posx +
		(1 - (double)params->ray->stepx) / 2) / params->ray->raydirx);
		params->texture->wallx = params->ray->posy + params->ray->perpwalldist *
		params->ray->raydiry;
	}
	else
	{
		params->ray->perpwalldist =
		(double)(((double)params->ray->map_y - params->ray->posy +
		(1 - (double)params->ray->stepy) / 2) / params->ray->raydiry);
		params->texture->wallx = params->ray->posx + params->ray->perpwalldist *
		params->ray->raydirx;
	}
	params->texture->wallx -= floor(params->texture->wallx);
	get_depth2(params);
}

void	print_wall(t_param *params, int text_y, int text_x, int x)
{
	params->map_info->img[(params->line_y * (params->map_info->size_line) +
	(x) * (params->map_info->bpp / 8))] =
	params->texture->img[(text_y * params->texture->size_line +
	(text_x) * (params->texture->bpp / 8))];
	params->map_info->img[(params->line_y * (params->map_info->size_line) +
	(x) * (params->map_info->bpp / 8)) + 1] =
	params->texture->img[(text_y * params->texture->size_line +
	(text_x) * (params->texture->bpp / 8)) + 1];
	params->map_info->img[(params->line_y * (params->map_info->size_line) +
	(x) * (params->map_info->bpp / 8)) + 2] =
	params->texture->img[(text_y * params->texture->size_line +
	(text_x) * (params->texture->bpp / 8)) + 2];
}

int		draw_wall(int text_x, int x, t_param *params)
{
	int		text_y;
	double	wally;
	double	step;
	double	texpos;

	step = 1.0 * params->texture->sizey / params->ray->lineheight;
	texpos = (params->ray->drawstart - params->y / 2 +
	params->ray->lineheight / 2) * step;
	text_x = (int)(params->texture->wallx * (double)params->texture->sizex);
	if (params->ray->side == 0 && params->ray->raydirx > 0)
		text_x = params->texture->sizex - text_x - 1;
	if (params->ray->side == 1 && params->ray->raydiry > 0)
		text_x = params->texture->sizex - text_x - 1;
	while (params->line_y < params->ray->drawend)
	{
		wally = (params->line_y - params->ray->drawstart) /
		params->ray->lineheight;
		text_y = (int)texpos & (params->texture->sizey - 1);
		texpos += step;
		print_wall(params, text_y, text_x, x);
		params->line_y++;
	}
	return (params->line_y);
}
