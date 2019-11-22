/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 18:51:33 by mwane             #+#    #+#             */
/*   Updated: 2019/11/22 19:48:08 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar(char c, pflags *lflags)
{
	write(1, &c, 1);
	lflags->total_len += 1;
}

void	ft_putstr(char *str, pflags *lflags)
{
	int i;

	i = 0;
	if (!str)
		return ;
	if (lflags->preci <= 0)
		return ;
	while (str[i] && i < lflags->preci)
	{
		ft_putchar(str[i], lflags);
		i++;
	}
}

int		ft_putnbr(long n, pflags *lflags)
{
	long	nbr;
	int		i;

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
