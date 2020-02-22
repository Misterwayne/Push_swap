/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 11:11:15 by mwane             #+#    #+#             */
/*   Updated: 2020/02/21 14:19:35 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		scan_save(char *save)
{
	if (save)
		return (1);
	free(save);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	char		*buffer;
	char static	*save;
	int			count;

	if (!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))) || fd == -1)
		return (-1);
	while ((count = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[count] = '\0';
		save = reallocbuff(buffer, save);
		if (scan_buffer(save))
		{
			*line = giveline(save);
			save = setup_save(save);
			free(buffer);
			return (1);
		}
	}
	free(buffer);
	if (count == -1)
		return (-1);
	*line = giveline(save);
	save = setup_save(save);
	return ((scan_save(save)) ? 1 : 0);
}
