/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:11:00 by mwane             #+#    #+#             */
/*   Updated: 2020/01/05 18:04:03 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#define mapWidth 29
#define mapHeight 14

int     raycast(t_param *params)
{
    double posx = (double)params->data->map_posX;
    double posy = (double)params->data->map_posY;//x and y start position
    int bpp;
    int *map_img;
	int size_line;
	int endian;
    params->img_ptr = mlx_new_image(params->mlx_ptr, 1800, 1080);
    map_img = (int *)mlx_get_data_addr(params->img_ptr, &bpp, &size_line, &endian);
    double x = posx;
    double y = posy;
    int dist=  0;
    int hit = 0;
    int step = 0;
    int x2 = 0;
    int x3 = 0;
    double angle = 0.1;
    while (angle > -0.1)
    {
        while (y > 0 && hit == 0)
        {
            if (params->map[(int)y][(int)x] == '1')
            {
                hit = 1;
                dist = step-1;
                while (dist++ < 268 - (step))
                {
                    while (((x3*32 + 4 * 1800 * ((dist)))) + x2 < (((int)((x3+1)*32) + 4 * 1800 * ((dist)))))
                        map_img[(((int)x3*32 + 4 * 1800 * ((dist))))+x2++] = 0xFFFF;
                    x2 = 0;
                }
                break;
            }
            else
            {
                x -= angle;
                y -= 0.1;
                step += 1;
            }
        }
        y = posy;
        x = posx;
        x3 ++;
        step = 0;
        hit = 0;
        angle -= 0.005;
    }
    return (0);
}