/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 16:26:51 by truepath          #+#    #+#             */
/*   Updated: 2019/11/21 17:21:12 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"
#include <stdio.h>

void    do_precision(char *str, int pre)
{
	while (*str && pre < 0)
	{
		write(1, str, 1);
		str++;
		pre--;
	}
}

char *do_width(char *str, int width, int pre)
{
	int 	len;
	int     temp;
	int		i;
	int		temp2;

	temp = width;
	temp2 = pre;
	i = 0;
	len = ft_strlen(str);
	//printf("%d\n",len);
	if (width < 0)
		temp *= -1;
	if (temp < len)
		temp = len;
	if (pre <= 0)
		temp2 = len;
	if (width > len)
	{
		while (temp - temp2 > 0)
		{
			write(1, " ", 1);
			temp--;
		}
	}
	while (temp2 > len)
	{
		write(1, "0", 1);
		temp2--;
		i++;
	}
	while (temp2 > 0 && *str)
	{
		write(1, str, 1);
		str++;
		temp2--;
	}
	if (width < 0)
	{
		while (0 < temp - (len + i))
		{
			write(1, " ", 1);
			temp--;
		}
	}
	return (NULL);
}
/*
#include <stdio.h>

int main()
{
	printf("%20.6s.\n","Bonfour");
	printf("%s",do_width("Bonjour", 20,6));
}*/