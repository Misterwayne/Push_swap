/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 14:18:13 by mwane             #+#    #+#             */
/*   Updated: 2019/12/05 16:41:10 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include "cub3D.h"

int main(void)
{
	void* l;
	void* w;
	t_param params = {0,0,NULL,NULL,NULL,NULL,NULL,0,0,0,0,0,NULL};
	int     i;
	int     z;

	i = 0;
	z = 0;
	fill_params("map.cub", &params);
	// if(check_params(&params))
	// 	return (0);
	printf("line2 = %s\n",params.WE);
	printf_struct(&params);
	l = mlx_init();
	w = mlx_new_window(l, params.x, params.y, "test");
	mlx_clear_window(l, w);
	char* x = ft_itoa(params.x);
	char* y = ft_itoa(params.y);
	char* F = ft_itoa(params.F);
	int colorF = params.F;
	int colorC = params.C;
	char* C = ft_itoa(params.C);
	while(i < params.x)
	{
		mlx_pixel_put(l, w , i, z, 255);
		i++;
		z++;
	}
	mlx_string_put(l, w, params.x/2, params.y/2, 255,x);
	mlx_string_put(l, w, (params.x/2), (params.y/2) + 20, colorF,y);
	mlx_string_put(l, w, (params.x/2), (params.y/2) + 40, colorF,params.SO);
	mlx_string_put(l, w, (params.x/2), (params.y/2) + 60, colorF,params.NO);
	mlx_string_put(l, w, (params.x/2), (params.y/2) + 80, colorF,params.WE);
	mlx_string_put(l, w, (params.x/2), (params.y/2) + 100, colorF,params.EA);
	mlx_string_put(l, w, (params.x/2), (params.y/2) + 120, colorC,params.S);
	mlx_string_put(l, w, (params.x/2), (params.y/2) + 140, colorC,F);
	mlx_string_put(l, w, (params.x/2), (params.y/2) + 160, colorC,C);
	z = 0;
	while(i > 0)
	{
		mlx_pixel_put(l, w , i, z, 255);
		i--;
		z++;
	}
	mlx_loop(l);
	return (0);
}