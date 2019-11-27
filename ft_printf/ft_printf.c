/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 13:05:22 by mwane             #+#    #+#             */
/*   Updated: 2019/11/27 19:25:39 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		scan_dot(pflags *lflags, char *str)
{
	int p;
	int nega;
	int len1;
	int i;

	i = 0;
	p = 0;
	lflags->dot = 0;
	nega = 1;
	len1 = ft_strlen((char *)str);
	while (str[i] < 58)
	{
		if (str[i++] == '.')
			lflags->dot = 1;
	}
	while (*str == '0')
	{
		if (str[0] == '0' && str[1] != '0' && lflags->dot == 0)
		{
			p = 1;
			lflags->detail += 1;
		}
		str++;
	}
	return (p);
}

void	check_sign(pflags *lflags, char *str)
{
	int p;
	int nega;
	int len1;
	int i;

	i = 0;
	p = 0;
	lflags->dot = 0;
	nega = 1;
	len1 = ft_strlen((char *)str);
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
}

int		check_pre_width(const char *str, pflags *lflags, va_list argv)
{
	int p;
	int nega;
	int len1;
	int i;

	i = 0;
	lflags->dot = 0;
	nega = 1;
	len1 = ft_strlen((char *)str);
	p = scan_dot(lflags, (char *)str);
	// check_sign(lflags, (char *)str);
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
	else if (p == 0)
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
		else if ((*str == '0' || (*str + 1 < '0' || *str + 1 > '9')) && p == 0)
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

void	reset_struct(pflags *lflags)
{
	lflags->preci = -1;
	lflags->width = 0;
	lflags->plus = 0;
	lflags->form = 0;
	lflags->dot = 0;
}

int		ft_printf(const char *str, ...)
{
	va_list argv_list;
	pflags  lflags = {0, -1, 0, 0, 0, 0, 0, 0,'0'};

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
		reset_struct(&lflags);
		str++;
		if (lflags.end == 1)
			break ;
	}
	return (lflags.total_len);
}

// int main(void)
// {
// 	//int dec = 71;
// 	// char chara = 'x';
// 	// // char *str = "okidoki";
// 	// unsigned int ui = -44555566;
// 	// unsigned int x = -44555566;
// 	// int j = x;
// 	int v;

// 	// v = ft_printf("| %%s = %*.*s |\n", 8, 0,"OKKO");
// 	// printf("%d----------------------\n",v);
// 	// v = printf("| %%s = %*.*s |\n", 8, 0,"OKKO");
// 	// printf("%d----------------------\n\n",v);
// 	// v = ft_printf("| %%s = %*.*s |\n", 8, 1,"OKKO");
// 	// printf("%d----------------------\n",v);
// 	// v = printf("| %%s = %*.*s |\n", 8, 1,"OKKO");
// 	// printf("%d----------------------\n\n",v);
// 	// v = ft_printf("| %%s = %*.*s |\n", 8, 2,"OKKO");
// 	// printf("%d----------------------\n",v);
// 	// v = printf("| %%s = %*.*s |\n", 8, 2,"OKKO");
// 	// printf("%d----------------------\n\n",v);
// 	// v = ft_printf("| %%s = %*.*s |\n", 8, 4,"OKKO");
// 	// printf("%d----------------------\n",v);
// 	// v = printf("| %%s = %*.*s |\n", 8, 4,"OKKO");
// 	// printf("%d----------------------\n\n",v);
// 	v = ft_printf("u%4.2ss %-1.s\n %---5.3s\n", "coco", NULL, "yooo");
// 	printf("%d----------------------\n",v);
// 	v = printf("u%4.2ss %-1.s\n %---5.3s\n", "coco", NULL, "yooo");
// 	printf("%d----------------------\n\n",v);
// 	// printf("----------------------\n\n");
// 	// v = ft_printf("%1.4s et %-6.8s et %4.2s\n", "tuuu", "12345", "hu");
// 	// printf("%d----------------------\n\n",v);
// 	// v = printf("%1.4s et %-6.8s et %4.2s\n", "tuuu", "12345", "hu");
// 	// printf("%d----------------------\n\n",v);
// 	// v = ft_printf("| %%u = %*.*u |\n", -15, 0,ui);
// 	// printf("%d----------------------\n",v);
// 	// v = printf("| %%u = %*.*u |\n", -15, 0, ui);
// 	// printf("%d----------------------\n",v);
// 	// v = ft_printf("| %%d = %*.*d |\n", 5, 7,dec);
// 	// printf("%d----------------------\n",v);
// 	// v = printf("| %%d = %*.*d |\n", 5, 7, dec);
// 	// printf("%d----------------------\n\n",v);
// 	// v = ft_printf("| %%x = %*.*X |\n", -15, 12,x);
// 	// printf("%d----------------------\n",v);
// 	// v = printf("| %%x = %*.*X |\n", -15, 12, x);
// 	// printf("%d----------------------\n",v);
// 	// v = ft_printf("| %%x = %*.*X |\n", 15, 0,x);
// 	// printf("%d----------------------\n",v);
// 	// v = printf("| %%x = %*.*X |\n", 15, 0, x);
// 	// printf("%d----------------------\n\n",v);
// 	// v = ft_printf("| %%u = %*.*u |\n", 15, 6,ui);
// 	// printf("%d----------------------\n",v);
// 	// v = printf("| %%u = %*.*u |\n", 15, 6, ui);
// 	// printf("%d----------------------\n",v);
// 	// v = ft_printf("| %%p = %*p |\n", 20 ,&j);
// 	// printf("%d----------------------\n",v);
// 	// v = printf("| %%p = %*p |\n", 20, &j);
// 	// printf("%d----------------------\n",v);
// 	}