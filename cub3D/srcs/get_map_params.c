/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 15:01:18 by mwane             #+#    #+#             */
/*   Updated: 2020/02/23 19:06:57 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	get_res(char *line, t_param *params)
{
	int		i;

	i = 0;
	if (params->x != -1 || params->y != -1)
		error_msg("error 2 same parameter", params);
	if (check_str_res(line) == 1)
		error_msg("error resolution\n", params);
	while (line[i] == ' ' || line[i] == 'R')
		i++;
	params->x = ft_atoi(line + i);
	if (check_len(line + i) == 1)
		params->x = 2560;
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	params->y = ft_atoi(line + i);
	if (check_len(line) == 1)
		params->y = 1440;
	if (params->y <= 0 || params->x <= 0)
		error_msg("res null or negative\n", params);
	if (params->y > 1440)
		params->y = 1440;
	if (params->x > 2560)
		params->x = 2560;
	free(line);
}

void	check_file_name(char *str, t_param *params)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	if (str[i - 1] != 'b')
		error_msg("bad file name\n", params);
	if (str[i - 2] != 'u')
		error_msg("bad file name\n", params);
	if (str[i - 3] != 'c')
		error_msg("bad file name\n", params);
	if (str[i - 4] != '.')
		error_msg("bad file name\n", params);
}

void	fill_params(char *str, t_param *params)
{
	int		fd;
	int		i;

	i = 0;
	check_file_name(str, params);
	fd = open(str, O_RDONLY);
	if (fd < 0)
		error_msg("error map file\n", params);
	get_path(params, fd);
	if (params->c == -1 || params->f == -1)
		error_msg("error parametre\n", params);
	if (params->x == -1 || params->y == -1)
		error_msg("error parametre\n", params);
	if (params->map == NULL || params->map[2] == NULL)
		error_msg("error parametre\n", params);
	return ;
}

int		lot_of_if(char *line, t_param *params, int fd)
{
	if (line[0] == 'F')
		get_f(line, params);
	else if (line[0] == 'C')
		get_c(line, params);
	else if (line[0] == 'R')
		get_res(line, params);
	else if (line[0] == '1' || line[0] == '0')
	{
		params->map = NULL;
		if (!(params->map = malloc(sizeof(char *) * 100)))
			return (0);
		get_map(fd, params, line);
		free(line);
	}
	else
		return (0);
	return (1);
}

void	get_path(t_param *params, int fd)
{
	char	*line;
	int		i;

	i = 0;
	while (get_real_line(fd, &line) > 0)
	{
		if (lot_of_if(line, params, fd) == 0)
			if (line[0] != ' ')
				if (get_path_info(line, params) == 1)
					error_msg("error param\n", params);
	}
	free(line);
	close(fd);
}
