/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 18:38:10 by mwane             #+#    #+#             */
/*   Updated: 2019/11/22 20:37:17 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

int	check_params(const char *str, va_list argv, pflags *lflags)
{
	unsigned long c;
	char *res;

	c = 0;
	res = NULL;
	if (*str == 'd')
	{
		c = (int)va_arg(argv, int);
		res = ft_putnbr_base(c, "0123456789");
		do_int_width(res, lflags, &ft_putstr_int);
	}
	else if (*str == 'c')
	{
		c = (char)va_arg(argv, int);
		ft_putchar(c, lflags);
		return (1);
	}
	else if (*str == 's')
	{
		do_int_width(va_arg(argv, char *), lflags, &ft_putstr);
		return (1);
	}
	else if (*str == 'u')
	{
		c = (unsigned int)(4294967295 + 1 + va_arg(argv, unsigned int));
		res = ft_putnbr_base(c, "0123456789");
		do_int_width(res, lflags, &ft_putstr_int);
	}
	else if (*str == '%')
	{
		write(1, "%", 1);
		lflags->total_len += 1;
		return (1);
	}
	// else if (*str == 'p')
	// {
	// 	c = (unsigned long)va_arg(argv, unsigned long);
	// 	ft_putchar('0', lflags);
	// 	ft_putchar('x', lflags);
	// 	res = ft_putnbr_base(c, "0123456789abcdef", lflags);
	// }
	// else if (*str == 'x')
	// {
	// 	c = (int)va_arg(argv, int);
	// 	res = ft_putnbr_base(c, "0123456789abcdef", lflags);
	// }
	// else if (*str == 'X')
	// {
	// 	c = (int)va_arg(argv, int);
	// 	res = ft_putnbr_base(c, "0123456789ABCDEF", lflags);
	// }
	free(res);
	return (0);
}
