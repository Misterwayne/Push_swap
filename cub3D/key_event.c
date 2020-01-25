/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 09:14:03 by mwane             #+#    #+#             */
/*   Updated: 2020/01/20 09:14:10 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "cub3D.h"

int     cam_rotation(int dir, t_param *params)
{
    double olddirX;
	double oldplaneX;
	double olddirY;
	double oldplaneY;
    double ms;

    ms = 0.1;
    if (dir == 123)
        ms *= -1;
    olddirX = params->ray->dirX;
	params->ray->dirX = 
	params->ray->dirX * cos(-ms) - params->ray->dirY * sin(-ms);
	params->ray->dirY =
	olddirX * sin(-ms) + params->ray->dirY * cos(-ms);
	oldplaneX = params->ray->planeX;
	params->ray->planeX =
	params->ray->planeX * cos(-ms) - params->ray->planeY * sin(-ms);
	params->ray->planeY =
	oldplaneX * sin(-ms) + params->ray->planeY * cos(-ms);
    return (0);
}

int		mini_map(t_param *params)
{
		// map
	int xpos = 0;
	int ypos = 0;
	int *map_img;
	int temp = 0;
	int bpp;
	int size_line;
	int endian;
	int pposx = params->data->map_posX;
	int pposy = params->data->map_posY;
	params->img_ptr2 = mlx_new_image(params->mlx_ptr, params->x/10, params->y/10);
	map_img = (int *)mlx_get_data_addr(params->img_ptr2, &bpp, &size_line, &endian);
	// printf("bpp = %d, size_line = %d ,endian = %d\n",bpp,size_line,endian);
	while (params->map[ypos] != NULL)
	{
		pposy = params->data->map_posY;
		pposx = params->data->map_posX;
		while(params->map[ypos][xpos])
		{
			if (params->map[ypos][xpos] == '1')
			{
				map_img[(xpos) * 4 + bpp/8 * (size_line/4) * (ypos*2)] = 0xFFFFFF;
			}
			else if (ypos == (pposx) && xpos == (pposy)) 
				map_img[(xpos) * 4 + bpp/8 * (size_line/4) * (ypos*2)] = 0xFF0000;
			else
				map_img[(xpos) * 4 + bpp/8 * (size_line/4) * (ypos*2)] = 0x0;
			xpos++;
		}
		ypos++;
		xpos = 0;
	}
	return (0);
}