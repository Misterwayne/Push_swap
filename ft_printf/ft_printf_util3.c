/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truepath <truepath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 16:26:51 by truepath          #+#    #+#             */
/*   Updated: 2019/11/29 19:16:28 by truepath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"
#include <stdio.h>

void	put_zeros(pflags *lflags, int len, int neg)
{
	while (lflags->preci > len + neg)
	{
		ft_putchar('0', lflags);
		lflags->preci--;
	}
}

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
	put_zeros(lflags, ft_strlen(str), neg);
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
	if (lflags->plus == 1)
		width--;
	while (0 < width--)
		ft_putchar(' ', lflags);
}

void	check_form(int *i, pflags *lflags, char *str)
{
	if (str && (str[0] == '-' && lflags->preci > 0))
		*i = -1;
	else if (lflags->form == 's')
		*i = 2;
	else if (lflags->form == 'x' || lflags->form == 'X')
		*i = 0;
	return ;
}

