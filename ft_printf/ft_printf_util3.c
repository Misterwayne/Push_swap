/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truepath <truepath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 16:26:51 by truepath          #+#    #+#             */
/*   Updated: 2019/11/21 00:44:51 by truepath         ###   ########.fr       */
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
    int     i;
    char    *res;
    int     temp;
    
    temp = width;
    if (width < 0)
        temp *= -1;
    if (width < ft_strlen(str))
        temp = ft_strlen(str);
	if (pre <= 0)
		pre = temp;
	printf("pre = %d",pre);	
    res = malloc(sizeof(char) * (temp + 1));
    i = 0;
    if  (width > ft_strlen(str))
    {
		write(1, "1", 1);
        while (i < temp - pre)
            res[i++] = ' ';
    }
    while (pre > 0)
    {
		write(1, ".", 1);
        res[i++] = *str++;
        pre--;
    }
    if  (width < 0)
    {
		write(1, "3", 1);
        while (i < temp + 1)
            res[i++] = ' ';
    }
    res[i] = '\0';
    return(res);
}
/*
#include <stdio.h>

int main()
{
    printf("%20.6s.\n","Bonfour");
    printf("%s",do_width("Bonjour", 20,6));
}*/