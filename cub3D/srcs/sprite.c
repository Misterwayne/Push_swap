/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 14:28:28 by mwane             #+#    #+#             */
/*   Updated: 2020/02/21 16:35:29 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		init_sprite(t_param *params, int i)
{
	params->sprite->sprite_distance[i] =
	((params->ray->posx - params->sprite->sprt_list[i][0]) *
	(params->ray->posx - params->sprite->sprt_list[i][0]) +
	(params->ray->posy - params->sprite->sprt_list[i][1]) *
	(params->ray->posy - params->sprite->sprt_list[i][1]));
	return (params->sprite->sprite_distance[i]);
}

void	draw_sprite(t_param *params, double *zbuffer)
{
	int text_x;
	int stripe;

	stripe = params->sprite->draw_startx;
	while (stripe < params->sprite->draw_endx)
	{
		text_x = (int)(256 * (stripe - (-params->sprite->spritewidth
		/ 2 + params->sprite->spritescreenx)) *
		params->sprite->size_x / params->sprite->spritewidth)
		/ 256;
		if (params->sprite->transy > 0 && stripe > 0 &&
		stripe < params->x && params->sprite->transy < zbuffer[stripe])
			print_sprite(0, stripe, text_x, params);
		stripe++;
	}
}

void	cal_sprite_height(t_param *params)
{
	params->sprite->spriteheight = fabs((params->y / (params->sprite->transy)));
	params->sprite->draw_starty = (int)(-params->sprite->spriteheight /
	2 + params->y / 2);
	params->sprite->draw_endy = (int)(params->sprite->spriteheight /
	2 + params->y / 2);
	if (params->sprite->draw_endy >= params->y)
		params->sprite->draw_endy = params->y - 1;
	params->sprite->spritewidth = fabs(params->y / params->sprite->transy);
	params->sprite->draw_startx = -params->sprite->spritewidth /
	2 + params->sprite->spritescreenx;
	params->sprite->draw_endx = params->sprite->spritewidth /
	2 + params->sprite->spritescreenx;
	if (params->sprite->draw_endx >= params->x)
		params->sprite->draw_endx = params->x - 1;
}

void	cal_sprite_dist(t_param *params)
{
	params->sprite->spritey = params->sprite->y - params->ray->posy;
	params->sprite->spritex = params->sprite->x - params->ray->posx;
	params->sprite->indet = 1.0 / ((params->ray->planex * params->ray->vecy)
	- (params->ray->vecx * params->ray->planey));
	params->sprite->transx = params->sprite->indet *
	((params->ray->vecy * params->sprite->spritex) -
	(params->ray->vecx * params->sprite->spritey));
	params->sprite->transy = params->sprite->indet *
	(-params->ray->planey * params->sprite->spritex +
	params->ray->planex * params->sprite->spritey);
	params->sprite->spritescreenx = (int)(params->x / 2) *
	(1 + params->sprite->transx / params->sprite->transy);
	cal_sprite_height(params);
}

int		sprite(t_param *params, int x, double *zbuffer)
{
	int i;

	i = 0;
	if (!(params->sprite->img = mlx_get_data_addr(params->sprite->img_ptr,
	&params->sprite->bpp, &params->sprite->size_line, &params->sprite->endian)))
		error_msg("error texture sprite", params);
	params->sprite->x = params->sprite->sprt_list[x][0] + 0.5;
	params->sprite->y = params->sprite->sprt_list[x][1] + 0.5;
	init_sprite(params, x);
	cal_sprite_dist(params);
	draw_sprite(params, zbuffer);
	return (0);
}
