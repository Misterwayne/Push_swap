/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 15:01:18 by mwane             #+#    #+#             */
/*   Updated: 2019/12/06 12:50:33 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "cub3D.h"

void	get_colors(int fd, t_param *params);

void	fill_params(char* str, t_param *params)
{
	int 	fd;
	char* 	line;
	int		i;

	i = 0;
	fd = open(str, O_RDONLY);
	get_real_line(fd, &line);
	while (line[i] == ' ' || line[i] == 'R') 
		i++;
	params->x = ft_atoi(line + i);
	while(line[i] >= '0' && line[i] <= '9')
		i++;
	params->y = ft_atoi(line + i);
	free(line);
	get_real_line(fd, &line);
	i = 0;
	while (line[i] != '.')
		i++;
	params->NO = ft_strdup(line + i);
	free(line);
	get_real_line(fd, &line);
	i = 0;
	while (line[i] != '.')
		i++;
	params->SO = ft_strdup(line + i);
	get_path(params, fd);
	free(line);
	return ;
}

void	get_path(t_param *params, int fd)
{
	char*	line;
	int		i;

	i = 0;
	get_real_line(fd, &line);
	while (line[i] != '.')
		i++;
	params->WE = ft_strdup(line + i);
	free(line);
	get_real_line(fd, &line);
	i = 0;
	while (line[i] != '.')
		i++;
	params->EA = ft_strdup(line + i);
	free(line);
	get_real_line(fd, &line);
	i = 0;
	while (line[i] != '.')
		i++;
	params->S = ft_strdup(line + i);
	free(line);
	get_colors(fd, params);
	params->F = rgb1(params->r, params->g, params->b);
	get_colors(fd, params);
	params->C = rgb1(params->r, params->g, params->b);
	printf("line = %s\n",params->WE);
	get_map(fd, params);
	return ;
}

void	get_colors(int fd, t_param *params)
{
	char* line;
	int	  i;

	i = 1;
	get_real_line(fd, &line);
	params->r = ft_atoi(line + i);
	while (line[i] != ',')
		i++;
	params->g = ft_atoi(line + ++i);
	while (line[i] != ',')
		i++;
	params->b = ft_atoi(line + i + 1);
	free(line);
}

int		rgb1(int r, int g, int b)
{
  int c = r;
  
  c = (c << 8) | g;
  c = (c << 8) | b;
  return c;
}

void	get_map(int fd, t_param *params)
{
	char* line;
	int i;

	i = 0;
	params->map = malloc(sizeof(char) * 100);
	printf("line3 = %s\n",params->WE);
	while (get_real_line(fd, &line) > 0)
	{
		params->map[i++] = ft_strdup(line);
		free(line);
	}
	params->map[i++] = ft_strdup(line);
	params->map[i] = NULL;
	free(line);
	printf("line4 = %s\n",params->WE);
}