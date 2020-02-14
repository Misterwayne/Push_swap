/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 14:18:13 by mwane             #+#    #+#             */
/*   Updated: 2020/02/14 20:39:20 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
- rien apres la ;ap
- resoluton de l'ecran trop grande
- coleur enntre 0 255
- refaire le parfsing encore
- espace avant la map
- deux spawnpoint
- parametre de la map
- les couleurs
- d'autres chiffres dans la carte
- space avant les R - NO ?
- deux SS
- E and S
- no spawnpoint
faire le Makefile
*/

#include "../include/cub3D.h"

void	error_msg(char *msg, t_param *params)
{
	write(1, msg, ft_strlen(msg));
	exit(1);
}

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
		destroy_window(params);
	}
	mlx_hook(params->win_ptr, 2, 1L << 0, &key_hook, params);
	mlx_hook(params->win_ptr, 17, 1L << 22, &destroy_window, params);
	return (0);
}

int		main(int arc, char **argv)
{
	t_texture	map;
	t_texture	texture;
	t_ray		ray;
	t_data		data;
	t_param		params;
	t_sprites 	sprite;

	init_sruct(&params, &sprite, &data, &ray);
	init_text(&texture);
	init_text(&map);
	params.sprite = &sprite;
	params.map_info = &map;
	params.data = &data;
	params.ray = &ray;
	params.texture = &texture;
	fill_params(argv[1], &params);
	printf_struct(&params);
	is_save_real(argv[2], &params);
	check_ini_pos(params.map, &params);
	if (check_map(params.map))
		error_msg("error map",&params);
	params.mlx_ptr = mlx_init();
	params.win_ptr = mlx_new_window(params.mlx_ptr,
	params.x, params.y, "cub3D");
	init_texture(&params);
	raycast(&params);
	mlx_put_image_to_window(params.mlx_ptr, params.win_ptr, params.img_ptr
	, 0, 0);
	mlx_loop_hook(params.mlx_ptr, &loop_hook, &params);
	mlx_loop(params.mlx_ptr);
	return (0);
}
