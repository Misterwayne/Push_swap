/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 14:18:13 by mwane             #+#    #+#             */
/*   Updated: 2020/01/28 15:14:33 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int		loop_hook(t_param *params)
{
	char buffer[20];
	mlx_put_image_to_window(params->mlx_ptr, params->win_ptr, params->img_ptr, 0, 0);
	// if (params->sprite < 0)
	// {
		mini_map(params);
		mlx_put_image_to_window(params->mlx_ptr, params->win_ptr, params->img_ptr2, 0, 0);
		// mlx_string_put(params->mlx_ptr, params->win_ptr ,params->x - 100, 10, 255, "ok");
	// }
	raycast(params);
	return (0);
}

int		key_hook(int keydown, t_param *params)
{
	if (keydown == 53)
	{
		mlx_clear_window(params->mlx_ptr, params->win_ptr);
		mlx_destroy_image(params->mlx_ptr, params->img_ptr);
		mlx_destroy_window(params->mlx_ptr, params->win_ptr);
		exit(0);
	}
	if (keydown == 35)
		params->sprite *= -1;
	printf("%d key\n",keydown);
	if (keydown == 123)
		cam_rotation(keydown, params);
	if (keydown == 124)
		cam_rotation(keydown, params);
	// MOVEMENT
	if (keydown == 0)
	{
		if (params->map[(int)(params->data->map_posX + params->ray->planeX * 0.1)][(int)(params->data->map_posY)] != '1')
				params->data->map_posX -= params->ray->planeX * 0.1;
			if (params->map[(int)(params->data->map_posX)][(int)(params->data->map_posY + params->ray->planeY * 0.1)])	
				params->data->map_posY -= params->ray->planeY * 0.1;
	}
	if (keydown == 1)
	{
		if (params->map[(int)(params->data->map_posX - params->ray->dirX * 0.1)][(int)(params->data->map_posY)] != '1')
			params->data->map_posX -= params->ray->dirX * 0.1;
		if (params->map[(int)(params->data->map_posX)][(int)(params->data->map_posY - params->ray->dirY * 0.1)])	
			params->data->map_posY -= params->ray->dirY * 0.1;
	}
	if (keydown == 2)
	{
		if (params->map[(int)(params->data->map_posX + params->ray->planeX * 0.1)][(int)(params->data->map_posY)] != '1')
				params->data->map_posX += params->ray->planeX * 0.1;
			if (params->map[(int)(params->data->map_posX)][(int)(params->data->map_posY + params->ray->planeY * 0.1)])	
				params->data->map_posY += params->ray->planeY * 0.1;
	}
	if (keydown == 13)
	{
			if (params->map[(int)(params->data->map_posX + params->ray->dirX * 0.1)][(int)(params->data->map_posY)] != '1')
				params->data->map_posX += params->ray->dirX * 0.1;
			if (params->map[(int)(params->data->map_posX)][(int)(params->data->map_posY + params->ray->dirY * 0.1)])	
				params->data->map_posY += params->ray->dirY * 0.1;
	}
	// raycast(params);
	return (0);
} 

int main(int arc, char** argv)
{
	// t_ray 	ray = {-1,0,0,0.66,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	// t_data	data = {0,0,0,0,0,0,0};
	t_texture map = {0,0,0,0,0,0,0,0};
	t_texture texture = {NULL,NULL,NULL,NULL,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	t_ray 	ray;
	t_data	data;
	t_param params /*= {0,0,0,0,0,0,0,0,0,NULL,NULL,NULL,NULL,NULL,0,0,0,0,0,NULL,NULL,NULL,&data,&ray,&texture}*/;

	params.rad = 500;
	params.sprite = -1;
	init_data(&data);
    init_ray(&ray);
	init_sruct(&params);
	params.data            = &data;
    params.ray             = &ray;
    params.texture         = &texture;
	fill_params(argv[1], &params);
	// printf("%d\n",check_map(params.map));
	check_ini_pos(params.map, params.data);
	printf_struct(&params);
	write(1, "ok\n", 3);
	// write(1, "ok\n", 3);
	// write(1, "ok\n", 3);
	params.mlx_ptr = mlx_init();
	params.win_ptr = mlx_new_window(params.mlx_ptr, params.x, params.y, "test");
	params.texture->south_img_ptr = mlx_xpm_file_to_image(params.mlx_ptr,"brick.XPM", &params.texture->sizeX1, &params.texture->sizeY1);
	params.texture->east_img_ptr = mlx_xpm_file_to_image(params.mlx_ptr,"dio6.XPM", &params.texture->sizeX2, &params.texture->sizeY2);
	// write(1, "ok\n", 3);
	// init_texture(&params);
	// write(1, "ok\n", 3);
	raycast(&params);
	// write(1, "ok\n", 3);
	mlx_loop_hook(params.mlx_ptr, &loop_hook, &params);
	mlx_hook(params.win_ptr, 2,1L<<0,&key_hook,&params);
	mlx_loop(params.mlx_ptr);
	return (0);
}
