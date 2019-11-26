/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 18:51:33 by mwane             #+#    #+#             */
/*   Updated: 2019/11/25 18:15:29 by mwane            ###   ########.fr       */
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

void	ft_putstrl(char *str, pflags *lflags)
{
	int i;

	i = 0;
	if (!str)
		return ;
	if (lflags->preci == 0)
		return ;
	while (str[i] && i < lflags->preci)
	{
		ft_putchar(str[i], lflags);
		i++;
	}
}

char	*ft_strdup(const char *str)
{
	char	*nstr;
	int		i;

	i = 0;
	while (str[i] != 0)
		i++;
	if (!(nstr = malloc((sizeof(char) * (i + 1)))))
		return (NULL);
	i = -1;
	while (str[++i])
		nstr[i] = str[i];
	nstr[i] = '\0';
	return (nstr);
}
