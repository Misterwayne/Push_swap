/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 14:18:13 by mwane             #+#    #+#             */
/*   Updated: 2020/02/23 19:19:14 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		destroy_window(t_param *params)
{
	mlx_clear_window(params->mlx_ptr, params->win_ptr);
	mlx_destroy_image(params->mlx_ptr, params->img_ptr);
	mlx_destroy_window(params->mlx_ptr, params->win_ptr);
	exit(1);
	return (0);
}

int		key_hook(int keydown, t_param *params)
{
	if (keydown == 53)
		destroy_window(params);
	if (keydown == 123)
		cam_rotation(keydown, params);
	if (keydown == 124)
		cam_rotation(keydown, params);
	if (keydown == 0)
		move_left(params);
	if (keydown == 1)
		move_back(params);
	if (keydown == 2)
		move_right(params);
	if (keydown == 13)
		move_forward(params);
	raycast(params);
	mlx_put_image_to_window(params->mlx_ptr, params->win_ptr, params->img_ptr
	, 0, 0);
	return (0);
}

int		loop_hook(t_param *params)
{
	if (params->option == 1)
	{
		save_bitmap(params, params->map_info->img);
		exit(1);
	}
	mlx_put_image_to_window(params->mlx_ptr, params->win_ptr, params->img_ptr
	, 0, 0);
	mlx_hook(params->win_ptr, 2, 1L << 0, &key_hook, params);
	mlx_hook(params->win_ptr, 17, 1L << 22, &destroy_window, params);
	return (0);
}

void	part_2(t_param *params)
{
	check_ini_pos(params->map, params);
	if (check_map(params->map))
		error_msg("error map 1\n", params);
	params->mlx_ptr = mlx_init();
	if (params->option == 0)
		params->win_ptr = mlx_new_window(params->mlx_ptr,
		params->x, params->y, "cub3D");
	init_texture(params);
	raycast(params);
	if (params->option == 0)
		mlx_put_image_to_window(params->mlx_ptr,
		params->win_ptr, params->img_ptr
		, 0, 0);
}

int		main(int arc, char **argv)
{
	t_texture	map;
	t_texture	texture;
	t_ray		ray;
	t_param		params;
	t_sprites	sprite;

	init_sruct(&params, &sprite, &ray);
	init_text(&texture);
	init_text(&map);
	(void)arc;
	params.sprite = &sprite;
	params.map_info = &map;
	params.ray = &ray;
	params.texture = &texture;
	fill_params(argv[1], &params);
	is_save_real(argv[2], &params);
	part_2(&params);
	mlx_loop_hook(params.mlx_ptr, &loop_hook, &params);
	mlx_loop(params.mlx_ptr);
	return (0);
}
