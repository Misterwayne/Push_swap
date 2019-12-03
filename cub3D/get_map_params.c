/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 15:01:18 by mwane             #+#    #+#             */
/*   Updated: 2019/12/03 17:50:26 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "cub3D.h"
#include "gnl/get_next_line.h"

void	fill_params(char* str, t_param *params)
{
	int 	fd;
	char* 	line;

	fd = open(str, O_RDONLY);
	get_next_line(fd, &line);
	while (*line == ' ' || *line == 'R') 
		line++;
	params->x = ft_atoi(line);
	while(*line >= '0' && *line <= '9')
		line++;
	params->y = ft_atoi(line);
	return ;
}

static int		get_str_len(long nbr)
{
	int i;

	i = 0;
	if (nbr <= 0)
	{
		i++;
		nbr *= -1;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	long	nbr;
	char	*result;
	int		nega;
	int		i;
	int		j;

	nbr = n;
	j = -1;
	i = get_str_len(nbr);
	if (!(result = malloc(sizeof(char) * (i + 1))))
		return (0);
	if (nbr < 0)
	{
		nbr *= -1;
		result[0] = '-';
		j += 1;
	}
	result[i] = '\0';
	nega = i--;
	while (++j < nega && result[i] != '-')
	{
		result[i--] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (result);
}