/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 16:22:30 by mwane             #+#    #+#             */
/*   Updated: 2021/10/06 19:40:59 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack_a
{
	int					top;
	unsigned int		max;
	int					*a_stack;
	int					min;
	int					biggest;
	int					smallest;
	int					half;
	int					place;
	int					dir;
	int					up_place;
	int					action;
	int					ra;
	int					rra;
}						t_stack_a;

typedef struct s_stack_b
{
	int					top;
	unsigned int		max;
	int					*b_stack;
	int					min;
	int					biggest;
	int					smallest;
	int					half;
	int					dir;
	int					place;
	int					action;
	int					rb;
	int					rrb;
}						t_stack_b;

void					rotate_a(t_stack_a *stack, int mode);
void					rotate_b(t_stack_b *stack, int mode);
void					swap_a(t_stack_a *stack);
void					swap_b(t_stack_b *stack);
void					sa_sb(t_stack_a *stack_a, t_stack_b *stack_b);
void					push_a(t_stack_a *stack_a, t_stack_b *stack_b);
void					push_b(t_stack_b *stack_b, t_stack_a *stack_a);
void					reverse_rotate_a(t_stack_a *stack, int mode);
void					reverse_rotate_b(t_stack_b *stack, int mode);
void					r_r_r(t_stack_a *stack_a, t_stack_b *stack_b);
void					ra_rb(t_stack_a *stack_a, t_stack_b *stack_b);
void					*init_stack(unsigned int max);
int						is_full_b(t_stack_b *stack);
int						is_full(t_stack_a *stack);
int						is_empty(t_stack_a *stack);
void					push(t_stack_a *stack, int nbr);
int						pop(t_stack_a *stack);
void					b_push(t_stack_b *stack, int nbr);
int						pop_b(t_stack_b *stack);
void					free_stack(t_stack_a *stack, t_stack_b *stack_b);
int						sort_checker(t_stack_a *stack, t_stack_b *stack_b);
void					error_msg(void);
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
void					find_smallest(t_stack_a *stack_a);
int						find_smallest_b(t_stack_b *stack_b);
void					find_biggest(t_stack_a *stack_a);
void					sort_opti(t_stack_a *stack_a, t_stack_b *stack_b);
int						find_biggest_b(t_stack_b *stack);
char					**free_tab(char **res, int i);
long					ft_atoi(char *nbr);
int						ft_strcmp(char *s1, char *s2);
void					print_stack(t_stack_a *stack_a, t_stack_b *stack_b);
void					high_rotate(int index, t_stack_a *stack_a,
							t_stack_b *stack_b);
void					low_rotate(int index, t_stack_a *stack_a,
							t_stack_b *stack_b);
int						find_smallest_chunk(t_stack_a *stack_a);
int						*int_cmp(t_stack_a *stack_a);
void					quick_sort(int *stack_a, int low, int high);
void					small_sort(t_stack_a *stack_a, t_stack_b *stack_b);
void					sort_3(t_stack_a *stack_a);
void					sort_5(t_stack_a *stack_a, t_stack_b *stack_b);
void					case_3(t_stack_a *stack_a);
void					case_2(t_stack_a *stack_a);
void					case_1(t_stack_a *stack_a);
int						smallest(t_stack_a *stack_a);
void					low_rotate_b(int index, t_stack_a *stack_a, t_stack_b *stack_b);
int     				rotate_opti(t_stack_a *stack_a);

#endif
