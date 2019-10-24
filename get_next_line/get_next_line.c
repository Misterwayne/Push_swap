/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truepath <truepath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 11:11:15 by mwane             #+#    #+#             */
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
}