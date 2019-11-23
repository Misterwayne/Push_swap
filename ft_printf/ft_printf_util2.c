/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 18:38:10 by mwane             #+#    #+#             */
/*   Updated: 2019/11/23 17:58:25 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

void	do_int(char *str, va_list argv, pflags *lflags)
{
	char *res;
	int c;

	c = (int)va_arg(argv, int);
	res = NULL;

	lflags->form = *str;
	if (c == 0)
		res = ft_strdup("0");
	else
		res = ft_putnbr_base((int)va_arg(argv, int), "0123456789");
	do_int_width(res, lflags, &ft_putstr_int);
	free(res);
}

int		check_params(const char *str, va_list argv, pflags *lflags)
{
	unsigned long	c;

	c = 0;
	if (*str == 'd' || *str == 'i')
		do_int((char *)str, argv, lflags);
	else if (*str == 'c')
	{
		ft_putchar((char)va_arg(argv, int), lflags);
		return (1);
	}
	else if (*str == 's')
	{
		lflags->form = *str;
		do_int_width(va_arg(argv, char *), lflags, &ft_putstrl);
		return (1);
	}
	check_params2((char *)str, argv, lflags);
	return (1);
}

int		check_params2(const char *str, va_list argv, pflags *lflags)
{
	unsigned long	c;
	char			*res;

	c = 0;
	res = NULL;
	if (*str == 'u')
	{
		lflags->form = *str;
		c = (unsigned int)(4294967295 + 1 + va_arg(argv, unsigned int));
		do_int_width(ft_putnbr_base(c, "0123456789"), lflags, &ft_putstr_int);
	}
	else if (*str == '%')
	{
		ft_putchar('%', lflags);
		return (1);
	}
	else if (*str == 'p')
	{
		c = (unsigned long)va_arg(argv, unsigned long);
		res = ft_strjoin("0x", ft_putnbr_base(c, "0123456789abcdef"));
		do_int_width(res, lflags, &ft_putstr_int);
		free(res);
	}
	check_params3(str, argv, lflags);
	return (1);
}

int		check_params3(const char *str, va_list argv, pflags *lflags)
{
	unsigned long	c;
	char			*res;

	c = 0;
	res = NULL;
	if (*str == 'x')
	{
		lflags->form = *str;
		c = (unsigned int)va_arg(argv, int);
		res = ft_putnbr_base(c, "0123456789abcdef");
		do_int_width(res, lflags, &ft_putstr_int);
	}
	else if (*str == 'X')
	{
		lflags->form = *str;
		c = (unsigned int)va_arg(argv, int);
		res = ft_putnbr_base(c, "0123456789ABCDEF");
		do_int_width(res, lflags, &ft_putstr_int);
	}
	free(res);
	return (0);
}
