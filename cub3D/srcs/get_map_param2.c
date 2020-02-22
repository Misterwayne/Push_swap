/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_param2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 19:00:08 by mwane             #+#    #+#             */
/*   Updated: 2020/02/21 21:10:21 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		rgb1(int r, int g, int b)
{
	int c;

	c = r;
	c = (c << 8) | g;
	c = (c << 8) | b;
	return (c);
}

char	*cpy_path(char *line)
{
	int		i;
	char	*path;

	i = 2;
	path = shave_str(line + i, ' ');
	free(line);
	return (path);
}

void	check_path(t_param *params, char *path)
{
	if (path != NULL)
		error_msg("error 2 same param\n", params);
}

int		get_path_info(char *line, t_param *params)
{
	if (line[0] == 'N' && line[1] == 'O')
	{
		check_path(params, params->no);
		params->no = cpy_path(line);
	}
	else if (line[0] == 'S' && line[1] == 'O')
	{
		check_path(params, params->so);
		params->so = cpy_path(line);
	}
	else
		return (get_path_info2(line, params));
	return (0);
}

int		get_path_info2(char *line, t_param *params)
{
	if (line[0] == 'W' && line[1] == 'E')
	{
		check_path(params, params->we);
		params->we = cpy_path(line);
	}
	else if (line[0] == 'E' && line[1] == 'A')
	{
		check_path(params, params->ea);
		params->ea = cpy_path(line);
	}
	else if (line[0] == 'S')
	{
		check_path(params, params->s);
		params->s = cpy_path(line);
	}
	else
		return (1);
	return (0);
}
