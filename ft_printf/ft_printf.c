/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 13:05:22 by mwane             #+#    #+#             */
/*   Updated: 2019/11/22 21:09:02 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
changer putnbrbase pour les negatif. DONE
gerer la precition et le width au cas par cas. INT DONE.
Faire le Makefile.
separer les fonction.
Organiser les fichier.
fix le return de la ft_printf.


*/
#include "ft_printf.h"

int		check_pre_width(const char *str, pflags *lflags, va_list argv)
{
	int p;
	int len1;

	p = 0;
	len1 = ft_strlen((char *)str);
	if (*str == '*')
		lflags->width = (int)va_arg(argv, int);
	else
		lflags->width = ft_atoi((char *)str);
	while ((*str >= '0' && *str <= '9') || *str == '-' || *str == '*')
		str++;
	if (*str == '.')
	{
		str++;
		if (*str == '*')
			lflags->preci = (int)va_arg(argv, int);
		else
			lflags->preci = ft_atoi((char *)str);
		while ((*str >= '0' && *str <= '9') || *str == '-' || *str == '*')
			str++;
	}	// printf("pre = %d\n", lflags->preci);
	// printf("width = %d\n",lflags->width);
	// printf("str = %s\n",str);
	check_params(str, argv, lflags);
	return (len1 - ft_strlen((char *)str));
}

int		ft_printf(const char *str, ...)
{
	va_list argv_list;
	pflags  lflags = {0, -1, 0, NULL};

	va_start(argv_list, str);
	while (*str)
	{
		if (*str != '%')
			ft_putchar(*str, &lflags);
		else
		{
			str++;
			str += check_pre_width(str, &lflags, argv_list);
		}
		lflags.preci = 0;
		lflags.width = 0;
		str++;
	}
	return (lflags.total_len);
}

int main(void)
{
	int dec = 800;
	// char chara = 'x';
	// char *str = "okidoki";
	unsigned int ui = -89;
	// int x = 44555566;
	// int j = x;
	int v;

	v = ft_printf("| %%s = %*.*s |\n", 8, 8,"OKKO");
	printf("%d----------------------\n",v);
	v = printf("| %%s = %*.*s |\n", 8, 8,"OKKO");
	printf("%d----------------------\n",v);
	v = ft_printf("| %%d = %*.*d |\n", 15, 7,dec);
	printf("%d----------------------\n",v);
	v = printf("| %%d = %*.*d |\n", 15, 7, dec);
	printf("%d----------------------\n",v);
	v = ft_printf("| %%u = %*.*u |\n", -15, 0,ui);
	printf("%d----------------------\n",v);
	v = printf("| %%u = %*.*u |\n", -15, 0, ui);
	printf("%d----------------------\n",v);
	}