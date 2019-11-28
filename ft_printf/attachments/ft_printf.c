/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truepath <truepath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 13:05:22 by mwane             #+#    #+#             */
/*   Updated: 2019/11/26 02:52:07 by truepath         ###   ########.fr       */
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

//  int		check_pre_width(const char *str, pflags *lflags, va_list argv)
//  {
// 	 int i;
// 	 int lflags->dot;
// 	 int nega;

// 	i = 0;
// 	dot = 0;
// 	if (*str == '-')
// 	{
// 		nega = -1;
// 		while (*str == '-')
// 			str++;
// 	}
// 	while (str[i] < 58)
// 	{
// 		if (str[i] == '.')
// 			dot = 1;
// 	}
//  }

int		check_pre_width(const char *str, pflags *lflags, va_list argv)
{
	int p;
	int nega;
	int len1;
	int i;

	i = 0;
	p = 0;
	lflags->dot = 1;
	nega = 1;
	len1 = ft_strlen((char *)str);
	while (str[i] != '%')
	{
		if (str[i++] == '.')
			lflags->dot = 0;
	}
	while (*str == '0')
	{
		if (*str == '0' && lflags->dot == 1)
		{
			p = 1;
			lflags->detail += 1;
		}
		str++;
	}		
	if (*str == '-' || *str == '+' || *str == ' ')
	{
		if (*str == '-')
			nega = -1;
		if (*str == '+')
			lflags->plus = 1;
		if (*str == ' ')
		{
			ft_putchar(' ', lflags);
		}
		while (*str == '-' || *str == '+' || *str == ' ')
			str++;
	}
	if (*str == '*')
		lflags->width = (int)va_arg(argv, int);
	else
		lflags->width = ft_atoi((char *)str) * nega;
	if (nega < 0 && lflags->width > 0)
		lflags->width *= nega;
	while ((*str >= '0' && *str <= '9' && p == 0) || *str == '-' || *str == '*')
		str++;
	if (*str == '.' || p == 1)
	{
		while ((*str == '0' || *str == '.'))
			str++;
		if (*str == '*')
			lflags->preci = (int)va_arg(argv, int);
		else if ((*str == '0' || (*str + 1 < '0' || *str + 1 > '9')))
			lflags->preci = -2;
		else
			lflags->preci = ft_atoi((char *)str);
		while ((*str >= '0' && *str <= '9') || *str == '-' || *str == '*')
			str++;
		if (lflags->preci == 0)
			lflags->preci = -1;
	}
	check_params(str, argv, lflags);
	return (len1 - ft_strlen((char *)str));
}

int		ft_printf(const char *str, ...)
{
	va_list argv_list;
	pflags  lflags = {0, -1, 0, 0, 0, 0, '0'};
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
		lflags.preci = -1;
		lflags.width = 0;
		lflags.plus = 0;
		str++;
	}
	return (lflags.total_len);
}

int main(void)
{
	int dec = 71;
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
	v = ft_printf("titi %---12.5% %s et%%%0004% et %-1% h\n","%");
	printf("%d----------------------\n",v);
	v = printf("titi %---12.5% %s et%%%0004% et %-1% h\n","%");
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