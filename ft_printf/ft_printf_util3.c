/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 16:26:51 by truepath          #+#    #+#             */
/*   Updated: 2019/11/25 18:15:16 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"
#include <stdio.h>

void	ft_putstr_int(char *str, pflags *lflags)
{
	int i;
	int neg;

	i = 0;
	neg = 0;
	if (!str)
		return ;
	if (*str == '-')
	{
		ft_putchar('-', lflags);
		str++;
		if (lflags->detail == 1)
			neg = 1;
	}
	while (lflags->preci > ft_strlen(str) + neg)
	{
		ft_putchar('0', lflags);
		lflags->preci--;
	}
	while (str[i] && lflags->preci != 0)
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
	while (0 < width--)
		ft_putchar(' ', lflags);
}

void	check_form(int *i, pflags *lflags, char *str)
{
	if ((str[0] == '-' && lflags->preci > 0))
		*i = -1;
	else if (lflags->form == 's')
		*i = 2;
	else if (lflags->form == 'x' || lflags->form == 'X')
		*i = 0;
	return ;
}

char	*do_int_width(char *str, pflags *lflags, void (*ft_put)(char*, pflags*))
{
	int		i;
	int		temp;
	int		temp2;

	i = 0;
	check_param(lflags, str, &temp, &temp2);
	check_form(&i, lflags, str);
	if (lflags->preci <= 0 && ft_strlen(str) > 0 && i == 2 && lflags->width > 0)
		print_space(temp, lflags);
	if (i == 2 && lflags->width > 0 && lflags->preci > 0)
		print_space(temp - lflags->preci, lflags);
	if (lflags->width > ft_strlen(str) && i != 2)
		print_space(temp - temp2 + i, lflags);
	ft_put(str, lflags);
	if (lflags->width < 0 && lflags->preci > 0 && i == 2)
		print_space(temp - lflags->preci, lflags);
	if (lflags->preci <= 0 && ft_strlen(str) > 0 && i == 2 && lflags->width < 0)
		print_space(temp, lflags);
	if (lflags->width < 0 && i != 2)
		print_space(temp - temp2 + i, lflags);
	return (NULL);
}
