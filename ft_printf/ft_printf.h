/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:02:05 by mwane             #+#    #+#             */
/*   Updated: 2019/12/01 13:49:13 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_PRINTF_H
# define _FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct	s_flags
{
	int			width;
	int			preci;
	int			total_len;
	int			detail;
	int			plus;
	int			dot;
	int			len;
	int			end;
	int			zero;
	char		form;
}				t_flags;

int				scan_dot(t_flags *lflags, char *str);
int				check_sign(t_flags *lflags, char *str, int *nega);
int				skipskip(char *str);
int				skipskip2(char *str);
void			ft_putchar(char c, t_flags *lflags);
void			ft_putstrl(char *str, t_flags *lflags);
int				ft_putnbr(long n, t_flags *lflags);
void			do_int(char *str, va_list argv, t_flags *lflags);
int				check_params(const char *str, va_list argv, t_flags *lflags);
int				check_params2(const char *str, va_list argv, t_flags *lflags);
int				check_params3(const char *str, va_list argv, t_flags *lflags);
int				check_params4(const char *str, va_list argv, t_flags *lflags);
int				check_params5(const char *str, va_list argv, t_flags *lflags);
int				ft_printf(const char *str, ...);
int				check_base(char *base);
char			*ft_putnbr_base(long nbr, char *base);
int				ft_atoi(char *nbr);
char			*do_width(char *str, t_flags *lflags,
				void (*ft_put)(char*, t_flags*));
int				ft_strlen(char *str);
void			ft_putstr_int(char *str, t_flags *lflags);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strdup(const char *str);
void			check_form(int *i, t_flags *lflags, char *str);
void			print_space(int width, t_flags *lflags);
void			do_int(char *str, va_list argv, t_flags *lflags);
void			do_char_width(char *str, t_flags *lflags, int temp);
void			do_str_width(char *str, t_flags *lflags);
void			do_str_width2(t_flags *lflags, int temp, int temp2, int i);
void			do_int_width(t_flags *lflags, int temp, int temp2, int i);
void			check_param(t_flags *lflags, char *str, int *temp, int *temp2);
void			ft_putstr_int(char *str, t_flags *lflags);
void			put_zeros(t_flags *lflags, int len, int neg);

#endif
