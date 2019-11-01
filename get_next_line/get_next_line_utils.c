/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 17:05:27 by mwane             #+#    #+#             */
/*   Updated: 2019/11/01 16:56:41 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

int			ft_strlen(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

char		*reallocbuff(char *buffer, char *str)
{
	char	*newstr;
	int		lenstr;
	int		lenbuffer;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!str && !buffer)
		return (NULL);
	lenstr = ft_strlen(str);
	lenbuffer = ft_strlen(buffer);
	if (!(newstr = malloc(sizeof(char) * (lenstr + lenbuffer + 1))))
		return (NULL);
	while (++i < lenstr)
		newstr[i] = str[i];
	while (i < lenstr + lenbuffer && buffer[j])
		newstr[i++] = buffer[j++];
	newstr[i] = '\0';
	if (str)
		free(str);
	return (newstr);
}

char		*giveline(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str)
	{
		line = malloc(sizeof(char) * 1);
		*line = '\0';
		return (line);
	}
	while (i < ft_strlen(str) && str[i] != '\n')
		i++;
	if (!(line = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char		*setup_save(char *save)
{
	int		i;
	int		j;
	char	*newsave;

	i = 0;
	j = 0;
	if (!save)
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i])
	{
		if (!(newsave = malloc(sizeof(char) * (ft_strlen(save) - i) + 1)))
			return (NULL);
		i++;
		while (save[i])
			newsave[j++] = save[i++];
		newsave[j] = '\0';
		free(save);
		return (newsave);
	}
	else
		free(save);
	return (NULL);
}

int			scan_buffer(char *buff)
{
	int i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
