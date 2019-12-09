/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 16:37:33 by mwane             #+#    #+#             */
/*   Updated: 2019/12/09 17:45:06 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CUB3D_H
# define _CUB3D_H
# include <fcntl.h>
# include <stdio.h>
# include "libft2/libft.h"
#include "gnl/get_next_line.h"


typedef struct 	s_param
{
	void *win_ptr;
	void *mlx_ptr;
	int 		x;
	int 		y;
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
}              	t_param;

typedef struct	s_data
{
	int			cam_height;
	int			cam_angle;
	float		fov;
	float		cam_posX;
	float		cam_posY;
	int			sreen_size;
}				t_data;

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

#endif