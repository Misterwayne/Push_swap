/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truepath <truepath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:02:05 by mwane             #+#    #+#             */
/*   Updated: 2019/11/20 23:10:51 by truepath         ###   ########.fr       */
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
    char *  buffer;
}              pflags;

void		    ft_putchar(char c, pflags *lflags);
int             ft_putstr(char * str, pflags *lflags);
int			    ft_putnbr(long n, pflags *lflags);
int	            check_params(const char *str, va_list argv, pflags *lflags);
int		        ft_printf(const char *str, ...);
int		        check_base(char *base);
char	       *ft_putnbr_base(long nbr, char *base, pflags *lflags);
int		        ft_atoi(char *nbr);
char            *do_width(char * str, int width, int pre);
int		        ft_strlen(char *str);

#endif