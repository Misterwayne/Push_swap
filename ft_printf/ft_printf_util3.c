/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 16:26:51 by truepath          #+#    #+#             */
/*   Updated: 2019/12/01 13:50:29 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_zeros(t_flags *lflags, int len, int neg)
{
	while (lflags->preci > len + neg)
	{
		ft_putchar('0', lflags);
		lflags->preci--;
	}
}

void	ft_putstr_int(char *str, t_flags *lflags)
{
	int i;
	int neg;

	i = 0;
	neg = 0;
	if (!str)
		return ;
	if (*str == '-' || lflags->plus == 1)
	{
		if (lflags->plus == 1 && *str != '-')
			ft_putchar('+', lflags);
		else
		{
			ft_putchar('-', lflags);
			str++;
		}
		if (lflags->detail == 1)
			neg = 1;
	}
	if (lflags->dot == 1 && lflags->form == '%')
		lflags->preci = -1;
	put_zeros(lflags, ft_strlen(str), neg);
	while (str[i] && lflags->preci != 0)
		ft_putchar(str[i++], lflags);
}

void	check_param(t_flags *lflags, char *str, int *temp, int *temp2)
{
	int		len;

	*temp = lflags->width;
	*temp2 = lflags->preci;
	len = ft_strlen(str);
	if (*temp < 0)
		*temp *= -1;
	if (*temp < len)
		*temp = len;
	if (*temp2 < len)
		*temp2 = len;
}

void	print_space(int width, t_flags *lflags)
{
	if (lflags->plus == 1)
		width--;
	while (0 < width--)
		ft_putchar(' ', lflags);
}

void	check_form(int *i, t_flags *lflags, char *str)
{
	if (str && (str[0] == '-' && lflags->preci > 0))
		*i = -1;
	else if (lflags->form == 's')
		*i = 2;
	else if (lflags->form == 'x' || lflags->form == 'X')
		*i = 0;
	return ;
}
