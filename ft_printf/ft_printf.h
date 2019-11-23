/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:02:05 by mwane             #+#    #+#             */
/*   Updated: 2019/11/23 17:57:11 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_PRINTF_H_
# define _FT_PRINTF_H_

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

typedef struct pflags
{
    int     width;
    int     preci;
    int     total_len;
    char    form;
}              pflags;

void		    ft_putchar(char c, pflags *lflags);
void            ft_putstrl(char * str, pflags *lflags);
int			    ft_putnbr(long n, pflags *lflags);
int	            check_params(const char *str, va_list argv, pflags *lflags);
int	            check_params2(const char *str, va_list argv, pflags *lflags);
int	            check_params3(const char *str, va_list argv, pflags *lflags);
int		        ft_printf(const char *str, ...);
int		        check_base(char *base);
char	       *ft_putnbr_base(long nbr, char *base);
int		        ft_atoi(char *nbr);
char            *do_int_width(char * str, pflags *lflags,void (*ft_put)(char*, pflags*));
int		        ft_strlen(char *str);
void		    ft_putstr_int(char *str, pflags *lflags);
char	        *ft_strjoin(char const *s1, char const *s2);
char	        *ft_strdup(const char *str);

#endif