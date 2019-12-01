/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util6.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 12:01:06 by mwane             #+#    #+#             */
/*   Updated: 2019/12/01 13:49:51 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		scan_dot(t_flags *lflags, char *str)
{
	int p;
	int len1;
	int i;

	i = 0;
	p = 0;
	lflags->dot = 0;
	lflags->zero = 0;
	len1 = ft_strlen((char *)str);
	while (str[i] < 58)
	{
		if (str[i++] == '.')
			lflags->dot = 1;
	}
	while (*str == '0')
	{
		lflags->zero = 1;
		if (str[0] == '0' && str[1] != '0' && lflags->dot == 0)
		{
			p = 1;
			lflags->detail = 1;
		}
		str++;
	}
	return (p);
}

int		check_sign(t_flags *lflags, char *str, int *nega)
{
	int i;

	i = 0;
	if (str[i] == '-' || str[i] == '+' || str[i] == ' ')
	{
		if (str[i] == '-')
			*nega = -1;
		if (str[i] == '+')
			lflags->plus = 1;
		while (str[i] == '-' || str[i] == '+' || str[i] == ' ')
			i++;
	}
	return (i);
}

int		skipskip(char *str)
{
	int i;

	i = 0;
	while ((str[i] == '0' || str[i] == '.'))
		i++;
	return (i);
}

int		skipskip2(char *str)
{
	int i;

	i = 0;
	while ((str[i] >= '0' && str[i] <= '9') || str[i] == '-' || str[i] == '*')
		i++;
	return (i);
}
