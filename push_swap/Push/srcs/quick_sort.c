/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:51:20 by mwane             #+#    #+#             */
/*   Updated: 2021/04/30 17:14:08 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../header/checker.h"

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

void        reset_stack(t_stack_a *stack_a, int pivot)
{
    while (stack_a->a_stack[stack_a->top] != pivot)
        rotate_a(stack_a);
}

void        swap_nbr(t_stack_a *stack_a, t_stack_b *stack_b, int i, int j)
{
    int index;
    int index2;
    int tmp;
    int tmp2;

    if (i == j)
        return ;
    if (i > j)
        swap(&i ,&j);
    stack_a->big = j;
    stack_a->min = i;
    index = j - i;
    tmp = stack_a->a_stack[j];
    tmp2 = stack_a->a_stack[i];
    (void)stack_b;
    while (stack_a->a_stack[stack_a->top] != tmp2)
    {
        // print_stack(stack_a, stack_b);
        write(1, "ra\n", 3);
        rotate_a(stack_a);
    }
    index2 = stack_a->a_stack[stack_a->top - 1];
    push_b(stack_b, stack_a);
    write(1, "pb\n", 3);
    while (stack_a->a_stack[0] != tmp)
    {
        // swap_a(stack_a);
        // write(1, "sa\n", 3);
        // print_stack(stack_a, stack_b);
        rotate_a(stack_a);
        write(1, "ra\n", 3);
    }
    push_a(stack_a, stack_b);
    write(1, "pa\n", 3);
    reverse_rotate_a(stack_a);
    write(1, "rra\n", 4);
    push_b(stack_b, stack_a);
    write(1, "pb\n", 3);
    // print_stack(stack_a, stack_b);
    // printf("%d\n",index2);
    while (stack_a->a_stack[stack_a->top] != index2)
    {
        // print_stack(stack_a, stack_b);
        rotate_a(stack_a);
        write(1, "ra\n", 3);
    }
    rotate_a(stack_a);
    write(1, "pb\n", 3);
    push_a(stack_a, stack_b);
    while (stack_a->a_stack[i] != tmp && stack_a->a_stack[j] != tmp2)
    {
        // print_stack(stack_a, stack_b);
        rotate_a(stack_a);
        write(1, "ra\n", 3);
    }
}


int        partition(t_stack_a *stack_a, t_stack_b *stack_b, int low, int high)
{
    int     pivot;
    int     i;
    int     j;
    int     index;

    pivot = stack_a->a_stack[high];
    i = (low - 1);
    index = 0;
    j = low;
    while (j <= high - 1)
    {
        if (stack_a->a_stack[j] <= pivot)
        {
            i++;
            swap_nbr(stack_a, stack_b, i, j);
        }
        j++;
    }
    swap_nbr(stack_a, stack_b, i + 1, high);
    return (i + 1);
}

void        quick_sort(t_stack_a *stack_a, t_stack_b *stack_b, int low, int high)
{
    int index;

    if (low < high)
    {
        index = partition(stack_a, stack_b, low, high);
        quick_sort(stack_a, stack_b, low, index - 1);
        quick_sort(stack_a, stack_b, index + 1, high);
    }
}

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

void        sort_3(t_stack_a *stack_a, t_stack_b *stack_b)
{
    int     i;
    int     index;
    int     index2;
    int     s[stack_a->top];

    i = (stack_a->top / 2) + 1;
    index = 0;
    while (i > 0)
    // while (!(sort_checker(stack_a, stack_b)))
    {
        index = find_smallest(stack_a);
		index2 = find_biggest(stack_a);
        // print_stack(stack_a, stack_b);
			while (stack_a->a_stack[stack_a->top] != stack_a->min)
			{
				// print_stack(stack_a, stack_b);
				if (index < 0)
				{
					rotate_a(stack_a);
					write(1, "ra\n", 3);
				}
				else
				{
					reverse_rotate_a(stack_a);
					write(1, "rra\n", 4);
				}
            }
        // find_biggest(stack_a);
        // index = find_smallest(stack_a);
        if (stack_a->min == stack_a->a_stack[stack_a->top] && i > 0)
        {
            push_b(stack_b, stack_a);
            write(1, "pb\n", 3);
            i--;
        }
        // rotate_a(stack_a);
        // write(1, "ra\n", 3);
    }
    find_biggest(stack_a);
    while (!(sort_checker(stack_a, stack_b)))
    {
        // print_stack(stack_a, stack_b);
        if (stack_a->a_stack[stack_a->top] > stack_a->a_stack[stack_a->top - 1] && stack_a->a_stack[stack_a->top] != stack_a->big)
        {
            // reverse_rotate_a(stack_a);
            // printf("SWAP\n");
            swap_a(stack_a);
            write(1, "sa\n", 3);
            find_big_new(stack_a, stack_a->big, index, s);
            index++;
            // stack_a->big = stack_a->a_stack[stack_a->top];
        }
        rotate_a(stack_a);
        // find_smallest_new(stack_a, stack_a->min);
        write(1, "ra\n", 3);
        // printf("%d\n",stack_a->big);
    }
    return ;
}

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

//     push(stack_a, 10);
//     push(stack_a, 30);
//     push(stack_a, 80);
//     push(stack_a, 90);
//     push(stack_a, 40);
//     push(stack_a, 50);
//     push(stack_a, 70);
//     push(stack_a, 100);
//     push(stack_a, 800);
//     push(stack_a, 300);
//     push(stack_a, 900);
//     push(stack_a, 400);
//     push(stack_a, 500);
//     push(stack_a, 700);
//     push(stack_a, 8000);
//     push(stack_a, 3000);
//     push(stack_a, 9000);
//     push(stack_a, 4000);
//     push(stack_a, 5000);
//     push(stack_a, 7000);
//     push(stack_a, -800);
//     push(stack_a, -300);
//     push(stack_a, -900);
//     push(stack_a, -400);
//     push(stack_a, -500);
//     push(stack_a, -700);
   
//     // quick_sort(stack_a, stack_b, 0, stack_a->top);
//     sort_3(stack_a, stack_b);
//     reset_2(stack_a, stack_b);
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
//     print_stack(stack_a, stack_b);
//     return 0;
// }