/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_option.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 15:39:27 by mwane             #+#    #+#             */
/*   Updated: 2020/02/10 13:40:28 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	is_save_real(char *option, t_param *params)
{
	if (option)
	{
		if (ft_strncmp("-save",option,5) == 0)
			params->option = 1;
		else
			params->option = 0;
	}
	else
		params->option = 0;
	return ;
}

int		bitmap_info_header(t_param *mlx_img, int fd)
{
	int header_info_size;
	int plane_nbr;
	int o_count;

	header_info_size = 40;
	plane_nbr = 1;
	write(fd, &header_info_size, 4);
	write(fd, &mlx_img->bmp->width, 4);
	write(fd, &mlx_img->bmp->height, 4);
	write(fd, &plane_nbr, 2);
	write(fd, &mlx_img->texture->bpp, 2);
	o_count = 0;
	while (o_count < 28)
	{
		write(fd, "\0", 1);
		o_count++;
	}
	return (1);
}

void	save_bitmap(t_param *params, char *map_img)
{
	int		fd;
	int		images_size;
	Bitmap	bmp;
	int		file_size;
	int		first_pix;

	params->bmp = &bmp;
	params->bmp->width = params->x;
	params->bmp->height = params->y;
	images_size = params->bmp->width * params->bmp->height;
	if (!(fd = open("cub3d.BMP", O_RDWR | O_CREAT, 0666)))
		destroy_window(params);
	file_size = images_size + 58;
	first_pix = 58;
	write(fd, "BM", 2);
	write(fd, &file_size, 4);
	write(fd, "\0\0\0\0", 4);
	write(fd, &first_pix, 4);
	first_pix = images_size;
	bitmap_info_header(params, fd);
	while (--first_pix >= 0)
		write(fd, &map_img[first_pix * 32 / 8], 4);
	close(fd);
}
