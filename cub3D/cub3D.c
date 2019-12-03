/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 14:18:13 by mwane             #+#    #+#             */
/*   Updated: 2019/12/03 17:52:06 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "cub3D.h"

int main(void)
{
	void* l;
	void* w;
	t_param params = {0,0,0,0,0,0,0,0};
	int     i;
	int     z;

	i = 0;
	z = 0;
	fill_params("map.cub", &params);
	l = mlx_init();
	w = mlx_new_window(l, params.x, params.y, "test");
	mlx_clear_window(l, w);
	char* x = ft_itoa(params.x);
	char* y = ft_itoa(params.y);
	printf("%s",x);
	while(i < params.x)
	{
		mlx_pixel_put(l, w , i, z, 255);
		i++;
		z++;
	}

	mlx_string_put(l, w, params.x/2, params.y/2, 255,x);
	mlx_string_put(l, w, (params.x/2), (params.y/2) + 20, 255,y);
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