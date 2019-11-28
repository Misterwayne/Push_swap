/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 13:05:22 by mwane             #+#    #+#             */
/*   Updated: 2019/11/28 18:59:39 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		scan_dot(pflags *lflags, char *str)
{
	int p;
	int len1;
	int i;

	i = 0;
	p = 0;
	lflags->dot = 0;
	len1 = ft_strlen((char *)str);
	while (str[i] < 58)
	{
		if (str[i++] == '.')
			lflags->dot = 1;
	}
	while (*str == '0')
	{
		if (str[0] == '0' && str[1] != '0' && lflags->dot == 0)
		{
			p = 1;
			lflags->detail += 1;
		}
		str++;
	}
	return (p);
}

int		check_sign(pflags *lflags, char *str, int *nega)
{
	int i;

	i = 0;
	if (str[i] == '-' || str[i] == '+' || str[i] == ' ')
	{
		if (str[i] == '-')
			*nega = -1;
		if (str[i] == '+')
			lflags->plus = 1;
		if (str[i] == ' ')
			ft_putchar(' ', lflags);
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

void	get_preci(char *str, pflags *lflags, va_list argv, int p)
{
	int i;

	i = 0;
	if (str[i] == '*')
		lflags->preci = (int)va_arg(argv, int);
	else if ((str[i] == '0' || (str[i] + 1 < '0'
		|| str[i] + 1 > '9')) && p == 0)
		lflags->preci = -2;
	else
		lflags->preci = ft_atoi((char *)str);
	if (lflags->preci == 0)
		lflags->preci = -1;
}

int		check_pre_width(const char *str, pflags *lflags, va_list argv)
{
	int p;
	int nega;
	int len1;

	lflags->dot = 0;
	nega = 1;
	len1 = ft_strlen((char *)str);
	p = scan_dot(lflags, (char *)str);
	str += check_sign(lflags, (char *)str, &nega);
	if (*str == '*')
		lflags->width = (int)va_arg(argv, int);
	else if (p == 0)
		lflags->width = ft_atoi((char *)str) * nega;
	if (nega < 0 && lflags->width > 0)
		lflags->width *= nega;
	while ((*str >= '0' && *str <= '9' && p == 0) || *str == '-' || *str == '*')
		str++;
	if (*str == '.' || p == 1)
	{
		str += skipskip((char *)str);
		get_preci((char *)str, lflags, argv, p);
		str += skipskip2((char *)str);
	}
	check_params(str, argv, lflags);
	return (len1 - ft_strlen((char *)str));
}

void	reset_struct(pflags *lflags)
{
	lflags->preci = -1;
	lflags->width = 0;
	lflags->plus = 0;
	lflags->form = 0;
	lflags->dot = 0;
}

void	init_struct(pflags *lflags)
{
	lflags->preci = -1;
	lflags->width = 0;
	lflags->plus = 0;
	lflags->form = 0;
	lflags->dot = 0;
	lflags->total_len = 0;
	lflags->detail = 0;
	lflags->len = 0;
	lflags->end = 0;
}

int		ft_printf(const char *str, ...)
{
	va_list	argv_list;
	pflags	lflags;

	init_struct(&lflags);
	va_start(argv_list, str);
	while (*str)
	{
		if (*str != '%')
			ft_putchar(*str, &lflags);
		else
		{
			str++;
			str += check_pre_width(str, &lflags, argv_list);
		}
		reset_struct(&lflags);
		str++;
		if (lflags.end == 1)
			break ;
	}
	return (lflags.total_len);
}
