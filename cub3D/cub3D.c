/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 14:18:13 by mwane             #+#    #+#             */
/*   Updated: 2019/12/30 19:55:41 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <stdio.h>
#include "cub3D.h"
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void delay(int number_of_seconds) 
{ 
    // Converting time into milli_seconds 
    int milli_seconds = 1000 * number_of_seconds; 
  
    // Storing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not achieved 
    while (clock() < start_time + milli_seconds) 
        ; 
}
int		loop_hook(t_param *params)
{
	// delay(10);
	// if (params->angle >= 360)
	// 	params->angle = 0;
	int cx = params->x/2;
	int cy = params->y/2;
	int a;
	int b;
	// the circle stuff

	// double anx;
	// double any;
	// anx = (double)cx + (double)params->rad * cos((double)params->angle);
	// any = (double)cy + (double)params->rad * sin((double)params->angle);
	// // if (params->angle > 350) 
	// // 	mlx_clear_window(params->mlx_ptr, params->win_ptr);
	// // mlx_put_image_to_window(params->mlx_ptr, params->win_ptr, params->img_ptr, anx, any);
	// mlx_pixel_put(params->mlx_ptr,params->win_ptr, any, anx, params->F);
	// params->angle += 0.01;
	// params->F++;
	// params->rad -= 0.01;

	// JOJO Stuff
	
	// if (params->data->cam_posX >= params->x)
	// {
	// 	params->data->cam_posX = 0;
	// 	params->data->cam_posY += 100;

	// }
	// if (params->data->cam_posY >= params->y)
	// 	params->data->cam_posY = 0;
	// delay(1000/20);
	// if (params->sprite > 14)
	// 	params->sprite = 0;
	// params->img_ptr = mlx_xpm_file_to_image(params->mlx_ptr, params->dio[params->sprite], &a, &b);
	// params->img_ptr2 = mlx_xpm_file_to_image(params->mlx_ptr, params->jojo[params->sprite], &a, &b);
	// mlx_clear_window(params->mlx_ptr, params->win_ptr);
	// mlx_put_image_to_window(params->mlx_ptr, params->win_ptr, params->img_ptr, params->data->cam_posX, params->data->cam_posY);
	// mlx_put_image_to_window(params->mlx_ptr, params->win_ptr, params->img_ptr2, params->data->cam_posX + 100, params->data->cam_posY + 100);
	// params->data->cam_posX += 10;
	// params->sprite++;

	//TEST
	int xpos = 0;
	int ypos = 0;
	int *map_img;
	int bpp;
	int size_line;
	int endian;
	params->img_ptr = mlx_new_image(params->mlx_ptr, 800, 600);
	map_img = (int *)mlx_get_data_addr(params->img_ptr, &bpp, &size_line, &endian);
	// printf("bpp = %d, size_line = %d ,endian = %d\n",bpp,size_line,endian);
	while (params->map[ypos] != NULL)
	{
		while (params->map[ypos][xpos])
		{
			if (params->map[ypos][xpos] == '1')
			{
				map_img[xpos*10 + 4 * 800 * ypos] = 0xFFFFFF;
			}
			else if (ypos == params->data->map_posY && xpos == params->data->map_posX)
			{
				if (params->map[ypos][xpos] == '0')
					map_img[xpos*10 + 4 * 800 * ypos] = 0xFFFF;
				printf("xpos = %d  ypos = %d\n",params->data->map_posX, params->data->map_posY);
			}
			else if (params->map[ypos][xpos] == '0')
				map_img[xpos*10 + 4 * 800 * ypos] = 0;
			else
				map_img[xpos*10 + 4 * 800 * ypos] = 0xFF;
			xpos++;
			// printf("xpos = %d\n",params->data->map_posX);
		}
		xpos = 0;
		ypos += 1;
	}
	mlx_put_image_to_window(params->mlx_ptr, params->win_ptr, params->img_ptr, 0, 0);
	return (0);
}

int		key_hook(int key, t_param *params)
{
	static int i;
	int 	z;
	long 	t;

	t = 0;
	z = 0;
	if (!i)
		i = 0;
	if (key == 53)
	{
		mlx_destroy_image(params->mlx_ptr, params->img_ptr);
		mlx_clear_window(params->mlx_ptr, params->win_ptr);
		mlx_destroy_window(params->mlx_ptr, params->win_ptr);
		exit(0);
	}
	// MOVEMENT

	if (key == 13)
	{
		params->data->map_posY -= 1;
		// int cx = params->x/2;
		// int cy = params->y/2;
		// double anx;
		// double any;
		// anx = (double)cx + (double)500*cos((double)params->angle);
		// any = (double)cy + (double)500*sin((double)params->angle);
		// mlx_clear_window(params->mlx_ptr, params->win_ptr);
		// mlx_put_image_to_window(params->mlx_ptr, params->win_ptr, params->img_ptr, anx, any);
		// params->angle++;
	}
	if (key == 0)
	{
		params->data->map_posX -= 1;
	}
	if (key == 1)
		params->data->map_posY += 1;
	if (key == 2)
		params->data->map_posX += 1;
	return (0);
} 

int main(int arc, char** argv)
{
	t_data	data = {0,0,0,0,0,0,0};
	t_param params = {0,0,0,0,500,0,0,0,0,NULL,NULL,NULL,NULL,NULL,0,0,0,0,0,NULL,NULL,NULL,&data};
	int     i;
	int     z;
	int		o;
	int	    pos;
	int		c;

	i = 0;
	z = 0;
	o = 0;
	params.rad = 500;
	fill_params(argv[1], &params);
	printf("%d\n",check_map(params.map));
	check_ini_pos(params.map, &data);
	printf("x = %f, y = %f\n",data.cam_posX,data.cam_posY);
	// params.dio = malloc(sizeof(char*)* 16);
	// params.dio[0] = ft_strdup("images/xpm_file/dio/dio1.XPM");
	// params.dio[1] = ft_strdup("images/xpm_file/dio/dio2.XPM");
	// params.dio[2] = ft_strdup("images/xpm_file/dio/dio3.XPM");
	// params.dio[3] = ft_strdup("images/xpm_file/dio/dio4.XPM");
	// params.dio[4] = ft_strdup("images/xpm_file/dio/dio5.XPM");
	// params.dio[5] = ft_strdup("images/xpm_file/dio/dio6.XPM");
	// params.dio[6] = ft_strdup("images/xpm_file/dio/dio7.XPM");
	// params.dio[7] = ft_strdup("images/xpm_file/dio/dio8.XPM");
	// params.dio[8] = ft_strdup("images/xpm_file/dio/dio9.XPM");
	// params.dio[9] = ft_strdup("images/xpm_file/dio/dio10.XPM");
	// params.dio[10] = ft_strdup("images/xpm_file/dio/dio11.XPM");
	// params.dio[11] = ft_strdup("images/xpm_file/dio/dio12.XPM");
	// params.dio[12] = ft_strdup("images/xpm_file/dio/dio13.XPM");
	// params.dio[13] = ft_strdup("images/xpm_file/dio/dio14.XPM");
	// params.dio[14] = ft_strdup("images/xpm_file/dio/dio15.XPM");
	// params.dio[15] = ft_strdup("images/xpm_file/dio/dio16.XPM");
	// params.jojo = malloc(sizeof(char*)* 15);
	// params.jojo[0] = ft_strdup("images/xpm_file/jojo/jojo2.XPM");
	// params.jojo[1] = ft_strdup("images/xpm_file/jojo/jojo3.XPM");
	// params.jojo[2] = ft_strdup("images/xpm_file/jojo/jojo4.XPM");
	// params.jojo[3] = ft_strdup("images/xpm_file/jojo/jojo5.XPM");
	// params.jojo[4] = ft_strdup("images/xpm_file/jojo/jojo6.XPM");
	// params.jojo[5] = ft_strdup("images/xpm_file/jojo/jojo7.XPM");
	// params.jojo[6] = ft_strdup("images/xpm_file/jojo/jojo8.XPM");
	// params.jojo[7] = ft_strdup("images/xpm_file/jojo/jojo9.XPM");
	// params.jojo[8] = ft_strdup("images/xpm_file/jojo/jojo10.XPM");
	// params.jojo[9] = ft_strdup("images/xpm_file/jojo/jojo11.XPM");
	// params.jojo[10] = ft_strdup("images/xpm_file/jojo/jojo12.XPM");
	// params.jojo[11] = ft_strdup("images/xpm_file/jojo/jojo13.XPM");
	// params.jojo[12] = ft_strdup("images/xpm_file/jojo/jojo14.XPM");
	// params.jojo[13] = ft_strdup("images/xpm_file/jojo/jojo15.XPM");
	// params.jojo[14] = ft_strdup("images/xpm_file/jojo/jojo16.XPM");
	// printf("%s\n",params.jojo[14]);
	// if(check_params(&params))
	// // 	return (0);
	// printf("line2 = %s\n",params.WE);
	printf_struct(&params);
	params.mlx_ptr = mlx_init();
	params.win_ptr = mlx_new_window(params.mlx_ptr, params.x, params.y, "test");
	// params.img_ptr = mlx_xpm_file_to_image(params.mlx_ptr, "images/xpm_file/jojo/jojo2.XPM", &pos, &pos);
	
	//DATA 
	
	// i = 0;
	// mlx_clear_window(params.mlx_ptr, params.win_ptr);
	// char* x = ft_itoa(params.x);
	// char* y = ft_itoa(params.y);
	// char* F = ft_itoa(params.F);
	// int colorF = params.F;
	// int colorC = params.C;
	// char* C = ft_itoa(params.C);
	// mlx_string_put(params.mlx_ptr, params.win_ptr, params.x/2, params.y/2, 255,x);
	// mlx_string_put(params.mlx_ptr, params.win_ptr, (params.x/2), (params.y/2) + 20, colorF,y);
	// mlx_string_put(params.mlx_ptr, params.win_ptr, (params.x/2), (params.y/2) + 40, colorF,params.SO);
	// mlx_string_put(params.mlx_ptr, params.win_ptr, (params.x/2), (params.y/2) + 60, colorF,params.NO);
	// mlx_string_put(params.mlx_ptr, params.win_ptr, (params.x/2), (params.y/2) + 80, colorF,params.WE);
	// mlx_string_put(params.mlx_ptr, params.win_ptr, (params.x/2), (params.y/2) + 100, colorF,params.EA);
	// mlx_string_put(params.mlx_ptr, params.win_ptr, (params.x/2), (params.y/2) + 120, colorC,params.S);
	// mlx_string_put(params.mlx_ptr, params.win_ptr, (params.x/2), (params.y/2) + 140, colorC,F);
	// mlx_string_put(params.mlx_ptr, params.win_ptr, (params.x/2), (params.y/2) + 160, colorC,C);
	int cx = params.x/2;
	int cy = params.y/2;
	// // double anx;
	// // double any;
	// // anx = (double)cx + (double)500*cos((double)z);
	// // any = (double)cy + (double)500*sin((double)z);
	// // mlx_clear_window(params.mlx_ptr, params.win_ptr);
	// mlx_put_image_to_window(params.mlx_ptr, params.win_ptr, params.img_ptr, cx, cy);
	// int a,b;
	// z++;
	// params.img_ptr = mlx_xpm_file_to_image(params.mlx_ptr,params.dio[0], &a, &b);
	// mlx_put_image_to_window(params.mlx_ptr, params.win_ptr, params.img_ptr, cx, cy);
	// int xpos = 0;
	// int ypos = 0;
	// int *map_img;
	// int bpp;
	// int size_line;
	// int endian;
	// params.img_ptr = mlx_new_image(params.mlx_ptr, 800, 600);
	// map_img = (int *)mlx_get_data_addr(params.img_ptr, &bpp, &size_line, &endian);
	// printf("bpp = %d, size_line = %d ,endian = %d\n",bpp,size_line,endian);
	// while (params.map[ypos] != NULL)
	// {
	// 	while (params.map[ypos][xpos])
	// 	{
	// 		if (params.map[ypos][xpos] == '1')
	// 		{
	// 			map_img[xpos*10 + 4 * 800 * ypos] = 0xFFFFFF;
	// 		}
	// 		else if (params.map[ypos][xpos] == '0')
	// 			map_img[xpos*10 + 4 * 800 * ypos] = 0;
	// 		else if (ypos == params.data->cam_posY && xpos == params.data->cam_posX)
	// 			map_img[xpos*10 + 4 * 800 * ypos] = 0xFF;
	// 		else
	// 			map_img[xpos*10 + 4 * 800 * ypos] = 0xFF;
	// 		xpos++;
	// 	}
	// 	xpos = 0;
	// 	ypos += 1;
	// }
	// mlx_put_image_to_window(params.mlx_ptr, params.win_ptr, params.img_ptr, 0, 0);
	printf("x = %f, y = %f",data.cam_posX, data.cam_posY);
	mlx_loop_hook(params.mlx_ptr, &loop_hook, &params);
	mlx_key_hook(params.win_ptr, &key_hook, &params);
	mlx_loop(params.mlx_ptr);
	return (0);
}
