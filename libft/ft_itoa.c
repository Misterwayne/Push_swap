/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 17:01:31 by mwane             #+#    #+#             */
/*   Updated: 2019/10/14 23:20:48 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int     get_str_len(int nbr)
{
    int i;

    i = 0;
    while (nbr > 0)
    {
        nbr /= 10;
        i++;
    }
    return (i);
}

char	*ft_itoa(int n)
{
	long	nbr;
	char	*result;
	int		nega;
	int		i;
	int		j;

    nbr = n;
    nega = 1;
    j = 0;
    if (nbr < 0)
    {
        nbr *= -1;
        nega++;
        j += 1;
    }
    i = get_str_len(nbr);
    if (!(result = malloc(sizeof(char) * (i + nega))))
        return (0);
    if (n < 0)
        result[0] = '-';
	nega -= 1;
    nega += i;
    i--;
    while (j < nega)
    {
        result[j] = (nbr % 10^i) + '0';
        i--;
        j++;
    }
    result[j] = '\0';
    return (result);
}
#include <stdio.h>
int main(void)
{
    printf("%s\n",ft_itoa(-405));
    return (0);
}