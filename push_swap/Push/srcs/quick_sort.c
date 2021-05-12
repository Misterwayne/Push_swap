/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:51:20 by mwane             #+#    #+#             */
/*   Updated: 2021/05/12 18:11:38 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../header/checker.h"

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

// int		find_biggest_b(t_stack_b *stack)
// {
// 	int i;

// 	i = 0;
// 	stack->big = -2147483648;
// 	while (i <= stack->top)
// 	{
// 		if (stack->b_stack[i] > stack->big)
// 		{
// 			stack->big = stack->b_stack[i];
// 			stack->biggest = i;
// 		}
// 		i++;
// 	}
// 	if (stack->biggest > stack->top / 2)
// 		return (stack->biggest * -1);
// 	else
// 		return (stack->biggest);
// }

void        reset_stack(t_stack_a *stack_a, int pivot)
{
	while (stack_a->a_stack[stack_a->top] != pivot)
		rotate_a(stack_a);
}

// void	sort_opti(t_stack_a *stack_a, t_stack_b *stack_b)
// {
// 	int index;
// 	int index2;

// 	while (stack_a->top != -1)
// 	{
// 		index = find_smallest(stack_a);
// 		index2 = find_biggest(stack_a);
// 		if (absolute_v(index) > absolute_v(index2))
// 		{
// 			print_stack(stack_a, stack_b);
// 			while (stack_a->a_stack[stack_a->top] != stack_a->big)
// 			{
// 				print_stack(stack_a, stack_b);
// 				if (index2 < 0)
// 				{
// 					rotate_a(stack_a);
// 					write(1, "ra\n", 3);
// 				}
// 				else
// 				{
// 					reverse_rotate_a(stack_a);
// 					write(1, "rra\n", 4);
// 				}
// 			}
// 			if (stack_a->a_stack[stack_a->top] > stack_b->b_stack[stack_b->top])
// 			{
// 				write(1, "pb\n", 3);
// 				push_b(stack_b, stack_a);
// 				rotate_b(stack_b);
// 				write(1, "rrb\n", 4);
// 			}
// 			else
// 			{
// 				write(1, "pb\n", 3);
// 				push_b(stack_b, stack_a);
// 			}
// 		}
// 		else
// 		{
// 			while (stack_a->a_stack[stack_a->top] != stack_a->min)
// 			{
// 				print_stack(stack_a, stack_b);
// 				if (index < 0)
// 				{
// 					rotate_a(stack_a);
// 					write(1, "ra\n", 3);
// 				}
// 				else
// 				{
// 					reverse_rotate_a(stack_a);
// 					write(1, "rra\n", 4);
// 				}
// 			}
// 			write(1, "pb\n", 3);
// 			push_b(stack_b, stack_a);
// 		}
// 	}
// }

// void        quick_sort(t_stack_a *stack_a, t_stack_b *stack_b, int low, int high)
// {
//     int index;

//     if (low < high)
//     {
//         index = partition(stack_a, stack_b, low, high);
//         quick_sort(stack_a, stack_b, low, index - 1);
//         quick_sort(stack_a, stack_b, index + 1, high);
//     }
// }

int     is_inlist(t_stack_a *stack, int s[], int old)
{
	int i;

	i = 0;
	write(1, "LIST CHECKER\n", 11);
	while (i < stack->top - 1)
	{
		if (s[i] == old)
			return (0);
		i++;
	}
	return (1);
}


int		find_big_new(t_stack_a *stack, int old, int index, int s[])
{
	int i;

	i = 0;
	while (i <= stack->top)
	{
		if (stack->a_stack[i] < stack->min && is_inlist(stack, s, old))
		{
			stack->big = stack->a_stack[i];
			s[index] = old;
		}
		i++;
	}
	return (0);
}

int		find_biggest(t_stack_a *stack)
{
	int i;
	int index;


	index = 0;
	i = 0;
	stack->big = -2147483647;
	while (i <= stack->top)
	{
		if (stack->a_stack[i] > stack->big)
		{
			stack->big = stack->a_stack[i];
			stack->biggest = i;
		}
		i++;
	}
	if (stack->biggest > stack->top / 2)
		return ((stack->top - stack->biggest) * -1);
	else
		return (stack->biggest);
}


int		find_smallest(t_stack_a *stack)
{
	int i;
	int	half;

	i = 0;
	stack->min = 2147483647;
	half = stack->top / 2;
	while (i <= stack->top)
	{
		if (stack->a_stack[i] < stack->min)
		{
			stack->min = stack->a_stack[i];
			stack->smallest = i;
		}
		i++;
	}
	if (stack->smallest > half)
		return ((stack->top - stack->smallest) * -1);
	else
		return (stack->smallest);
}

int		sortest_path(t_stack_a *stack_a, t_stack_b *stack_b)
{
	int j;
	int i;
	
	i = stack_a->top;
	j = 0;
	while (stack_a->a_stack[i] < stack_b->b_stack[stack_b->top])
		i--;
	while (stack_a->a_stack[j] < stack_b->b_stack[stack_b->top])
		j++;
	i = stack_a->top - i;
	if (i > j)
		return ((j * -1) + 1);
	return (i);
}

int		sortest_way(t_stack_a *stack_a, t_stack_b *stack_b)
{
	int j;
	int i;
	
	(void)stack_b;
	i = stack_a->top;
	j = 0;
	while (stack_a->a_stack[i] != stack_a->min && stack_a->a_stack[i] != stack_a->big && stack_a->a_stack[i] > stack_a->a_stack[i - 1])
		i--;
	while (stack_a->a_stack[j] != stack_a->min && stack_a->a_stack[j] != stack_a->big && stack_a->a_stack[j] > stack_a->a_stack[j + 1])
		j++;
	i = stack_a->top - i;
	if (i > j)
		return (j * -1);
	return (i);
}

void        sort_3(t_stack_a *stack_a, t_stack_b *stack_b)
{
	int     i;
	int		j;

	find_smallest(stack_a);
    find_biggest(stack_a);
	while (!(sort_checker(stack_a, stack_b)))
	{
		if (stack_a->a_stack[stack_a->top] != stack_a->min && stack_a->a_stack[stack_a->top] != stack_a->big && stack_a->a_stack[stack_a->top] > stack_a->a_stack[stack_a->top - 1])
		{
			push_b(stack_b, stack_a);
			write(1, "pb\n", 3);
			// print_stack(stack_a, stack_b);
			// i = sortest_path(stack_a, stack_b);
			i = 0;
			j = i;
			stack_a->key = i;
			if (i < 0)
			{
				while (i < 0)
				{
					// print_stack(stack_a, stack_b);
					reverse_rotate_a(stack_a);
					write(1, "rra\n", 4);
					i++;
				}
			}
			else
			{
				while (stack_a->a_stack[stack_a->top] < stack_b->b_stack[stack_b->top])
				{
					// print_stack(stack_a, stack_b);
					rotate_a(stack_a);
					write(1, "ra\n", 3);
				}
			}
			push_a(stack_a, stack_b);
			write(1, "pa\n", 3);
		}
		j = sortest_way(stack_a,stack_b);
		if (j < 0)
		{
			// print_stack(stack_a, stack_b);
			reverse_rotate_a(stack_a);
			write(1, "rra\n", 4);
		}
		else
		{
			// print_stack(stack_a, stack_b);
			rotate_a(stack_a);
			write(1, "ra\n", 3);
		}
		
	}
	return ;
}

// void	reset(t_stack_a *stack_a, t_stack_b *stack_b)
// {
// 	int index;

// 	while (stack_b->top != -1)
// 	{
// 		index = find_biggest_b(stack_b);
// 		while (stack_b->b_stack[stack_b->top] != stack_b->big)
// 		{
// 			if (index < 0)
// 			{
// 				rotate_b(stack_b);
// 				write(1, "rb\n", 3);
// 			}
// 			else
// 			{
// 				reverse_rotate_b(stack_b);
// 				write(1, "rrb\n", 4);
// 			}
// 			if (stack_b->top == -1)
// 				break ;
// 		}
// 		write(1, "pa\n", 3);
// 		push_a(stack_a, stack_b);
// 		if (stack_b->top == -1)
// 				break ;
// 	}
// }

// void	reset_2(t_stack_a *stack_a, t_stack_b *stack_b)
// {
// 	while (stack_b->top != -1)
// 	{
// 		write(1, "pa\n", 3);
// 		push_a(stack_a, stack_b);
// 	}
// }

// int     main(void)
// {
//     t_stack_a *stack_a;
//     t_stack_b *stack_b;

//     stack_a = init_stack(20);
//     stack_b = init_stack(20);

//     push(stack_a, 30);
//     push(stack_a, 40);
//     push(stack_a, 50);
//     push(stack_a, 5000);
//     push(stack_a, 70);
//     push(stack_a, 100);
//     push(stack_a, 800);
//     push(stack_a, 10);
//     push(stack_a, 90);
//     push(stack_a, 900);
//     push(stack_a, 80);
//     push(stack_a, 400);
//     push(stack_a, 500);
//     push(stack_a, 700);
//     push(stack_a, 8000);
//     push(stack_a, 300);
//     push(stack_a, 9000);
//     push(stack_a, 4000);
//     push(stack_a, 7000);
//     push(stack_a, 3000);
   
//     // quick_sort(stack_a, stack_b, 0, stack_a->top);
//     sort_3(stack_a, stack_b);
//     // reset(stack_a, stack_b);
//     // print_stack(stack_a, stack_b);
//     // print_stack(stack_a, stack_b);
//     // printf("%d and %d\n", stack_a->a_stack[0], stack_a->a_stack[5]);
//     // swap_nbr(stack_a, stack_b, 3, 5);
//     // print_stack(stack_a, stack_b);
//     // printf("%d and %d\n",stack_a->a_stack[2], stack_a->a_stack[7]);
//     // swap_nbr(stack_a, stack_b, 2, 7);
//     // swap_nbr(stack_a, stack_b, 2, 7);
//     // swap_nbr(stack_a, stack_b, 4, 9);
//     // reset_stack(stack_a, 700);
//     // print_stack(stack_a, stack_b);
//     return 0;
// }