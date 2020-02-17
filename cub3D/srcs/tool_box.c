/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_box.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 11:28:18 by mwane             #+#    #+#             */
/*   Updated: 2020/02/17 18:05:36 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int    get_real_line(int fd, char **line)
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

int		check_str(char *line)
{
	int i;
	int u;

	i = 1;
	u = 0;
	if (line[0] == 'R')
	{
		while (line[i])
		{
			if (line[i] == ' ' || (line[i] >= '0' && line[i] <= '9'))
				i++;
			else
				return (1);
		}
	}
	else
	{
		while (line[i])
		{
			if (line[i] == ',')
				if (line[i - 1] < '0' || line[i - 1] > '9')
					return (1);
			if (line[i] == ',' || line[i] == ' ' || (line[i] >= '0' && line[i] <= '9'))
				i++;
			else
				return (1);
		}
	}
	return (0);
}

void    printf_struct(t_param *params)
{
	int i;

	i = 0;
	printf("C = %d\n",params->C);
	printf("NO = %s\n",params->NO);
	printf("SO = %s\n",params->SO);
	printf("WE = %s\n",params->WE);
	printf("EA = %s\n",params->EA);
	printf("F = %ld\n",params->F);
	printf("r = %d\n",params->r);
	printf("x = %d\n",params->x);
	printf("y = %d\n",params->y);
	printf("g = %d\n",params->g);
	printf("b = %d\n",params->b);
	printf("R = x:%ld y:%ld\n",params->x,params->y);
	while (params->map[i] != NULL)
		printf("map = %s\n",params->map[i++]);
}

int       check_params(t_param *params)
{
	if (params->x == 0 || params->y == 0)
		return (1);
	if (params->F == 0 || params->C == 0)
		return (1);
	else
		return (0);
}

char	*shave_str(char *str, char c)
{
	int		i;
	int		y;
	char	*nstr;
	
	i = 0;
	y = 0;
	if (!(nstr = malloc(sizeof(char) * ft_strlen(str) + 1)))
		return (NULL);
	while (str[i])
	{
		if (str[i] != c)
			nstr[y++] = str[i];
		i++;
	}
	nstr[y] = 0;
	return (nstr);
}

int		get_pos2(char **map, t_param *params, int x, int y)
{
	if (map[x][y] == 'S')
	{
		if (params->data->map_posY == 0)
		{
			params->data->map_posY = y + 0.5;
			params->data->map_posX = x + 0.5;
			params->ray->dirX = 1;
			params->ray->dirY = 0;
			params->ray->planeX = 0;
    		params->ray->planeY = -0.66;
		}
		else
			error_msg("error spawn point S",params);
		return (1);

	}
	else if (map[x][y] == 'E')
	{
		if (params->data->map_posY == 0)
		{
			params->data->map_posY = y + 0.5;
			params->data->map_posX = x + 0.5;
			params->ray->dirX = 0;
			params->ray->dirY = 1;
			params->ray->planeX = 0.66;
    		params->ray->planeY = 0;
		}
		else
			error_msg("error spawn point E",params);
		return (1);
	}
	return (0);
}

void		checkform(char *line, t_param *params, int *i)
{
	int y;

	y = *i;
	while (line[y] == ' ')
		y++;
	while ((line[y] >= '0' && line[y] <= '9'))
		y++;
	if (line[y] != ',')
		error_msg("error color\n",params);
	*i = y;
}