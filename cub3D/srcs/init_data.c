/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:46:12 by mwane             #+#    #+#             */
/*   Updated: 2020/02/21 16:28:06 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		init_texture(t_param *params)
{
	if (!(params->sprite->img_ptr = mlx_xpm_file_to_image(params->mlx_ptr,
	params->s, &params->sprite->size_x, &params->sprite->size_y)))
		error_msg("error texture sprite\n", params);
	if (!(params->texture->south_img_ptr =
	mlx_xpm_file_to_image(params->mlx_ptr, params->so, &params->texture->sizex1,
	&params->texture->sizey1)))
		error_msg("error texture south\n", params);
	if (!(params->texture->north_img_ptr =
	mlx_xpm_file_to_image(params->mlx_ptr, params->ea, &params->texture->sizex2,
	&params->texture->sizey2)))
		error_msg("error texture east\n", params);
	if (!(params->texture->east_img_ptr =
	mlx_xpm_file_to_image(params->mlx_ptr, params->no, &params->texture->sizex3,
	&params->texture->sizey3)))
		error_msg("error texture north\n", params);
	if (!(params->texture->west_img_ptr =
	mlx_xpm_file_to_image(params->mlx_ptr, params->we, &params->texture->sizex4,
	&params->texture->sizey4)))
		error_msg("error texture west\n", params);
	return (0);
}

void	init_text(t_texture *tex)
{
	tex = 0;
}

void	init_ray(t_ray *ray)
{
	ray->raydirx = 0;
	ray->raydiry = 0;
	ray->sidedistx = 0;
	ray->sidedisty = 0;
	ray->deltadistx = 0;
	ray->deltadisty = 0;
	ray->perpwalldist = 0;
	ray->stepx = 0;
	ray->stepy = 0;
	ray->hit = 0;
	ray->side = 0;
	ray->lineheight = 0;
	ray->drawstart = 0;
	ray->drawend = 0;
}

int		init_sruct(t_param *params, t_sprites *sprite, t_ray *ray)
{
	sprite = 0;
	ray = 0;
	params->s = NULL;
	params->no = NULL;
	params->ea = NULL;
	params->so = NULL;
	params->we = NULL;
	params->x = -1;
	params->y = -1;
	params->r = -1;
	params->g = -1;
	params->b = -1;
	params->f = -1;
	params->c = -1;
	params->option = 0;
	params->win_ptr = 0;
	params->mlx_ptr = 0;
	params->img_ptr = 0;
	params->img_ptr2 = 0;
	params->numsprite = 0;
	params->map = NULL;
	return (0);
}
