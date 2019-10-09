/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:19:01 by mwane             #+#    #+#             */
/*   Updated: 2019/10/09 17:50:11 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if ((char)c == *str)
			return ((char*)str);
		str++;
	}
	if (c == '\0')
		return ((char*)str);
	return (NULL);
}

/*
	int main(void)
{
	printf("my func : %s\n",ft_strchr("there is so \0ma\0ny \0 \\0",'\0'));
	printf("their func : %s\n",strchr("there is so \0ma\0ny \0 \\0",'\0'));
}*/