/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 13:05:22 by mwane             #+#    #+#             */
/*   Updated: 2019/11/12 19:30:07 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putchar(char c, pflags *lflags)
{
	write(1, &c, 1);
	lflags->total_len += 1;
}

int ft_putstr(char * str)
{
	int i;

	i = 0;
	while (*str)
	{
		write(1, str++, 1);
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


int	check_params(const char *str, va_list argv, pflags *lflags);

int		ft_printf(const char *str, ...)
{
	va_list argv_list;
	pflags  lflags = {0,0,NULL};

	va_start(argv_list, str);
	while (*str)
	{
		if (*str != '%')
		{
			write(1, str, 1);
			lflags.total_len += 1;
		}
		else
		{
			str++;
			check_params(str, argv_list, &lflags);
		}
		str++;
	}
	return (lflags.total_len);
}

int		check_pre_with(const char *str)
{
	int p;

	p = ft_atoi((char *)str);
	while (p >= 0)
	{
		write(1, " ", 1);
		p--;
	}
	return (1);
}

int	check_params(const char *str, va_list argv, pflags *lflags)
{
	unsigned long c;

	c = 0;
	if ((*str == '-') || (*str == '.') || (*str >= '0' && *str <= '9'))
	{
		check_pre_with(str);
		str++;
		check_params(str, argv, lflags);
	}
	else if (*str == 'd')
	{
		c = (int)va_arg(argv, int);
		lflags->total_len += ft_putnbr(c, lflags);
		return (1);
	}
	else if (*str == 'c')
	{
		c = (char)va_arg(argv, int);
		ft_putchar(c, lflags);
		lflags->total_len += 1;
 		return (1);
	}
	else if (*str == 's')
	{
		lflags->total_len += ft_putstr(va_arg(argv, char *));
		return (1);
	}
	else if (*str == 'u')
	{
		c = (unsigned int)(4294967295 + 1 +va_arg(argv, unsigned int));
		ft_putnbr(c, lflags);
		return (1);
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
		write(1, "0x", 2);
		ft_putnbr_base(c, "0123456789abcdef", lflags);
	}
	else if (*str == 'x')
	{
		c = (int)va_arg(argv, int);
		ft_putnbr_base(c, "0123456789abcdef", lflags);
	}
	else if (*str == 'X')
	{
		c = (int)va_arg(argv, int);
		ft_putnbr_base(c, "0123456789ABCDEF", lflags);
	}
	return (0);
}

int main(void)
{
	int dec = -100000;
	char chara = 'x';
	char *str = "okidoki";
	unsigned int ui = -16;
	int x = 44555566;
	int j = x;
	int v;
	
	v = ft_printf("| %%d = %d |\n| %%c = %c |\n| %%s = %s |\n| %%u = %u |\n| %%p = %p |\n| %%x = %X |\n", dec, chara, str, ui, &j, x);
	printf("%d---------------------\n",v);
	v = printf("| %%d = %2d |\n| %%c = %c |\n| %%s = %s |\n| %%u = %u |\n| %%p = %p |\n| %%x = %X |\n", dec, chara, str, ui, &j, x);
	printf("%d---------------------\n",v);
}