/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 18:38:10 by mwane             #+#    #+#             */
/*   Updated: 2019/11/27 19:10:43 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

void	do_int(char *str, va_list argv, pflags *lflags)
{
	char	*res;
	int		c;

	c = (int)va_arg(argv, int);
	res = NULL;

	lflags->form = *str;
	if (c == 0)
	{
		res = ft_strdup("0");
		if (lflags->preci == -2)
			lflags->preci = 0;
	}
	else
		res = ft_putnbr_base(c, "0123456789");
	do_int_width(res, lflags, &ft_putstr_int);
	free(res);
}

int		check_params(const char *str, va_list argv, pflags *lflags)
{
	unsigned long	c;
	char *			res;

	c = 0;
	res = NULL;
	if (*str == 'd' || *str == 'i' || *str == 'D')
	{
		do_int((char *)str, argv, lflags);
		return (1);
	}
	else if (*str == 'c')
	{
		c = (char)va_arg(argv, int);
		if (!(res = malloc(sizeof(char) * 2)))
			return (0);
		if (c == 0)
		{
			lflags->total_len += 1;
			// lflags->end = 1;
		}
		res[0] = c;
		res[1] = '\0';
		do_int_width(res, lflags, &ft_putstr_int);
		return (1);
	}
	else if (*str == 's')
	{
		lflags->form = *str;
		res = va_arg(argv, char *);
		if (res)
		{
			do_int_width(res, lflags, &ft_putstrl);
		}
		else
		{
			if (lflags->preci > 0 || lflags->dot == 0)
				res = ft_strdup("(null)");
			else
				res = ft_strdup("");
			do_int_width(res, lflags, ft_putstrl);
		}
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
	if (*str == 'u' || *str == 'U')
	{
		lflags->form = *str;
		c = (unsigned int)(4294967295 + 1 + va_arg(argv, unsigned int));
		if (c == 0 && lflags->dot == 0)
		{
			res = ft_strdup("0");
			do_int_width(res ,lflags, &ft_putstr_int);
		}
		else
			do_int_width(ft_putnbr_base(c, "0123456789"), lflags, &ft_putstr_int);
	}
	else if (*str == '%')
	{
		lflags->form = *str;
		res = ft_strdup("%");
		do_int_width(res, lflags, &ft_putstr_int);
		return (1);
	}
	else if (*str == 'p')
	{
		c = (unsigned long)va_arg(argv, unsigned long);
		if (c == 0 && lflags->dot == 0)
		{
			res = ft_strdup("0x0");
			do_int_width(res ,lflags, &ft_putstr_int);
		}
		else
		{
			res = ft_strjoin("0x", ft_putnbr_base(c, "0123456789abcdef"));
			do_int_width(res, lflags, &ft_putstr_int);
		}
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
		if (c == 0 && lflags->dot == 0)
			res = ft_strdup("0");
		else
			res = ft_putnbr_base(c, "0123456789abcdef");
		do_int_width(res, lflags, &ft_putstr_int);
	}
	else if (*str == 'X')
	{
		lflags->form = *str;
		c = (unsigned int)va_arg(argv, int);
		if (c == 0 && lflags->dot == 0)
			res = ft_strdup("0");
		else
			res = ft_putnbr_base(c, "0123456789ABCDEF");
		do_int_width(res, lflags, &ft_putstr_int);
	}
	free(res);
	return (0);
}
