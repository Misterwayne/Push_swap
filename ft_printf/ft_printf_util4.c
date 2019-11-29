/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 18:51:33 by mwane             #+#    #+#             */
/*   Updated: 2019/11/29 14:26:38 by mwane            ###   ########.fr       */
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
		ft_putstrl("(null)", lflags);
	if (lflags->preci == -1)
		lflags->preci = ft_strlen(str);
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
	if (!str)
		return (NULL);
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
	do_width(res, lflags, &ft_putstr_int);
	free(res);
}
