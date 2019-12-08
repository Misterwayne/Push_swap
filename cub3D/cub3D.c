/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 14:18:13 by mwane             #+#    #+#             */
/*   Updated: 2019/12/08 18:23:45 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include "cub3D.h"
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

void my_delay(int i)
{
    clock_t start,end;
    start=clock();
    while(((end=clock())-start)<=i*CLOCKS_PER_SEC);
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
		mlx_clear_window(params->mlx_ptr, params->win_ptr);
		mlx_destroy_window(params->mlx_ptr, params->win_ptr);
		exit(0);
	}
	if (key == 12)
		mlx_clear_window(params->mlx_ptr, params->win_ptr);
	return (0);
} 

int main(void)
{
	t_param params = {0,0,0,0,NULL,NULL,NULL,NULL,NULL,0,0,0,0,0,NULL};
	int     i;
	int     z;
	int		o;
	int		c;

	i = 0;
	z = 0;
	o = 0;
	fill_params("map.cub", &params);
	if(check_params(&params))
		return (0);
	printf("line2 = %s\n",params.WE);
	printf_struct(&params);
	params.mlx_ptr = mlx_init();
	params.win_ptr = mlx_new_window(params.mlx_ptr, params.x, params.y, "test");
	mlx_clear_window(params.mlx_ptr, params.win_ptr);
	char* x = ft_itoa(params.x);
	char* y = ft_itoa(params.y);
	char* F = ft_itoa(params.F);
	int colorF = params.F;
	int colorC = params.C;
	char* C = ft_itoa(params.C);
	while(i < params.x)
	{
		mlx_pixel_put(params.mlx_ptr, params.win_ptr, i, z, 255);
		i++;
		z++;
	}
	mlx_string_put(params.mlx_ptr, params.win_ptr, params.x/2, params.y/2, 255,x);
	mlx_string_put(params.mlx_ptr, params.win_ptr, (params.x/2), (params.y/2) + 20, colorF,y);
	mlx_string_put(params.mlx_ptr, params.win_ptr, (params.x/2), (params.y/2) + 40, colorF,params.SO);
	mlx_string_put(params.mlx_ptr, params.win_ptr, (params.x/2), (params.y/2) + 60, colorF,params.NO);
	mlx_string_put(params.mlx_ptr, params.win_ptr, (params.x/2), (params.y/2) + 80, colorF,params.WE);
	mlx_string_put(params.mlx_ptr, params.win_ptr, (params.x/2), (params.y/2) + 100, colorF,params.EA);
	mlx_string_put(params.mlx_ptr, params.win_ptr, (params.x/2), (params.y/2) + 120, colorC,params.S);
	mlx_string_put(params.mlx_ptr, params.win_ptr, (params.x/2), (params.y/2) + 140, colorC,F);
	mlx_string_put(params.mlx_ptr, params.win_ptr, (params.x/2), (params.y/2) + 160, colorC,C);
	z = 0;
	while(i > 0)
	{
		mlx_pixel_put(params.mlx_ptr, params.win_ptr , i, z, 255);
		i--;
		z++;
	}
	mlx_key_hook(params.win_ptr, &key_hook, &params);
	mlx_loop(params.mlx_ptr);
	return (0);
}