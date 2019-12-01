/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 18:38:10 by mwane             #+#    #+#             */
/*   Updated: 2019/12/01 13:50:55 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_params(const char *str, va_list argv, t_flags *lflags)
{
	unsigned long	c;
	char			*res;

	c = 0;
	res = NULL;
	if (*str == 'd' || *str == 'i' || *str == 'D')
	{
		do_int((char *)str, argv, lflags);
		return (1);
	}
	else if (*str == 'c')
	{
		lflags->form = 'c';
		c = (char)va_arg(argv, int);
		if (!(res = malloc(sizeof(char) * 2)))
			return (0);
		res[0] = c;
		res[1] = '\0';
		do_width(res, lflags, &ft_putstr_int);
		free(res);
		return (1);
	}
	check_params2((char *)str, argv, lflags);
	return (1);
}

int		check_params2(const char *str, va_list argv, t_flags *lflags)
{
	char	*res;

	res = NULL;
	if (*str == 's')
	{
		lflags->form = *str;
		res = va_arg(argv, char *);
		if (res)
		{
			do_width(res, lflags, &ft_putstrl);
		}
		else
		{
			if (lflags->preci > 0 || lflags->dot == 0)
				res = ft_strdup("(null)");
			else
				res = ft_strdup("");
			do_width(res, lflags, ft_putstrl);
			free(res);
		}
		return (1);
	}
	check_params3((char *)str, argv, lflags);
	return (1);
}

int		check_params3(const char *str, va_list argv, t_flags *lflags)
{
	unsigned long	c;
	char			*res;

	c = 0;
	res = NULL;
	if (*str == 'u' || *str == 'U')
	{
		c = (unsigned int)(4294967295 + 1 + va_arg(argv, unsigned int));
		if (c == 0 && lflags->dot == 0)
			res = ft_strdup("0");
		else
			res = ft_putnbr_base(c, "0123456789");
		do_width(res, lflags, &ft_putstr_int);
		free(res);
	}
	else if (*str == '%')
	{
		lflags->form = 'c';
		res = ft_strdup("%");
		do_width(res, lflags, &ft_putstr_int);
		free(res);
	}
	check_params4(str, argv, lflags);
	return (1);
}

int		check_params4(const char *str, va_list argv, t_flags *lflags)
{
	unsigned long	c;
	char			*res;
	char			*temp;

	c = 0;
	temp = NULL;
	res = NULL;
	if (*str == 'p')
	{
		c = (unsigned long)va_arg(argv, unsigned long);
		if (c == 0 && lflags->dot == 0)
			res = ft_strdup("0x0");
		else
		{
			temp = ft_putnbr_base(c, "0123456789abcdef");
			res = ft_strjoin("0x", temp);
			free(temp);
		}
		do_width(res, lflags, &ft_putstr_int);
		free(res);
	}
	check_params5(str, argv, lflags);
	return (1);
}

int		check_params5(const char *str, va_list argv, t_flags *lflags)
{
	unsigned long	c;
	char			*res;

	c = 0;
	res = NULL;
	if (*str == 'x' || *str == 'X')
	{
		lflags->form = *str;
		c = (unsigned int)va_arg(argv, int);
		if (c == 0 && lflags->dot == 0)
			res = ft_strdup("0");
		else if (*str == 'x')
			res = ft_putnbr_base(c, "0123456789abcdef");
		else if (*str == 'X')
			res = ft_putnbr_base(c, "0123456789ABCDEF");
		do_width(res, lflags, &ft_putstr_int);
		free(res);
	}
	return (0);
}
