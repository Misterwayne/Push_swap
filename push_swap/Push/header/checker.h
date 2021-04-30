/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 16:22:30 by mwane             #+#    #+#             */
/*   Updated: 2021/04/29 15:33:51 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft2/libft.h"

typedef struct			s_stack_a
{
	int					top;
	unsigned int		max;
	int					*a_stack;
	int					min;
	int					big;
	int					biggest;
	int					smallest;
}						t_stack_a;

typedef struct			s_stack_b
{
	int					top;
	unsigned int		max;
	int					*b_stack;
	int					min;
	int					big;
	int					biggest;
	int					smallest;
}						t_stack_b;

void					rotate_a(t_stack_a *stack);
void					rotate_b(t_stack_b *stack);
void					swap_a(t_stack_a *stack);
void					swap_b(t_stack_b *stack);
void					sa_sb(t_stack_a *stack_a, t_stack_b *stack_b);
void					push_a(t_stack_a *stack_a, t_stack_b *stack_b);
void					push_b(t_stack_b *stack_b, t_stack_a *stack_a);
void					reverse_rotate_a(t_stack_a *stack);
void					reverse_rotate_b(t_stack_b *stack);
void					r_r_r(t_stack_a *stack_a, t_stack_b *stack_b);
void					ra_rb(t_stack_a *stack_a, t_stack_b *stack_b);
void					*init_stack(unsigned int max);
int						is_full_b(t_stack_b *stack);
int						is_full(t_stack_a *stack);
int						is_empty(t_stack_a *stack);
void					push(t_stack_a *stack, int nbr);
int						pop(t_stack_a *stack);
void					print_stack(t_stack_a *stack_a, t_stack_b *stack_b);
void					b_push(t_stack_b *stack, int nbr);
int						pop_b(t_stack_b *stack);
void					free_stack(t_stack_a *stack, t_stack_b *stack_b);
int						sort_checker(t_stack_a *stack, t_stack_b *stack_b);
void					error_msg(int code);
int						duplicate(char **stack, char *item, int index);
void					check_args(int argc, char **args, t_stack_a *stack,
						t_stack_b *stack_b);
char					**ft_split(char const *s, char c);
int						checker_2(char *instruction, t_stack_a *stack,
						t_stack_b *stack_b);
void					checker(char *instruction, t_stack_a *stack,
						t_stack_b *stack_b);
int						check_2(char *instruction);
void					check(char *instruction);
int						absolute_v(int nbr);
void        			quick_sort(t_stack_a *stack_a, t_stack_b *stack_b, int low, int high);
int        				partition(t_stack_a *stack_a, t_stack_b *stack_b, int low, int high);
void        			swap_nbr(t_stack_a *stack_a, t_stack_b *stack_b, int i, int j);
int						find_smallest(t_stack_a *stack);
int						find_biggest(t_stack_a *stack);
void        			sort_3(t_stack_a *stack_a, t_stack_b *stack_b);

#endif
