/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 13:57:21 by mwane             #+#    #+#             */
/*   Updated: 2020/02/23 19:55:35 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	get_sprite(t_param *params, int x, int y, int i)
{
	if (i < params->numsprite)
	{
		if (!(params->sprite->sprt_list[i] = malloc(sizeof(char) * 3)))
			return ;
		params->sprite->sprt_list[i][0] = y;
		params->sprite->sprt_list[i][1] = x;
		params->sprite->sprt_list[i][2] = '\0';
	}
	return ;
}

void	sort_sprite(t_param *params)
{
	int		i;
	char	*temp;

	i = 0;
	if (!(params->sprite->sprite_distance = malloc(sizeof(double) *
	params->numsprite + 1)))
		return ;
	while (i < params->numsprite - 1)
	{
		if (init_sprite(params, i) < init_sprite(params, i + 1))
		{
			temp = params->sprite->sprt_list[i];
			params->sprite->sprt_list[i] = params->sprite->sprt_list[i + 1];
			params->sprite->sprt_list[i + 1] = temp;
		}
		i++;
	}
}

void	draw_sprite2(t_param *params, double *zbuffer)
{
	int i;

	i = 0;
	sort_sprite(params);
	while (i < params->numsprite)
	{
		sprite(params, i, zbuffer);
		i++;
	}
}

void	print_sprite(int y, int stripe, int text_x, t_param *para)
{
	int d;
	int text_y;

	y = para->sprite->draw_starty;
	while (y < para->sprite->draw_endy)
	{
		d = (y) * 256 - para->y * 128 +
		para->sprite->spriteheight * 128;
		text_y = ((d * para->sprite->size_y) / para->sprite->spriteheight)
		/ 256;
		if (para->sprite->img[(text_y * para->sprite->size_line +
		(text_x) * (para->sprite->bpp / 8))] != 0x0)
		{
			para->map_info->img[(y * (para->map_info->size_line) + (stripe)
			* (para->map_info->bpp / 8))] = para->sprite->img[(text_y *
			para->sprite->size_line + (text_x) * (para->sprite->bpp / 8))];
			para->map_info->img[(y * (para->map_info->size_line) + (stripe)
			* (para->map_info->bpp / 8)) + 1] = para->sprite->img[(text_y *
			para->sprite->size_line + (text_x) * (para->sprite->bpp / 8)) + 1];
			para->map_info->img[(y * (para->map_info->size_line) + (stripe)
			* (para->map_info->bpp / 8)) + 2] = para->sprite->img[(text_y *
			para->sprite->size_line + (text_x) * (para->sprite->bpp / 8)) + 2];
		}
		y++;
	}
}
