/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truepath <truepath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 11:11:15 by mwane             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/10/25 16:12:34 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


char     *reallocbuff(char *buffer, char *str, int size, int i)
{
	int j;
	char *tmp;

	j = -1;
	tmp = malloc(sizeof(char) * ((size * i) + 1));
	while (buffer[j++])
		str[size++ * (i - 1)] = buffer[j];
	if (str)
		free(str);
	str = tmp;
	return (str);
}

int		scan_buffer(char *buff)
{
	while (*buff)
	{
		if (*buff == '\n')
		{
			*buff = '\0';
			return (1);
		}
		else
			buff++;
	}
	return (0);
}

int get_next_line(int fd, char **line)
{
	char *buffer;
	static char *test;
	int count;
	int i = 1;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	line = malloc(sizeof(char *) * 1);
	*line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while ((count = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		if (!scan_buffer(buffer))
		{
			reallocbuff(buffer, test, BUFFER_SIZE, i);
			i++;
		}
		else
			return 0;
	}
	buffer[BUFFER_SIZE + 1] = '\0';
	while (i < BUFFER_SIZE)
	{
		(*line)[i] = buffer[i];
		i++;
	}
	buffer[BUFFER_SIZE + 1] = '\0';
	(*line)[BUFFER_SIZE + 1] = '\0';
	printf("%s",*line);
	return 0;
}

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
	int fd = 0; 
	
	fd = open("test.txt", O_RDONLY);

	get_next_line(fd,NULL);
=======
/*   Updated: 2019/10/24 15:22:37 by truepath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
# define BUFFER_SIZE 8


int get_next_line(int fd, char **line)
{
	int count;
	char *c;
	int buff;
	int i;
	static int fileindex;
	i = 0;
	count = 1;
	
	buff = BUFFER_SIZE;
	c = malloc(sizeof(char) * buff);
	count = read(fd, c, BUFFER_SIZE);
		*line[0] = c[0];
		*line[1] = '\0';
		printf("%c",*line[0]);
		(*line)++;
	//printf("%d\n",fileindex);
	return (count);
}

int main(void)
{
	int fd = 0;
	int static i;
	char **file;
	
	fd = open("test.txt",fd ,O_RDONLY);
	i = 2;
	while (i > 0)
	{
		i = get_next_line(fd, file);
		printf("%s\n", (*file)++);
	}
	return (0);
>>>>>>> aab00a6bab698b33c0472d1690062ef262fdc44a
}