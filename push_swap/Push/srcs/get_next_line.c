/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 11:11:15 by mwane             #+#    #+#             */
/*   Updated: 2021/06/11 13:05:06 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/get_next_line.h"

int	scan_save(char *save)
{
	if (save)
		return (1);
	free(save);
	return (0);
}

int	fed(char *save, char *buffer, char **line)
{
	if (scan_buffer(save))
	{
		*line = giveline(save);
		save = setup_save(save);
		free(buffer);
		return (1);
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char		*buffer;
	char static	*save;
	int			count;

	buffer = malloc(sizeof(char) * (4 + 1));
	if (!(buffer) || fd == -1)
		return (-1);
	count = 1;
	while (count > 0)
	{
		count = read(fd, buffer, 4);
		buffer[count] = '\0';
		save = reallocbuff(buffer, save);
		if (fed(save, buffer, line))
			return (1);
	}
	free(buffer);
	if (count == -1)
		return (-1);
	*line = giveline(save);
	save = setup_save(save);
	return (scan_save(save));
}
