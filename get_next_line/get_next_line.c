/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 11:11:15 by mwane             #+#    #+#             */
/*   Updated: 2019/10/30 21:11:59 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_bzero(void *s, size_t size)
{
	unsigned char *str;

	str = (unsigned char*)s;
	while (size-- > 0)
		*(str++) = 0;
}


int ft_strlen(char *str)
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

char     *reallocbuff(char *buffer, char *str)
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
	// printf("buffer = |%s|\n",buffer);
	// printf("str = %s\n",str);
	if (!(newstr = malloc(sizeof(char) * (lenstr + lenbuffer + 1))))
		return (NULL);
	while (++i < lenstr)
	{
		newstr[i] = str[i];
	}
	while (i < lenstr + lenbuffer && buffer[j])
		newstr[i++] = buffer[j++];
	newstr[i] = '\0';
	free(str);
	free(buffer);
	// printf("newstr = |%s|\n",newstr);
	return (newstr);
}

char *giveline(char* str)
{
	int i;
	char *line;
	int len;

	i = 0;
	if (!str)
	{
		//printf("\nstr est null\n");
		return NULL;
	}
	//printf("str de l = %d\n",ft_strlen(str));
	//printf("str = %s\n",str);
	while (i < ft_strlen(str) && str[i] != '\n')
		i++;
	len = i;
	line = malloc(sizeof(char) * (i + 1));
	i = 0;
	// printf("len = %d\n",len);
	while (str[i] && str[i]!= '\n' && len > i)
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	// printf("len de l = %d\n",ft_strlen(line));
	//  printf("l = %s\n",line);
	return (line);
}

char	*setup_save(char *save)
{
	int i;
	int j;
	char *newsave;

	i = 0;
	j = 0;
	// printf("oldsave = |%s|\n",save);
	if (!save)
	{
		//printf("\nstr est null\n");
		return NULL;
	}
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i])
	{
		newsave = malloc(sizeof(char) * (ft_strlen(save) - i) + 1);
		i++;
		while (save[i])
			newsave[j++] = save[i++];
		newsave[j] = '\0';
	}
	else
	{	
		return(NULL);
	}
	free(save);
	// printf("newsave = |%s|\n",newsave);
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
		i++;
	}
	return (0);
}

int		scan_save(char *save)
{
	if (!save)
	{	
		// printf(" \nstr est null\n");
		return (0);
	}
	return (1);
}

int get_next_line(int fd, char **line)
{
	char *buffer;
	char static *save;
	int count;
	int i;

	i = 1;
	// if (*line)
	// 	free(*line);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	// printf("lastsave = %s\n",save);
	// ft_bzero(buffer, BUFFER_SIZE);
	while ((count = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[count] = '\0';
		save = reallocbuff(buffer, save);
		if (scan_buffer(save))
		{
			*line = giveline(save);
			// printf("lastsave = %s\n",save);
			save = setup_save(save);
			return 1;
		}
	}
	*line = giveline(save);
	save = setup_save(save);
	// printf("lastsave = %s\n",save);
	if (scan_save(save))
		return (1);
	else
		free(save);
	save = NULL;
	return (0);
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
	int res = 1;
	
	line = NULL;
	fd = open("test.txt", O_RDONLY);


	while (res > 0)
	{
		res = get_next_line(fd, &line);
		printf("ligne %d |%s|\n",i++ ,line);
		free(line);
	}
	close(fd);
	// printf("count = %d ligne %d = %s\n\n",get_next_line(fd, &line),i++,line);
	// printf("count = %d ligne %d = %s\n\n",get_next_line(fd, &line),i++,line);
	// printf("count = %d ligne %d = %s\n\n",get_next_line(fd, &line),i++,line);
	// printf("count = %d ligne %d = %s\n\n",get_next_line(fd, &line),i++,line);
	// printf("count = %d ligne %d = %s\n\n",get_next_line(fd, &line),i++,line);
	// printf("count = %d ligne %d = %s\n\n",get_next_line(fd, &line),i++,line);
	// printf("count = %d ligne %d = %s\n\n",get_next_line(fd, &line),i++,line);
	// printf("count = %d ligne %d = %s\n\n",get_next_line(fd, &line),i++,line);
	return 0;
}