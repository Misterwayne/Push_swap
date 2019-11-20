/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 13:58:01 by mwane             #+#    #+#             */
/*   Updated: 2019/11/20 19:32:32 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

int		ft_atoi(char *nbr)
{
	long	nb;
	int		i;
	int		nega;
	int		m;

	nb = 0;
	i = 0;
	nega = -1;
	m = 1;
	while (nbr[i] == '\t' || nbr[i] == '\n' || nbr[i] == ' '
			|| nbr[i] == '\f' || nbr[i] == '\r' || nbr[i] == '\v')
		nbr++;
	if (nbr[i] == '+' || nbr[i] == '-')
	{
		nega += (nbr[i] - 44) + 1;
		i++;
	}
	while (nbr[i] && nbr[i] <= '9' && nbr[i] >= '0')
		i++;
	while (i > 0 && nbr[--i] <= '9' && nbr[i] >= '0')
	{
		nb += (nbr[i] - '0') * m;
		m *= 10;
	}
	return (-nb * nega);
}

int		check_base(char *base)
{
	int	i;
	int	z;

	i = 0;
	z = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		z = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] < 32 || base[i] > 126)
			return (0);
		while (base[z])
		{
			if (base[i] == base[z])
				return (0);
			z++;
		}
		i++;
	}
	return (1);
}

char	*ft_putnbr_base(long nbr, char *base, pflags *lflags)
{
	long	size_base;
	long	nbr_final[100];
	char	*res;
	long	i;
	int		j;

	i = 0;
	j = 0;
	res = malloc(sizeof(char) * 100);
	size_base = 0;
	if (check_base(base))
	{
		if (nbr < 0)
		{
			nbr = -nbr;
			ft_putchar('-', lflags);
			j++;
		}
		while (base[size_base])
			size_base++;
		while (nbr)
		{
			nbr_final[i] = nbr % size_base;
			nbr = nbr / size_base;
			i++;
		}
		while (--i >= 0)
		{
			res[j] = base[nbr_final[i]];
			j++;
		}
	}
	res[j] = '\0';
	return (res);
}
