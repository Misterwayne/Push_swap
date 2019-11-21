/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truepath <truepath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 13:05:22 by mwane             #+#    #+#             */
/*   Updated: 2019/11/21 00:38:36 by truepath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while(str[i])
	{
		i++;
		str++;
	}
	return i;
}

void		ft_putchar(char c, pflags *lflags)
{
	write(1, &c, 1);
	lflags->total_len += 1;
}

int ft_putstr(char * str, pflags *lflags)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		ft_putchar(str[i], lflags);
		i++;
	}
	return (i);
}

int			ft_putnbr(long n, pflags *lflags)
{
	long nbr;
	int i;

	nbr = n;
	i = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		ft_putchar('-', lflags);
		i++;
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10, lflags);
		ft_putnbr(nbr % 10, lflags);
	}
	else
	{
		ft_putchar(nbr + 48, lflags);
		i++;
	}
	return (i);
}

int		check_pre_with(const char *str, pflags * lflags, va_list argv_list)
{
	int p;
	int len1;

	p = 0;
	len1 = ft_strlen((char *)str);
	if ((*str == '-') || (*str == '.') || (*str >= '0' && *str <= '9'))
	{
		lflags->width = ft_atoi((char *)str);
		//  printf("with = %d\n",lflags->width);
		while(*str != '.')
			str++;
		str++;
		lflags->preci = ft_atoi((char *)str);
		//  printf("preci = %d\n",lflags->preci);
		str++;
	}
	check_params(str, argv_list, lflags);
	return (len1 - ft_strlen((char *)str));
}

int	check_params(const char *str, va_list argv, pflags *lflags)
{
	unsigned long c;
	char *res;

	c = 0;
	res = NULL;
	if (*str == 'd')
	{
		c = (int)va_arg(argv, int);
		res = ft_putnbr_base(c, "0123456789", lflags);
	}
	else if (*str == 'c')
	{
		c = (char)va_arg(argv, int);
		ft_putchar(c, lflags);
		return (1);
	}
	else if (*str == 's')
	{
		ft_putstr(do_width(va_arg(argv, char *), lflags->width, lflags->preci), lflags);
		return (1);
	}
	else if (*str == 'u')
	{
		c = (unsigned int)(4294967295 + 1 + va_arg(argv, unsigned int));
		res = ft_putnbr_base(c, "0123456789", lflags);
	}
	else if (*str == '%')
	{
		write(1, "%", 1);
		lflags->total_len += 1;
		return (1);
	}
	else if (*str == 'p')
	{
		c = (unsigned long)va_arg(argv, unsigned long);
		ft_putchar('0', lflags);
		ft_putchar('x', lflags);
		res = ft_putnbr_base(c, "0123456789abcdef", lflags);
	}
	else if (*str == 'x')
	{
		c = (int)va_arg(argv, int);
		res = ft_putnbr_base(c, "0123456789abcdef", lflags);
	}
	else if (*str == 'X')
	{
		c = (int)va_arg(argv, int);
		res = ft_putnbr_base(c, "0123456789ABCDEF", lflags);
	}
	ft_putstr(do_width(res, lflags->width, lflags->preci), lflags);
	free(res);
	return (0);
}

int		ft_printf(const char *str, ...)
{
	va_list argv_list;
	pflags  lflags = {0, 0, 0, NULL};

	va_start(argv_list, str);
	while (*str)
	{
		if (*str != '%')
			ft_putchar(*str, &lflags);
		else
		{
			str++;
			str += check_pre_with(str, &lflags, argv_list);
		}
		lflags.preci = 0;
		lflags.width = 0;
		str++;
	}
	return (lflags.total_len);
}

int main(void)
{
	int dec = 7854;
	char chara = 'x';
	char *str = "okidoki";
	unsigned int ui = -16;
	int x = 44555566;
	int j = x;
	int v;
	
	v = ft_printf("| %%d = %10d |\n| %%c = %c |\n| %%s = %s |\n| %%u = %u |\n| %%p = %p |\n| %%x = %X |\n", dec, chara, str, ui, &j, x);
	// printf("%d---------------------\n",v);
	// v = printf("| %%d = %d |\n| %%c = %c |\n| %%s = %s |\n| %%u = %u |\n| %%p = %p |\n| %%x = %X |\n", dec, chara, str, ui, &j, x);
	// printf("%d---------------------\n",v);
	}