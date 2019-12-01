/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 13:05:22 by mwane             #+#    #+#             */
/*   Updated: 2019/12/01 13:51:07 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_preci(char *str, t_flags *lflags, va_list argv, int p)
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

int		check_pre_width(const char *str, t_flags *lflags, va_list argv)
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

void	reset_struct(t_flags *lflags)
{
	lflags->preci = -1;
	lflags->width = 0;
	lflags->plus = 0;
	lflags->form = 0;
	lflags->dot = 0;
	lflags->detail = 0;
}

void	init_struct(t_flags *lflags)
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
	t_flags	lflags;

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
