/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:11:00 by mwane             #+#    #+#             */
/*   Updated: 2020/02/23 19:14:00 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	draw_pix(t_param *params, int x)
{
	params->line_y = 0;
	params->texture->img = (char *)mlx_get_data_addr(params->texture->img_ptr,
	&params->texture->bpp, &params->texture->size_line,
	&params->texture->endian);
	params->line_y = draw_celing(x, params->line_y, params);
	params->line_y = draw_wall(0, x, params);
	draw_floor(x, params->line_y, params);
}

void	load_texture_we_ea(t_param *params)
{
	params->ray->sidedisty += params->ray->deltadisty;
	params->ray->map_y += params->ray->stepy;
	params->ray->side = 1;
	if (params->ray->stepy < 0)
	{
		params->texture->img_ptr = params->texture->south_img_ptr;
		params->texture->sizex = params->texture->sizex1;
		params->texture->sizey = params->texture->sizey1;
	}
	else
	{
		params->texture->img_ptr = params->texture->north_img_ptr;
		params->texture->sizex = params->texture->sizex2;
		params->texture->sizey = params->texture->sizey2;
	}
}

void	load_texture_no_so(t_param *params)
{
	params->ray->sidedistx += params->ray->deltadistx;
	params->ray->map_x += params->ray->stepx;
	params->ray->side = 0;
	if (params->ray->stepx < 0)
	{
		params->texture->img_ptr = params->texture->west_img_ptr;
		params->texture->sizex = params->texture->sizex4;
		params->texture->sizey = params->texture->sizey4;
	}
	else
	{
		params->texture->img_ptr = params->texture->east_img_ptr;
		params->texture->sizex = params->texture->sizex3;
		params->texture->sizey = params->texture->sizey3;
	}
}

void	ray(t_param *params, double camerax, int x)
{
	camerax = ((2 * (double)x) / (double)params->x) - 1;
	calcul_ray(params, camerax);
	if (params->ray->raydirx < 0)
	{
		params->ray->stepx = -1;
		params->ray->sidedistx = (params->ray->posx - params->ray->map_x) *
		params->ray->deltadistx;
	}
	else
	{
		params->ray->stepx = 1;
		params->ray->sidedistx = (params->ray->map_x + 1.0 - params->ray->posx)
		* params->ray->deltadistx;
	}
	ray2(params);
}

int		raycast(t_param *params)
{
	int		x;
	int		i;
	double	zbuffer[params->x];

	x = 0;
	i = 0;
	init_ray_data(params);
	while (x < params->x)
	{
		ray(params, 0, x);
		while (params->ray->hit == 0)
		{
			if (params->ray->sidedistx < params->ray->sidedisty)
				load_texture_no_so(params);
			else
				load_texture_we_ea(params);
			if (params->map[params->ray->map_x][params->ray->map_y] == '1')
				params->ray->hit = 1;
		}
		get_depth(params);
		draw_pix(params, x);
		zbuffer[x++] = params->ray->perpwalldist;
	}
	draw_sprite2(params, zbuffer);
	return (0);
}
