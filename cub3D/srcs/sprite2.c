/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 13:57:21 by mwane             #+#    #+#             */
/*   Updated: 2020/02/14 16:02:11 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void     get_sprite(t_param *params,int x, int y, int i)
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

void 	sort_sprite(t_param *params)
{
	int i;
	char* temp;

	i = 0;
	if (!(params->sprite->sprite_distance = malloc(sizeof(double) * params->numsprite)))
		return ;
	while (i < params->numsprite - 1)
	{
		if (init_sprite(params,i) < init_sprite(params,i+1))
		{
			temp = params->sprite->sprt_list[i];
			params->sprite->sprt_list[i] = params->sprite->sprt_list[i+1];
			params->sprite->sprt_list[i+1] = temp;
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

void	print_sprite(int y, int stripe, int text_x, t_param *params)
{
	int d;
	int text_y;
	
	y = params->sprite->draw_startY;
    while (y < params->sprite->draw_endY)
    {
        d = (y) * 256 - params->y * 128 +
        params->sprite->spriteHeight * 128;
        text_y = ((d * params->sprite->size_y) / params->sprite->spriteHeight)
        / 256;
        if (params->sprite->img[(text_y * params->sprite->size_line +
        (text_x) * (params->sprite->bpp / 8))] != 0x0)
        {
        params->map_info->img[(y * (params->map_info->size_line) + (stripe) *
	    (params->map_info->bpp / 8))] = params->sprite->img[(text_y *
        params->sprite->size_line + (text_x) * (params->sprite->bpp / 8))];
         params->map_info->img[(y * (params->map_info->size_line) + (stripe) *
	    (params->map_info->bpp / 8))+1] = params->sprite->img[(text_y *
        params->sprite->size_line + (text_x) * (params->sprite->bpp / 8))+1];
         params->map_info->img[(y * (params->map_info->size_line) + (stripe) *
	    (params->map_info->bpp / 8))+2] = params->sprite->img[(text_y *
        params->sprite->size_line + (text_x) * (params->sprite->bpp / 8))+2];
        }
        y++;
    }
}