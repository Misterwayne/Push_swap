/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_box2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 17:51:40 by mwane             #+#    #+#             */
/*   Updated: 2020/02/21 21:07:36 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	get_f(char *line, t_param *params)
{
	if (params->f != -1)
		error_msg("2 same param\n", params);
	get_colors(line, params);
	params->f = rgb1(params->r, params->g, params->b);
}

void	get_c(char *line, t_param *params)
{
	if (params->c != -1)
		error_msg("2 same param C\n", params);
	get_colors(line, params);
	params->c = rgb1(params->r, params->g, params->b);
}

int		check_map2(char **map)
{
	int i;
	int y;

	i = 0;
	y = 0;
	while (map[i][y])
	{
		if (map[0][y] != '1')
			return (1);
		while (map[i] != NULL)
			i++;
		if (map[i - 1][y] != '1')
			return (1);
		y++;
		i = 0;
	}
	return (0);
}

void	checkform(char *line, t_param *params, int *i)
{
	int y;

	y = *i;
	while (line[y] == ' ')
		y++;
	while ((line[y] >= '0' && line[y] <= '9'))
		y++;
	if (line[y] != ',')
		error_msg("error color\n", params);
	*i = y;
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
