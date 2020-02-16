/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 15:01:18 by mwane             #+#    #+#             */
/*   Updated: 2020/02/16 18:54:13 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "../include/cub3D.h"

void	get_colors(char *line, t_param *params)
{
	int i;

	i = 1;
	if (check_str(line) == 1)
		error_msg("error color\n",params);
	params->r = ft_atoi(line + i);
	if (params->r > 255)
		params->r = 255;
	while (line[i] != ',')
		i++;
	params->g = ft_atoi(line + ++i);
	if (params->g > 255)
		params->g = 255;
	while (line[i] != ',')
		i++;
	params->b = ft_atoi(line + i + 1);
	if (params->b > 255)
		params->b = 255;
	free(line);
}

void	get_res(char *line, t_param *params)
{
	int i;

	i = 0;
	if (check_str(line) == 1)
		error_msg("error color\n",params);
	while (line[i] == ' ' || line[i] == 'R')
		i++;
	params->x = ft_atoi(line + i);
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	params->y = ft_atoi(line + i);
	if (params->y < 0 || params->x < 0)
		error_msg("error parametre",params);
	if (params->y > 1440)
		params->y = 1440;
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
		if (line[0] == 'F')
		{
			get_colors(line, params);
			params->F = rgb1(params->r, params->g, params->b);
		}
		else if (line[0] == 'C')
		{
			get_colors(line, params);
			params->C = rgb1(params->r, params->g, params->b);
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
		else
		{
			if (line[0] != ' ')
			{
				if (get_path_info(line, params) == 1)
					error_msg("error param\n",params);
			}
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
			params->map[i++] = shave_str(line, ' ');
		else if (line[0] == '\0' || line[0] == ' ')
			x = 1;
		else
			error_msg("error params 2", params);
		if (line[0] == '1' && x == 1)
			error_msg("error params 3", params);
		free(line);
	}
	if (line[0] != '\0')
		params->map[i] = shave_str(line, ' ');
	params->map[++i] = NULL;
	free(line);
	free(fl);
}
