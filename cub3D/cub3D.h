/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 16:37:33 by mwane             #+#    #+#             */
/*   Updated: 2020/01/24 18:34:11 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CUB3D_H
# define _CUB3D_H
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <time.h>
# include <stdlib.h>
# include <unistd.h>
# include <time.h>
# include <fcntl.h>
# include "libft2/libft.h"
# include "gnl/get_next_line.h"

typedef	struct	s_ray
{
	double 	dirX;
    double 	dirY;
    double 	planeX;
    double 	planeY;

	double posx;
	double posy;

    int 	x;
    double 	cameraX;
    int 	w;
    int 	h;

    int mapX;
    int mapY;

    double rayDirX;
    double rayDirY;

    double sidedistX;
    double sidedistY;

    double deltaDistX;
    double deltaDistY;

    double perpWallDist;

    int stepX;
    int stepY;

    int hit;
    int side;

    int lineheight;
    int drawstart;
    int drawend;
}				t_ray;

typedef struct	s_data
{
	int			cam_height;
	int			cam_angle;
	float		fov;
	float		cam_posX;
	float		cam_posY;
	int			screen_size;
	float 		map_posX;
	float		map_posY;
}				t_data;

typedef struct	s_texture
{
	char *	img;
	void*	img_ptr;
	double	wallx;
	double	wally;
	int		sizeY;
	int 	sizeX;
	int		d;
	int 	text_x;
	int 	text_y;
	int		size_line;
	int		bpp;
	int 	endian;
}				t_texture;

typedef struct 	s_param
{
	void *win_ptr;
	void *mlx_ptr;
	void *img_ptr;
	void *img_ptr2;
	int 		sprite;
	float 		rad;
	int 		x;
	int 		y;
	float 		angle;
	char*   	NO;
	char*   	SO;
	char*   	WE;
	char*   	EA;
	char*   	S;
	long    	F;
	int			r;
	int 		g;
	int			b;
	int     	C;
	char**		map;
	char**		dio;
	char**		jojo;
	t_data		*data;
	t_ray		*ray;
	t_texture	*texture;
}              	t_param;


void			fill_params(char* str, t_param *params);
static int		get_str_len(long nbr);
char			*ft_itoa(int n);
void			get_path(t_param *params, int fd);
int 			rgb1(int r, int g, int b);
void			get_colors(char* line, t_param *params);
int	    		get_real_line(int fd, char **line);
void			get_map(int fd, t_param *params);
void    		printf_struct(t_param *params);
int       		check_params(t_param *params);
void			check_ini_pos(char **map, t_data *data);
int				check_map(char **map);
int				raycast(t_param *params);
int     		cam_rotation(int dir, t_param *params);
int				mini_map(t_param *params);

#endif