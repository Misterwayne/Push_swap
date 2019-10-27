/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 11:11:15 by mwane             #+#    #+#             */
/*   Updated: 2019/10/27 16:25:21 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char     *reallocbuff(char *buffer, char *str, int size, int i, int z)
{
	int j;
	int x;
	//static int k = 1;
	static char *tmp;

	j = 0;
	x = 0;
	tmp = malloc(sizeof(char) * ((size * i) + 1));
	while (str[z])
		tmp[j++] = str[z++];
	while (buffer[x] && buffer[x] != '\n')
		tmp[j++] = buffer[x++];
	tmp[j] = '\0';
	if (str)
		free(str);
	str = tmp;
	return (str);
}

int		scan_buffer(char *buff,char *overbuff)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
		{
			buff[i] = '\0';
			if (buff[i + 1])
			{
				while(buff[++i])
					overbuff[j++] = buff[i];
				overbuff[j] = '\0';
			}
			printf("over = %s\n",overbuff);
			return (1);
		}
		else
			i++;
	}
	return (0);
}

int filloverbuff(char *overbuff,char *line)
{
	int i;

	i = 0;
	while (overbuff[i])
		*line++ = overbuff[i++];
	return i;
}

int get_next_line(int fd, char **line)
{
	char *buffer;
	char *overbuff;
	int count;
	int	x = 0;
	int i = 1;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	*line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	overbuff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while ((count = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[count] = '\0';
		if (!scan_buffer(buffer,overbuff))
		{
			*line = reallocbuff(buffer, *line, BUFFER_SIZE, i, x);
			i++;
		}
		else
		{
			//x += filloverbuff(overbuff, *line);
			*line = reallocbuff(buffer, *line, BUFFER_SIZE, i, x);
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
	char	*line;
	
	line = NULL;
	fd = open("test.txt", O_RDONLY);

	get_next_line(fd, &line);
	printf("%s\n\n",line);
	get_next_line(fd, &line);
	//{
		printf("%s\n\n",line);
	//}
}