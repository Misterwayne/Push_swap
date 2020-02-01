/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 14:18:13 by mwane             #+#    #+#             */
/*   Updated: 2020/02/01 19:01:19 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
-- Sprite
-- l'option save
-- Mettre a la norme
-- check les leaks
faire le Makefile
*/




#include "../include/cub3D.h"

int		loop_hook(t_param *params)
{
	char buffer[20];
	// if (params->sprite != 1);
		// mlx_put_image_to_window(params->mlx_ptr, params->win_ptr, params->img_ptr, 0, 0);
	// mlx_string_put(params->mlx_ptr, params->win_ptr,params->x/2,params->y/2,0xFFFFFF,ft_strjoin(ft_itoa(params->ray->dirX)," dirX"));
	// mlx_string_put(params->mlx_ptr, params->win_ptr,params->x/2,params->y/2 - 100/2,0xFFFFFF,ft_strjoin(ft_itoa(params->ray->dirY)," dirY"));
	// mlx_string_put(params->mlx_ptr, params->win_ptr,params->x/2,params->y/2 - 200/2,0xFFFFFF,ft_strjoin(ft_itoa(params->ray->deltaDistX)," deltadistX"));
	// mlx_string_put(params->mlx_ptr, params->win_ptr,params->x/2,params->y/2 - 300/2,0xFFFFFF,ft_strjoin(ft_itoa(params->ray->deltaDistY)," deltadistY"));
	// mlx_string_put(params->mlx_ptr, params->win_ptr,params->x/2,params->y/2 - 400/2,0xFFFFFF,ft_strjoin(ft_itoa(params->ray->sidedistX)," sidedistX"));
	// mlx_string_put(params->mlx_ptr, params->win_ptr,params->x/2,params->y/2 - 500/2,0xFFFFFF,ft_strjoin(ft_itoa(params->ray->sidedistY)," sidedistY"));
	// mlx_string_put(params->mlx_ptr, params->win_ptr,params->x/2,params->y/2 - 600/2,0xFFFFFF,ft_strjoin(ft_itoa(params->ray->stepX)," stepX"));
	// mlx_string_put(params->mlx_ptr, params->win_ptr,params->x/2,params->y/2 - 700/3,0xFFFFFF,ft_strjoin(ft_itoa(params->ray->stepY)," stepY"));
	// if (params->sprite < 0)
	// {
	
	mini_map(params);
	mlx_put_image_to_window(params->mlx_ptr, params->win_ptr, params->img_ptr2, 0, 0);
		// mlx_string_put(params->mlx_ptr, params->win_ptr ,params->x - 100, 10, 255, "ok");
	// }
	raycast(params);
	return (0);
}
int 	destroy_window(t_param *params)
{
	mlx_clear_window(params->mlx_ptr, params->win_ptr);
	mlx_destroy_image(params->mlx_ptr, params->img_ptr);
	mlx_destroy_window(params->mlx_ptr, params->win_ptr);
	exit(0);
	return (0);
}
int		key_hook(int keydown, t_param *params)
{
	if (keydown == 53)
		destroy_window(params);
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
	t_texture map = {0,0,0,0,0,0,0,0};
	t_texture texture = {NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	t_ray 	ray;
	t_data	data;
	t_param params;

	init_data(&data);
    init_ray(&ray);
	init_sruct(&params);
	params.data            = &data;
    params.ray             = &ray;
    params.texture         = &texture;
	params.sprite = 1;
	fill_params(argv[1], &params);
	check_ini_pos(params.map, &params);
	printf_struct(&params);
	write(1, "sick\n", 5);
	params.mlx_ptr = mlx_init();
	params.win_ptr = mlx_new_window(params.mlx_ptr, params.x, params.y, "cub3D");
	init_texture(&params);
	write(1, "sick\n", 5);
	raycast(&params);
	write(1, "sick\n", 5);
	mlx_loop_hook(params.mlx_ptr, &loop_hook, &params);
	mlx_hook(params.win_ptr, 2,1L<<0,&key_hook,&params);
	mlx_hook(params.win_ptr, 17,1L<<22,&destroy_window, &params);
	mlx_loop(params.mlx_ptr);
	return (0);
}
