/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 15:01:18 by mwane             #+#    #+#             */
/*   Updated: 2020/02/17 18:57:03 by mwane            ###   ########.fr       */
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
	if (params->r > 255 || params->r < 0)
		error_msg("color error\n",params);
	while (line[i] != ',')
		i++;
	params->g = ft_atoi(line + ++i);
	if (params->g > 255 || params->g < 0)
		error_msg("color error 2\n",params);
	while (line[i] != ',')
		i++;
	params->b = ft_atoi(line + i + 1);
	if (params->b > 255 || params->b < 0)
		error_msg("color error 3\n",params);
	free(line);
}

void	get_res(char *line, t_param *params)
{
	int i;

	i = 0;
	params->par_nbr += 1;
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
	if (ft_strnstr(str, ".cub", ft_strlen(str)) == 0)
		error_msg("error map file\n", params);
	fd = open(str, O_RDONLY);
	if (fd < 0)
		error_msg("error map file\n", params);
	get_path(params, fd);
	if (params->map == NULL)
		error_msg("missing param\n", params);
	return ;
}

void	get_path(t_param *params, int fd)
{
	char	*line;
	int 	i;

	i = 0;
	while (get_real_line(fd, &line) > 0)
	{
		i++;
		if (line[0] == 'F')
		{
			get_colors(line, params);
			params->F = rgb1(params->r, params->g, params->b);
			params->par_nbr += 1;
		}
		else if (line[0] == 'C')
		{
			get_colors(line, params);
			params->C = rgb1(params->r, params->g, params->b);
			params->par_nbr += 1;
		}
		else if (line[0] == 'R')
			get_res(line, params);
		else if (shave_str(line, ' ')[0] == '1')
		{
			params->par_nbr += 1;
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
	if (i != 9)
		error_msg("missing param\n",params);
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
	params->map[x] = ft_strdup(fl);
	while (get_next_line(fd, &line) > 0)
	{
		if (shave_str(line, ' ')[0] == '1')
			params->map[i++] = ft_strdup(line);
		else if (line[0] != '1' && line[0] != ' ' && line[0] != '0')
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
