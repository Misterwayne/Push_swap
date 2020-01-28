/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 15:01:18 by mwane             #+#    #+#             */
/*   Updated: 2020/01/27 13:48:36 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "cub3D.h"

void	get_colors(char *line, t_param *params);

char*	cpy_path(char *line)
{
	int  i;
	char *params;

	i = 0;
	while (line[i] != '.')
		i++;
	params = ft_strdup(line + i);
	free(line);
	return (params);
}

void	get_res(char *line, t_param *params)
{
	int i;

	i = 0;
	while (line[i] == ' ' || line[i] == 'R') 
		i++;
	params->x = ft_atoi(line + i);
	while(line[i] >= '0' && line[i] <= '9')
		i++;
	params->y = ft_atoi(line + i);
	free(line);
}

void	fill_params(char* str, t_param *params)
{
	int 	fd;
	char* 	line;
	int		i;

	i = 0;
	fd = open(str, O_RDONLY);
	get_path(params, fd);
	return ;
}

void	get_path(t_param *params, int fd)
{
	char*	line;
	int		i;

	i = 1;
	while (i > 0)
	{
		i = get_real_line(fd, &line);
		if (line[0] == 'N')
			params->NO = cpy_path(line);
		else if (line[0] == 'S' && line[1] == 'O')
			params->SO = cpy_path(line);
		else if (line[0] == 'W')
			params->WE = cpy_path(line);
		else if (line[0] == 'E')
			params->EA = cpy_path(line);
		else if (line[0] == 'S')
			params->S = cpy_path(line);
		else if (line[0] == 'F')
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
			params->map = malloc(sizeof(char) * 100);
			params->map[0] = ft_strdup(line);
			free(line);
			get_map(fd, params);
		}
	}
	return ;
}

void	get_colors(char* line, t_param *params)
{
	int	  i;

	i = 1;
	params->r = ft_atoi(line + i);
	while (line[i] != ',')
		i++;
	params->g = ft_atoi(line + ++i);
	while (line[i] != ',')
		i++;
	params->b = ft_atoi(line + i + 1);
}

int		rgb1(int r, int g, int b)
{
	int c;

	c = r;  
  	c = (c << 8) | g;
  	c = (c << 8) | b;
  	return c;
}

void	get_map(int fd, t_param *params)
{
	char* line;
	int i;

	i = 1;
	while (get_real_line(fd, &line) > 0)
	{
		params->map[i++] = ft_strdup(line);
		free(line);
	}
	params->map[i++] = ft_strdup(line);
	params->map[0] = ft_strdup(params->map[0]);
	params->map[i] = NULL;
	free(line);
}