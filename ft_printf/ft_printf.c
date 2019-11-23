/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 13:05:22 by mwane             #+#    #+#             */
/*   Updated: 2019/11/23 17:59:06 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
changer putnbrbase pour les negatif. DONE
gerer la precition et le width au cas par cas. DONE.
Faire le Makefile.
separer les fonction. Done
Organiser les fichier.
fix le return de la ft_printf. DONE
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
	if (str[0] == '0')
		p = 1;
	while ((*str >= '0' && *str <= '9' && p == 0) || *str == '-' || *str == '*')
		str++;
	if (*str == '.' || p == 1)
	{
		str++;
		if (*str == '*')
			lflags->preci = (int)va_arg(argv, int);
		else
			lflags->preci = ft_atoi((char *)str);
		while ((*str >= '0' && *str <= '9') || *str == '-' || *str == '*')
			str++;
	}
	check_params(str, argv, lflags);
	return (len1 - ft_strlen((char *)str));
}

int		ft_printf(const char *str, ...)
{
	va_list argv_list;
	pflags  lflags = {0, -1, 0, '0'};

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
	int dec = 78900;
	// char chara = 'x';
	// // char *str = "okidoki";
	// unsigned int ui = -44555566;
	// unsigned int x = -44555566;
	// int j = x;
	int v;

	// v = ft_printf("| %%s = %*.*s |\n", 8, 0,"OKKO");
	// printf("%d----------------------\n",v);
	// v = printf("| %%s = %*.*s |\n", 8, 0,"OKKO");
	// printf("%d----------------------\n\n",v);
	// v = ft_printf("| %%s = %*.*s |\n", 8, 1,"OKKO");
	// printf("%d----------------------\n",v);
	// v = printf("| %%s = %*.*s |\n", 8, 1,"OKKO");
	// printf("%d----------------------\n\n",v);
	// v = ft_printf("| %%s = %*.*s |\n", 8, 2,"OKKO");
	// printf("%d----------------------\n",v);
	// v = printf("| %%s = %*.*s |\n", 8, 2,"OKKO");
	// printf("%d----------------------\n\n",v);
	// v = ft_printf("| %%s = %*.*s |\n", 8, 4,"OKKO");
	// printf("%d----------------------\n",v);
	// v = printf("| %%s = %*.*s |\n", 8, 4,"OKKO");
	// printf("%d----------------------\n\n",v);
	v = ft_printf("%50d\n",dec);
	printf("%d----------------------\n",v);
	v = printf("%50d\n",dec);
	printf("%d----------------------\n\n",v);
	// v = ft_printf("| %%u = %*.*u |\n", -15, 0,ui);
	// printf("%d----------------------\n",v);
	// v = printf("| %%u = %*.*u |\n", -15, 0, ui);
	// printf("%d----------------------\n",v);
	// v = ft_printf("| %%d = %*.*d |\n", 5, 7,dec);
	// printf("%d----------------------\n",v);
	// v = printf("| %%d = %*.*d |\n", 5, 7, dec);
	// printf("%d----------------------\n\n",v);
	// v = ft_printf("| %%x = %*.*X |\n", -15, 12,x);
	// printf("%d----------------------\n",v);
	// v = printf("| %%x = %*.*X |\n", -15, 12, x);
	// printf("%d----------------------\n",v);
	// v = ft_printf("| %%x = %*.*X |\n", 15, 0,x);
	// printf("%d----------------------\n",v);
	// v = printf("| %%x = %*.*X |\n", 15, 0, x);
	// printf("%d----------------------\n\n",v);
	// v = ft_printf("| %%u = %*.*u |\n", 15, 6,ui);
	// printf("%d----------------------\n",v);
	// v = printf("| %%u = %*.*u |\n", 15, 6, ui);
	// printf("%d----------------------\n",v);
	// v = ft_printf("| %%p = %*p |\n", 20 ,&j);
	// printf("%d----------------------\n",v);
	// v = printf("| %%p = %*p |\n", 20, &j);
	// printf("%d----------------------\n",v);
	}