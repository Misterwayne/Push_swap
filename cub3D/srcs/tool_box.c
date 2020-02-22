/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_box.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 11:28:18 by mwane             #+#    #+#             */
/*   Updated: 2020/02/22 13:59:28 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		get_real_line(int fd, char **line)
{
	int v;

	v = get_next_line(fd, line);
	while (**line == '\0' && v > 0)
	{
		free(*line);
		v = get_next_line(fd, line);
	}
	return (v);
}

int		check_str_res(char *line)
{
	int i;
	int u;

	i = 1;
	u = 0;
	if (line[0] == 'R')
	{
		while (line[i])
		{
			if (line[i - 1] == ' ' && (line[i] >= '0' && line[i] <= '9'))
				u++;
			if (line[i] == ' ' || (line[i] >= '0' && line[i] <= '9'))
				i++;
			else
				return (1);
		}
	}
	if (u > 2)
		return (1);
	return (0);
}

int		check_str_color(char *line)
{
	int		i;
	int		j;
	int		u;

	i = 1;
	u = 0;
	while (line[i])
	{
		if (line[i] == ',')
		{
			j = i - 1;
			while (line[j] == ' ')
				j--;
			if (line[j - 1] < '0' || line[j - 1] > '9')
				return (1);
		}
		if (line[i] == ',' || line[i] == ' ' ||
		(line[i] >= '0' && line[i] <= '9'))
			i++;
		else
			return (1);
	}
	return (0);
}

int		check_params(t_param *params)
{
	if (params->x == 0 || params->y == 0)
		return (1);
	if (params->f == 0 || params->c == 0)
		return (1);
	else
		return (0);
}

int		get_pos2(char **map, t_param *params, int x, int y)
{
	if (map[x][y] == 'S')
	{
		if (params->map_y == 0)
		{
			params->map_y = y + 0.5;
			params->map_x = x + 0.5;
			params->ray->vecx = 1;
			params->ray->planey = -0.66;
		}
		else
			error_msg("error spawn point S", params);
	}
	else if (map[x][y] == 'E')
	{
		if (params->map_y == 0)
		{
			params->map_y = y + 0.5;
			params->map_x = x + 0.5;
			params->ray->vecy = 1;
			params->ray->planex = 0.66;
		}
		else
			error_msg("error spawn point E", params);
	}
	return (1);
}
