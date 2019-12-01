/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 13:58:01 by mwane             #+#    #+#             */
/*   Updated: 2019/12/01 12:38:15 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (nbr[i] == '-' || nbr[i] == '+')
	{
		if (nbr[i] == '-')
			nega += (nbr[i] - 44) + 1;
		while (nbr[i] == '-' || nbr[i] == '+')
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

char	*fill_res(char *base, long *nbr, int neg, int i)
{
	char	*res;
	int		j;

	j = 0;
	if (!(res = malloc(sizeof(char) * 100)))
		return (NULL);
	if (neg == 1)
		res[j++] = '-';
	while (--i >= 0)
		res[j++] = base[nbr[i]];
	res[j] = '\0';
	return (res);
}

char	*ft_putnbr_base(long nbr, char *base)
{
	long	size_base;
	long	nbr_final[100];
	long	i;
	int		nega;

	i = 0;
	nega = 0;
	size_base = ft_strlen(base);
	if (check_base(base))
	{
		if (nbr < 0)
			nega = 1;
		if (nbr < 0)
			nbr *= -1;
		while (nbr)
		{
			nbr_final[i++] = nbr % size_base;
			nbr = nbr / size_base;
		}
		return (fill_res(base, nbr_final, nega, i));
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	int		lens1;
	int		lens2;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	lens1 = ft_strlen((char *)s1);
	lens2 = ft_strlen((char *)s2);
	if (!(newstr = malloc(sizeof(char) * (lens1 + lens2 + 1))))
		return (NULL);
	while (++i < lens1)
		newstr[i] = s1[i];
	while (i < lens1 + lens2)
		newstr[i++] = s2[j++];
	newstr[i] = '\0';
	return (newstr);
}
