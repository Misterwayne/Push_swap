/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 16:26:51 by truepath          #+#    #+#             */
/*   Updated: 2019/11/27 18:36:34 by mwane            ###   ########.fr       */
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
	if (*str == '-' || lflags->plus == 1)
	{
		if (lflags->plus == 1 && *str != '-')
			ft_putchar('+', lflags);
		else
		{
			ft_putchar('-', lflags);
			str++;
		}
		if (lflags->detail == 1)
			neg = 1;
	}
	if (lflags->dot == 1 && lflags->form == '%')
		lflags->preci = -1;
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
	if (lflags->plus == 1 || lflags->form == '%')
		width--;
	// if (lflags->preci > 0 && lflags->form == 's' && lflags->width < 0 && lflags->dot == 1)
	// 	width++; 
	while (0 < width--)
		ft_putchar(' ', lflags);
}

void	check_form(int *i, pflags *lflags, char *str)
{
	if (str && (str[0] == '-' && lflags->preci > 0))
		*i = -1;
	else if (lflags->form == 's' || lflags->form == '%')
		*i = 2;
	else if (lflags->form == 'x' || lflags->form == 'X')
		*i = 0;
	return ;
}

void	do_str_width(char *str, pflags *lflags)
{
	int temp;
	int temp2;
	int len;

	temp = lflags->width;
	temp2 = lflags->preci;
	len = ft_strlen(str);
	if (temp < 0)
		temp *= -1;
	if (temp2 > len)
		temp2 = len;
	// printf("temp = %d\n",temp);
	// printf("temp2 = %d\n",temp2);
	// printf("len = %d\n",len);
	if (temp > ft_strlen(str))
	{
		if (lflags->preci > 0)
			print_space(temp - temp2, lflags);
		else if (lflags->preci <= 0)
			print_space(temp - len, lflags);
	}
}

char	*do_int_width(char *str, pflags *lflags, void (*ft_put)(char*, pflags*))
{
	int		i;
	int		temp;
	int		temp2;

	i = 0;
	check_param(lflags, str, &temp, &temp2);
	check_form(&i, lflags, str);
	if (lflags->preci <= 0 && i == 2 && lflags->width > 0)
		print_space(temp - temp2, lflags);
	else if (i == 2 && lflags->width > 0 && lflags->preci > 0)
		print_space(temp - lflags->preci, lflags);
	else if (lflags->width > ft_strlen(str) && i != 2)
		print_space(temp - temp2 + i, lflags);
	ft_put(str, lflags);
	if ((lflags->form == '%' || lflags->form == 's') && lflags->width < 0)
		do_str_width(str, lflags);
	else if (lflags->width < 0 && i != 2)
	{
		if ((temp - temp2 + i) == 0 && lflags->preci == 0)
			print_space(temp, lflags);
		else
			print_space(temp - temp2 + i, lflags);
	}
	return (NULL);
}
