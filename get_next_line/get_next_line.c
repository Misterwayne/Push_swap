/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 11:11:15 by mwane             #+#    #+#             */
/*   Updated: 2019/10/29 19:27:09 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char     *reallocbuff(char *buffer, char *str, int size, int i)
{
	size_t j;
	size_t x;
	//static int k = 1;
	char *tmp;

	j = 0;
	tmp = malloc(sizeof(char) * ((size * i) + sizeof(str) + 1));
	if (str)
	{
		while (*str && j < ((size * i) + sizeof(str) + 1))
		{
			//printf("j = %zu\n",j);
			tmp[j++] = *str++;
		}
		free(str - j);
	}
	x = 0;
	while (buffer[x])
		tmp[j++] = buffer[x++];
	tmp[j] = '\0';
	printf("tmp = %s\n",tmp);
	str = tmp;
	return (str);
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
	while (buff[i] != '\n' && buff[i])
		i++;
	newsave = malloc(sizeof(BUFFER_SIZE - i + 1));
	if (buff[i++])
	{
		while (buff[i])
			newsave[j++] = buff[i++];
		newsave[j] = '\0';
	}
	printf("newsave = %s\n",newsave);
	printf("len newsave = %d\n",j);
	return(newsave);
}

int		scan_buffer(char *buff)
{
	int i;
	
	i = -1;
	while (buff[++i])
	{
		printf("%d\n",i);
		if (buff[i] == '\n')
			return (1);
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
	printf("save1 = %s\n",save);
	while ((count = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[count] = '\0';
		//printf("save = %s\n",save);
		save = reallocbuff(buffer, save, BUFFER_SIZE, i);
		printf("save2 = %s\n",save);
		if (!scan_buffer(buffer))
		{
			printf("save3 = %s\n",save);
			i++;
		}
		else
		{
			printf("save2 = %s\n",save);
			*line = giveline(save);
			save = setup_save(buffer);
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