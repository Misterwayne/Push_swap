/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_params3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 20:58:02 by mwane             #+#    #+#             */
/*   Updated: 2020/02/23 14:37:03 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	get_map(int fd, t_param *params, char *fl)
{
	char	*temp;
	int		i;
	int		x;

	i = 0;
	x = 0;
	params->map[i++] = ft_strdup(fl);
	while (get_next_line(fd, &fl) > 0)
	{
		temp = shave_str(fl, ' ');
		free(fl);
		fl = temp;
		if (fl[0] == '1' || fl[0] == '0')
			params->map[i++] = ft_strdup(fl);
		else if (fl[0] != '1' && fl[0] != ' ' && fl[0] != '0')
			x = 1;
		else
			error_msg("error params 2", params);
		if ((fl[0] == '1' || fl[0] == '0') && x == 1)
			error_msg("error params 3", params);
		free(fl);
	}
	if (fl[0] != '\0')
		params->map[i++] = shave_str(fl, ' ');
	free(fl);
}

void	late_check(char *line, int i, t_param *params)
{
	while (line[i] == ' ')
		i++;
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	while (line[i] == ' ')
		i++;
	if (line[i] > 0)
		error_msg("color error 4\n", params);
}

void	get_colors(char *line, t_param *params)
{
	int		i;

	i = 1;
	if (check_str_color(line) == 1)
		error_msg("error color\n", params);
	params->r = ft_atoi(line + i);
	if (params->r > 255 || params->r < 0)
		error_msg("color error\n", params);
	while (line[i] != ',')
		i++;
	params->g = ft_atoi(line + ++i);
	if (params->g > 255 || params->g < 0)
		error_msg("color error 2\n", params);
	while (line[i] != ',')
		i++;
	params->b = ft_atoi(line + ++i);
	i++;
	if (params->b > 255 || params->b < 0)
		error_msg("color error 3\n", params);
	late_check(line, i, params);
	free(line);
}

int		check_len(char *line)
{
	int i;

	i = 0;
	while (line[i] && line[i] != ' ')
		i++;
	if (i > 4)
		return (1);
	return (0);
}
