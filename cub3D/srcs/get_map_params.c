/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 15:01:18 by mwane             #+#    #+#             */
/*   Updated: 2020/02/14 19:58:45 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "../include/cub3D.h"

void	get_colors(char *line, t_param *params)
{
	int i;

	i = 1;
	params->r = ft_atoi(shave_str(line + i, ' '));
	if (params->r > 255)
		params->r = 255;
	while (line[i] != ',')
		i++;
	params->g = ft_atoi(shave_str(line + ++i, ' '));
	if (params->g > 255)
		params->g = 255;
	while (line[i] != ',')
		i++;
	params->b = ft_atoi(shave_str(line + i + 1, ' '));
	if (params->b > 255)
		params->b = 255;
	free(line);
}

void	get_res(char *line, t_param *params)
{
	int i;

	i = 0;
	while (line[i] == ' ' || line[i] == 'R')
		i++;
	params->x = ft_atoi(shave_str(line + i, ' '));
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	params->y = ft_atoi(shave_str(line + i, ' '));
	if (params->y < 0 || params->x < 0)
		error_msg("error parametre",params);
	if (params->y > 1440)
		params->y = 1400;
	if (params->x > 2560)
		params->x = 2560;
	free(line);
}

void	fill_params(char *str, t_param *params)
{
	int		fd;
	int		i;

	i = 0;
	fd = open(str, O_RDONLY);
	get_path(params, fd);
	return ;
}

void	get_path(t_param *params, int fd)
{
	char	*line;

	while (get_real_line(fd, &line) > 0)
	{
		get_path_info(line, params);
		if (line[0] == 'F')
		{
			get_colors(line, params);
			params->F = rgb1(params->r, params->g, params->b);
			if (params->F > 16777215)
				params->F = 16777215;
		}
		else if (line[0] == 'C')
		{
			get_colors(line, params);
			params->C = rgb1(params->r, params->g, params->b);
			if (params->C > 16777215)
				params->C = 16777215;
		}
		else if (line[0] == 'R')
			get_res(line, params);
		else if (line[0] == '1')
		{
			params->map = NULL;
			if(!(params->map = malloc(sizeof(char*) * 100)))
				return ;
			get_map(fd, params, line);
		}
	}
	free(line);
	close(fd);
}

void	get_map(int fd, t_param *params, char *fl)
{
	char	*line;
	int		i;
	int		x;

	i = 1;
	x = 0;
	line = NULL;
	params->map[x] = shave_str(fl, ' ');
	while (get_next_line(fd, &line) > 0)
	{
		if (line[0] == '1')
		{
			params->map[i++] = shave_str(line, ' ');
			if (x == 1)
				error_msg("error map", params);
		}
		else
			x = 1;
		free(line);
	}
	params->map[i++] = shave_str(line, ' ');
	params->map[14] = NULL;
	free(line);
}
