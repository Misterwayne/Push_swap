/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 14:18:13 by mwane             #+#    #+#             */
/*   Updated: 2019/12/29 19:19:56 by mwane            ###   ########.fr       */
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
	if (params->sprite == 15)
		params->sprite = 0;
	params->img_ptr = mlx_xpm_file_to_image(params->mlx_ptr, params->dio[params->sprite], &a, &b);
	// mlx_clear_window(params->mlx_ptr, params->win_ptr);
	// delay(1000/60);
	// mlx_put_image_to_window(params->mlx_ptr, params->win_ptr, params->img_ptr, cx, cy);
	// params->sprite++;
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
	key = 0;
	if (key != 12)
	{
		int cx = params->x/2;
		int cy = params->y/2;
		double anx;
		double any;
		anx = (double)cx + (double)500*cos((double)params->angle);
		any = (double)cy + (double)500*sin((double)params->angle);
		mlx_clear_window(params->mlx_ptr, params->win_ptr);
		mlx_put_image_to_window(params->mlx_ptr, params->win_ptr, params->img_ptr, anx, any);
		params->angle++;
	}
	return (0);
} 

int main(int arc, char** argv)
{
	t_param params = {0,0,0,0,500,0,0,0,0,NULL,NULL,NULL,NULL,NULL,0,0,0,0,0,NULL,NULL};
	t_data	data = {0,0,0,0,0,0};
	int     i;
	int     z;
	int		o;
	int	    pos;
	int		c;

	i = 0;
	z = 0;
	o = 0;
	fill_params(argv[1], &params);
	printf("%d\n",check_map(params.map));
	check_ini_pos(params.map, &data);
	printf("x = %f, y = %f\n",data.cam_posX,data.cam_posY);
	params.dio = malloc(sizeof(char)* 16);
	params.dio[0] = ft_strdup("images/xpm_file/dio1.XPM");
	params.dio[1] = ft_strdup("images/xpm_file/dio2.XPM");
	params.dio[2] = ft_strdup("images/xpm_file/dio3.XPM");
	params.dio[3] = ft_strdup("images/xpm_file/dio4.XPM");
	params.dio[4] = ft_strdup("images/xpm_file/dio5.XPM");
	params.dio[5] = ft_strdup("images/xpm_file/dio6.XPM");
	params.dio[6] = ft_strdup("images/xpm_file/dio7.XPM");
	params.dio[7] = ft_strdup("images/xpm_file/dio8.XPM");
	params.dio[8] = ft_strdup("images/xpm_file/dio9.XPM");
	params.dio[9] = ft_strdup("images/xpm_file/dio10.XPM");
	params.dio[10] = ft_strdup("images/xpm_file/dio11.XPM");
	params.dio[11] = ft_strdup("images/xpm_file/dio12.XPM");
	params.dio[12] = ft_strdup("images/xpm_file/dio13.XPM");
	params.dio[13] = ft_strdup("images/xpm_file/dio14.XPM");
	params.dio[14] = ft_strdup("images/xpm_file/dio15.XPM");
	params.dio[15] = ft_strdup("images/xpm_file/dio16.XPM");
	// if(check_params(&params))
	// // 	return (0);
	// printf("line2 = %s\n",params.WE);
	// printf_struct(&params);
	params.mlx_ptr = mlx_init();
	params.win_ptr = mlx_new_window(params.mlx_ptr, params.x, params.y, "test");
	// // params.img_ptr = mlx_xpm_file_to_image(params.mlx_ptr, "images/xpm file/dio.XPM", &pos, &pos);
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
	// double anx;
	// double any;
	// anx = (double)cx + (double)500*cos((double)z);
	// any = (double)cy + (double)500*sin((double)z);
	// mlx_clear_window(params.mlx_ptr, params.win_ptr);
	// mlx_put_image_to_window(params.mlx_ptr, params.win_ptr, params.img_ptr, cx, cy);
	int a,b;
	z++;
	// params.img_ptr = mlx_xpm_file_to_image(params.mlx_ptr,params.dio[0], &a, &b);
	// mlx_put_image_to_window(params.mlx_ptr, params.win_ptr, params.img_ptr, cx, cy);
	mlx_loop_hook(params.mlx_ptr, &loop_hook, &params);
	mlx_key_hook(params.win_ptr, &key_hook, &params);
	mlx_loop(params.mlx_ptr);
	return (0);
}
