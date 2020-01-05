/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 14:18:13 by mwane             #+#    #+#             */
/*   Updated: 2020/01/05 18:04:59 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int		loop_hook(t_param *params)
{
	mlx_put_image_to_window(params->mlx_ptr, params->win_ptr, params->img_ptr, 0, 0);
	return (0);
}

int		key_hook(int keydown, t_param *params)
{
	static int i;
	int 	z;
	long 	t;

	t = 0;
	z = 0;
	if (keydown == 53)
	{
		mlx_clear_window(params->mlx_ptr, params->win_ptr);
		mlx_destroy_window(params->mlx_ptr, params->win_ptr);
		exit(0);
	}
	// MOVEMENT
	if (keydown == 13)
	{
		if (params->map[params->data->map_posY - 1][params->data->map_posX] != '1')
				params->data->map_posY -= 1;
	}
	if (keydown == 0)
	{
		if (params->map[params->data->map_posY][params->data->map_posX - 1] != '1')
				params->data->map_posX -= 1;
	}
	if (keydown == 1)
	{
		if (params->map[params->data->map_posY + 1][params->data->map_posX] != '1')
			if (params->map[params->data->map_posY + 1][params->data->map_posX] != '\0')
				params->data->map_posY += 1;
	}
	if (keydown == 2)
	{
		if (params->map[params->data->map_posY][params->data->map_posX + 1] != '1')
			if (params->map[params->data->map_posY][params->data->map_posX + 1] != '\0')
				params->data->map_posX += 1;
	}
	mlx_destroy_image(params->mlx_ptr,params->img_ptr);
	raycast(params);
	return (0);
} 

int main(int arc, char** argv)
{
	t_data	data = {0,0,0,0,0,0,0};
	t_param params = {0,0,0,0,0,0,0,0,0,NULL,NULL,NULL,NULL,NULL,0,0,0,0,0,NULL,NULL,NULL,&data};

	params.rad = 500;
	params.sprite = 0;
	fill_params(argv[1], &params);
	printf("%d\n",check_map(params.map));
	check_ini_pos(params.map, &data);
	printf_struct(&params);
	params.mlx_ptr = mlx_init();
	params.win_ptr = mlx_new_window(params.mlx_ptr, params.x, params.y, "test");
	raycast(&params);
	mlx_loop_hook(params.mlx_ptr, &loop_hook, &params);
	mlx_key_hook(params.win_ptr, &key_hook, &params);
	mlx_loop(params.mlx_ptr);
	return (0);
}
