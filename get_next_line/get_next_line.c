/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 11:11:15 by mwane             #+#    #+#             */
/*   Updated: 2019/10/28 17:41:01 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char     *reallocbuff(char *buffer, char *str, int size, int i)
{
	int j;
	int x;
	//static int k = 1;
	char *tmp;

	j = 0;
	x = 0;
	tmp = malloc(sizeof(char) * ((size * i) + sizeof(str) + 1));
	if (str)
	{
		while (str[j])
		{
			tmp[j] = str[j];
			j++;
		}
		free(str);
	}
	while (buffer[x] && buffer[x] != '\n')
		tmp[j++] = buffer[x++];
	tmp[j] = '\0';
	str = tmp;
	return (str);
}

char	*setup_save(char *buff)
{
	int i;
	char *newsave;

	i = 0;
	newsave = malloc(sizeof(BUFFER_SIZE));
	while (*buff && *buff != '\n')
		buff++;
	if (*buff)
	{
		buff++;
		while (*buff && *buff != '\n')
			newsave[i++] = *buff++;
		newsave[i] = '\0';
	}
	return(newsave);
}

int		scan_buffer(char *buff)
{
	int i;
	
	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
			return (1);
		else
			i++;
	}
	return (0);
}

int get_next_line(int fd, char **line)
{
	char *buffer;
	char static *save;
	int count;
	int i = 1;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!save)
		save = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while ((count = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[count] = '\0';
		if (!scan_buffer(buffer))
		{
			save = reallocbuff(buffer, save, BUFFER_SIZE, i);
			i++;
		}
		else
		{
			*line = reallocbuff(buffer, save, BUFFER_SIZE, i);
			save = setup_save(buffer);
			return count;
		}
	}
	return 0;
}

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
	int fd = 0;
	int i = 1;
	char	*line;
	
	line = NULL;
	fd = open("test.txt", O_RDONLY);

	get_next_line(fd, &line);
	printf("ligne %d = %s\n\n",i++,line);
	get_next_line(fd, &line);
	printf("ligne %d = %s\n\n",i++,line);
	get_next_line(fd, &line);
	printf("ligne %d = %s\n\n",i++,line);
	get_next_line(fd, &line);
	printf("ligne %d = %s\n\n",i++,line);
	get_next_line(fd, &line);
	printf("ligne %d = %s\n\n",i++,line);
	get_next_line(fd, &line);
	printf("ligne %d = %s\n\n",i++,line);
	get_next_line(fd, &line);
	printf("ligne %d = %s\n\n",i++,line);
	get_next_line(fd, &line);
	printf("ligne %d = %s\n\n",i++,line);
	//while(1){}
	return 0;
}