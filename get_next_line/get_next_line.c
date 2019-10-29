/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truepath <truepath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 11:11:15 by mwane             #+#    #+#             */
/*   Updated: 2019/10/29 12:37:16 by truepath         ###   ########.fr       */
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
		while (str[x] != '\n' && str[x])
			x++;
		while (str[x])
		{
			x++;
			tmp[j] = str[x];
			j++;
		}
		free(str);
	}
	x = 0;
	while (buffer[x])
		tmp[j++] = buffer[x++];
	tmp[j] = '\0';
	str = tmp;
	return (tmp);
}

char *giveline(char* str)
{
	int i;
	char *line;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	line = malloc(sizeof(char) * (i +1));
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		line[i] = str[i];
		i++;
	}
	printf("%d\n",i);
	line[i] = '\0';
	return (line);
}

char	*setup_save(char *buff)
{
	int i;
	int j;
	char *newsave;

	i = 0;
	j = 0;
	newsave = malloc(sizeof(BUFFER_SIZE + 1));
	while (buff[i] != '\n' && buff[i])
		i++;
	printf("i1 = %d\n",i);
	if (buff[i++])
	{
		while (buff[i])
			newsave[j++] = buff[i++];
		printf("i2 = %d\n",i);
		newsave[j] = '\0';
	}
	printf("newsave = %s\n",newsave);
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
		printf("save2 = %s\n",save);
		buffer[count] = '\0';
		save = reallocbuff(buffer, save, BUFFER_SIZE, i);
		//printf("save = %s\n",save);
		if (!scan_buffer(buffer))
		{
			save = setup_save(buffer);
			i++;
		}
		else
		{
			*line = giveline(save);
			save = setup_save(save);
			return count;
		}
	}
	*line = giveline(save);
	if (buffer)
		save = reallocbuff(buffer, save, BUFFER_SIZE, i);
	else
		save = reallocbuff(save, save, BUFFER_SIZE, i);
	printf("save1 = %s\n",save);
	*line = giveline(save);
	save = setup_save(save);
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