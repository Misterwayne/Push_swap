/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_param2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 19:00:08 by mwane             #+#    #+#             */
/*   Updated: 2020/02/17 18:46:45 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

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

	i = 2 ;
	path = shave_str(line + i,' ');
	free(line);
	return (path);
}

int		get_path_info(char *line, t_param *params)
{
	if (line[0] == 'N' && line[1] == 'O')
		params->NO = cpy_path(line);
	else if (line[0] == 'S' && line[1] == 'O')
		params->SO = cpy_path(line);
	else if (line[0] == 'W' && line[1] == 'E')
		params->WE = cpy_path(line);
	else if (line[0] == 'E' && line[1] == 'A')
		params->EA = cpy_path(line);
	else if (line[0] == 'S')
		params->S = cpy_path(line);
	else
		return (1);
	params->par_nbr += 1;
	return (0);
}
