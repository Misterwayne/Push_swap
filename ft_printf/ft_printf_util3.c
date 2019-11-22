/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 16:26:51 by truepath          #+#    #+#             */
/*   Updated: 2019/11/22 21:09:31 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"
#include <stdio.h>

void		ft_putstr_int(char *str, pflags *lflags)
{
	int i;

	i = 0;
	if (!str)
		return ;
	if (*str == '-')
	{
		ft_putchar('-', lflags);
		str++;
	}
	if (lflags->preci <= 0)
		lflags->preci = ft_strlen(str);
	if (lflags->preci > ft_strlen(str))
	{
		while (lflags->preci != ft_strlen(str))
		{
			ft_putchar('0', lflags);
			lflags->preci--;
		}
	}
	while (str[i])
		ft_putchar(str[i++], lflags);
}

void	check_param(pflags *lflags, char *str, int *temp, int *temp2)
{
	int		len;

	*temp = lflags->width;
	*temp2 = lflags->preci;
	len = ft_strlen(str);
	if (*temp < 0)
		*temp *= -1;
	if (*temp < len)
		*temp = len;
	if (*temp2 < len)
		*temp2 = len;
}

void	print_space(int width, pflags *lflags)
{
	printf("ok");
	while (0 < width--)
		ft_putchar(' ', lflags);
}

char	*do_int_width(char *str, pflags *lflags, void (*ft_put)(char*, pflags*))
{
	int		len;
	int		i;
	int		temp;
	int		temp2;

	check_param(lflags, str, &temp, &temp2);
	i = 0;
	if ((str[0] == '-' && lflags->preci > 0))
		i = -1;
	else if (str[0] != '-' && *str && (str[i] > '9' || str[i] < '0'))
		i = 2;
	len = ft_strlen(str);
	if (lflags->preci == 0 && len > 0 && i == 2 && lflags->width > 0)
		print_space(temp, lflags);
	if (lflags->width > temp2 && lflags->preci > 0)
		print_space(temp - temp2 + i, lflags);
	// while (lflags->width > len && 0 < temp - temp2 + i)
	// {
	// 	ft_putchar(' ', lflags);
	// 	temp--;
	// }
	printf("|i = %d|",i);
	ft_put(str, lflags);
	if (lflags->preci == 0 && len > 0 && i == 2 && lflags->width < 0)
		print_space(temp, lflags);
	if (lflags->width < 0 && lflags->preci > 0)
		print_space(temp - temp2 + 1, lflags);
	// while (lflags->width < 0 && 0 < temp - temp2 + i)
	// {
	// 	ft_putchar(' ', lflags);
	// 	temp--;
	// }
	return (NULL);
}

