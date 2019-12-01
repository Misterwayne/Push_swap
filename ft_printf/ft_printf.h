/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truepath <truepath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:02:05 by mwane             #+#    #+#             */
/*   Updated: 2019/11/29 19:19:33 by truepath         ###   ########.fr       */
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
    int     detail;
    int     plus;
    int     dot;
    int     len;
    int     end;
    int     zero;
    char    form;
}              pflags;

int		        scan_dot(pflags *lflags, char *str);
int		        check_sign(pflags *lflags, char *str, int *nega);
int		        skipskip(char *str);
int		        skipskip2(char *str);

void		    ft_putchar(char c, pflags *lflags);
void            ft_putstrl(char * str, pflags *lflags);
int			    ft_putnbr(long n, pflags *lflags);
void	        do_int(char *str, va_list argv, pflags *lflags);
int	            check_params(const char *str, va_list argv, pflags *lflags);
int	            check_params2(const char *str, va_list argv, pflags *lflags);
int	            check_params3(const char *str, va_list argv, pflags *lflags);
int	            check_params4(const char *str, va_list argv, pflags *lflags);
int	            check_params5(const char *str, va_list argv, pflags *lflags);
int		        ft_printf(const char *str, ...);
int		        check_base(char *base);
char	        *ft_putnbr_base(long nbr, char *base);
int		        ft_atoi(char *nbr);
char            *do_width(char * str, pflags *lflags,void (*ft_put)(char*, pflags*));
int		        ft_strlen(char *str);
void		    ft_putstr_int(char *str, pflags *lflags);
char	        *ft_strjoin(char const *s1, char const *s2);
char	        *ft_strdup(const char *str);
void	        check_form(int *i, pflags *lflags, char *str);
void	        print_space(int width, pflags *lflags);
void	        do_int(char *str, va_list argv, pflags *lflags);

void	        do_char_width(char *str, pflags *lflags, int temp);
void	        do_str_width(char *str, pflags *lflags);
void	        do_str_width2(pflags *lflags, int temp, int temp2, int i);
void	        do_int_width(pflags *lflags, int temp, int temp2, int i);
void	        check_param(pflags *lflags, char *str, int *temp, int *temp2);
void	        ft_putstr_int(char *str, pflags *lflags);
void	        put_zeros(pflags *lflags, int len, int neg);

#endif