/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 11:54:21 by mwane             #+#    #+#             */
/*   Updated: 2019/12/01 13:50:06 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	do_char_width(char *str, t_flags *lflags, int temp)
{
	int	i;

	if (lflags->dot == 0)
		i = lflags->preci;
	else
		i = lflags->width;
	if (lflags->width > 0 && lflags->zero == 0)
		print_space(temp - 1, lflags);
	else if (lflags->zero == 1)
	{
		while (i-- > 1)
			ft_putchar('0', lflags);
	}
	ft_putchar(*str, lflags);
	if (lflags->width <= 0)
		print_space(temp - 1, lflags);
	return ;
}

void	do_str_width(char *str, t_flags *lflags)
{
	int temp;
	int temp2;
	int len;

	temp = lflags->width;
	temp2 = lflags->preci;
	len = ft_strlen(str);
	if (temp < 0)
		temp *= -1;
	if (temp2 > len)
		temp2 = len;
	if (temp > ft_strlen(str))
	{
		if (lflags->preci > 0)
			print_space(temp - temp2, lflags);
		else if (lflags->preci <= 0)
			print_space(temp - len, lflags);
	}
}

void	do_str_width2(t_flags *lflags, int temp, int temp2, int i)
{
	if (lflags->preci <= 0 && i == 2 && lflags->width > 0)
		print_space(temp - temp2, lflags);
	else if (i == 2 && lflags->width > 0 && lflags->preci > 0)
		print_space(temp - lflags->preci, lflags);
}

void	do_int_width(t_flags *lflags, int temp, int temp2, int i)
{
	if ((temp - temp2 + i) == 0 && lflags->preci == 0)
		print_space(temp, lflags);
	else
		print_space(temp - temp2 + i, lflags);
}

char	*do_width(char *str, t_flags *lflags, void (*ft_put)(char*, t_flags*))
{
	int		i;
	int		temp;
	int		temp2;

	i = 0;
	check_param(lflags, str, &temp, &temp2);
	check_form(&i, lflags, str);
	if (lflags->form == 'c')
	{
		do_char_width(str, lflags, temp);
		return (0);
	}
	else if (i == 2)
		do_str_width2(lflags, temp, temp2, i);
	else if (lflags->width > ft_strlen(str) && i != 2)
		print_space(temp - temp2 + i, lflags);
	if (lflags->form != 'c')
		ft_put(str, lflags);
	if ((lflags->form == 's') && lflags->width < 0)
		do_str_width(str, lflags);
	else if (lflags->width < 0 && i != 2)
		do_int_width(lflags, temp, temp2, i);
	return (NULL);
}
