/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_param2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 19:00:08 by mwane             #+#    #+#             */
/*   Updated: 2020/02/10 17:43:50 by mwane            ###   ########.fr       */
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
	char	*params;

	i = 0;
	while (line[i] != '.')
		i++;
	params = ft_strdup(line + i);
	free(line);
	return (params);
}

void	get_path_info(char *line, t_param *params)
{
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
}