/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 16:37:33 by mwane             #+#    #+#             */
/*   Updated: 2020/02/21 16:47:49 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CUB3D_H
# define _CUB3D_H
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <string.h>
# include <time.h>
# include <stdlib.h>
# include <unistd.h>
# include <time.h>
# include <fcntl.h>
# include "../libft2/libft.h"
# include "../gnl/get_next_line.h"

typedef	struct	s_bitmap
{
	int			image_size;
	int			file_size;
	int			ppm;
	char		*file_name;
	int			width;
	int			height;
	int			dpi;
}				t_bitmap;

typedef	struct	s_sprite
{
	double		x;
	double		y;
	void		*img_ptr;
	char		*img;
	int			size_line;
	int			bpp;
	int			endian;
	int			texture;
	int			*sprite_order;
	double		*sprite_distance;
	double		spritey;
	double		spritex;
	double		indet;
	double		transx;
	double		transy;
	int			spritescreenx;
	int			spriteheight;
	int			spritewidth;
	int			draw_startx;
	int			draw_endx;
	int			draw_starty;
	int			draw_endy;
	int			stripe;
	int			size_x;
	int			size_y;
	char		**sprt_list;
}				t_sprites;

typedef	struct	s_ray
{
	double		vecx;
	double		vecy;
	double		planex;
	double		planey;
	double		posx;
	double		posy;
	int			x;
	double		camx;
	int			w;
	int			h;
	int			map_x;
	int			map_y;
	double		raydirx;
	double		raydiry;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	double		perpwalldist;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	int			lineheight;
	int			drawstart;
	int			drawend;
	int			text_y;
	double		wally;
	double		step;
	double		texpos;
	int			text_x;
}				t_ray;

typedef	struct	s_texture
{
	char		*img;
	void		*img_ptr;
	void		*west_img_ptr;
	void		*east_img_ptr;
	void		*south_img_ptr;
	void		*north_img_ptr;
	double		wallx;
	double		wally;
	int			sizey;
	int			sizex;
	int			sizey1;
	int			sizex1;
	int			sizey2;
	int			sizex2;
	int			sizey3;
	int			sizex3;
	int			sizey4;
	int			sizex4;
	int			d;
	int			text_x;
	int			text_y;
	int			size_line;
	int			bpp;
	int			endian;
}				t_texture;

typedef	struct	s_param
{
	int			numsprite;
	void		*win_ptr;
	void		*mlx_ptr;
	void		*img_ptr;
	void		*img_ptr2;
	int			option;
	float		map_y;
	float		map_x;
	long long	x;
	long long	y;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*s;
	long		f;
	int			r;
	int			par_nbr;
	int			g;
	int			b;
	long		c;
	char		**map;
	int			line_y;
	t_ray		*ray;
	t_texture	*texture;
	t_texture	*map_info;
	t_bitmap	*bmp;
	t_sprites	*sprite;
}				t_param;

void			fill_params(char *str, t_param *params);
void			save_bitmap(t_param *params, char *map_img);
char			*ft_itoa(int n);
void			get_path(t_param *params, int fd);
int				rgb1(int r, int g, int b);
void			get_colors(char *line, t_param *params);
int				get_real_line(int fd, char **line);
void			get_map(int fd, t_param *params, char *fl);
void			printf_struct(t_param *params);
int				check_params(t_param *params);
void			check_ini_pos(char **map, t_param *params);
int				get_pos(char **map, t_param *params, int x, int y);
int				get_pos2(char **map, t_param *params, int x, int y);
int				check_map(char **map);
int				raycast(t_param *params);
int				cam_rotation(int dir, t_param *params);
int				mini_map(t_param *params);
int				init_texture(t_param *params);
int				init_sruct(t_param *params, t_sprites *sprite, t_ray *ray);
void			init_ray(t_ray *ray);
int				destroy_window(t_param *params);
void			calcul_ray(t_param *params, double camerax);
void			get_depth(t_param *params);
int				draw_wall(int text_x, int x, t_param *params);
void			init_ray_data(t_param *params);
void			ray2(t_param *params);
void			move_forward(t_param *params);
void			move_back(t_param *params);
void			move_left(t_param *params);
void			move_right(t_param *params);
void			init_text(t_texture *tex);
int				get_path_info(char *line, t_param *params);
int				get_path_info2(char *line, t_param *params);
char			*cpy_path(char *line);
int				rgb1(int r, int g, int b);
void			is_save_real(char *option, t_param *params);
int				sprite(t_param *params, int x, double *zbuffer);
void			draw_sprite(t_param *params, double *zbuffer);
void			get_sprite(t_param *params, int x, int y, int i);
int				init_sprite(t_param *params, int i);
void			sort_sprite(t_param *params);
int				check_map2(char **map);
char			*shave_str(char *str, char c);
void			error_msg(char *msg, t_param *params);
void			draw_sprite2(t_param *params, double *zbuffer);
void			print_sprite(int y, int stripe, int text_x, t_param *params);
int				draw_floor(int x, int line_y, t_param *params);
int				draw_celing(int x, int line_y, t_param *params);
int				check_str(char *line);
void			checkform(char *line, t_param *params, int *i);
void			get_f(char *line, t_param *params);
void			get_c(char *line, t_param *params);
int				check_str_color(char *line);
int				check_str_res(char *line);
int				get_pos_w(char **map, t_param *params, int x, int y);
int				check_len(char *line);

#endif
