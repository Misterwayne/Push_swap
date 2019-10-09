/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 13:53:57 by mwane             #+#    #+#             */
/*   Updated: 2019/10/09 17:18:05 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char	*ft_strrchr(const char *str, int c)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	
	if (i == 0)
		return (NULL);
	while (i >= 0)
	{
		if ((char)c == str[i])
			return ((char*)str + i);
		i--;
	}
	return (NULL);
}
/*
int main(void)
{
	printf("my func : %s\n",ft_strrchr("lol\0lol",'\0'));
	printf("their func : %s\n",strrchr("lol\0lol",'\0'));
}*/