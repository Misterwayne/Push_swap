/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:51:20 by mwane             #+#    #+#             */
/*   Updated: 2021/04/21 18:28:07 by mwane            ###   ########.fr       */
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
    int tmp;
    int save;
    int tmp2;

    if (i == j)
        return ;
    index = 0;
    tmp = stack_a->a_stack[j];
    tmp2 = stack_a->a_stack[i];
    printf("%d != %d\n", stack_a->a_stack[stack_a->top], tmp);
    while (stack_a->a_stack[stack_a->top] != tmp)
    {
        print_stack(stack_a, stack_b);
        write(1, "raa\n", 4);
        reverse_rotate_a(stack_a);
        printf("%d != %d\n", stack_a->a_stack[stack_a->top], tmp);
    }
    push_b(stack_b, stack_a);
    while (stack_a->a_stack[stack_a->top] != tmp2)
    {
        print_stack(stack_a, stack_b);
        write(1, "raa\n", 4);
        reverse_rotate_a(stack_a);
        index++;
        printf("%d != %d\n", stack_a->a_stack[stack_a->top], tmp2);
    }
    push_b(stack_b, stack_a);
    write(1, "sb\n", 3);
    swap_b(stack_b);
    write(1, "pa\n", 3);
    push_a(stack_a, stack_b);
    while (index > 0)
    {
        print_stack(stack_a, stack_b);
        write(1, "ra\n", 4);
        rotate_a(stack_a);
        index--;
    }
    write(1, "pa\n", 3);
    push_a(stack_a, stack_b);
    
}


int        partition(t_stack_a *stack_a, t_stack_b *stack_b, int low, int high)
{
    int     tmp;
    int     tmp2;
    int     pivot;
    int     i;
    int     j;
    int     index;

    pivot = stack_a->a_stack[high];
    i = (low - 1);
    index = 0;
    for(j = low; j <= high - 1; j++)
    {
        if (stack_a->a_stack[j] <= pivot)
        {
            i++;
            swap(&stack_a->a_stack[j], &stack_a->a_stack[i]);
            // swap_nbr(stack_a, stack_b, i, j);
            // reset_stack(stack_a, pivot);
        }
    }
    swap(&stack_a->a_stack[i + 1], &stack_a->a_stack[high]);
    // swap_nbr(stack_a, stack_b, i + 1, high);
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

int     main(void)
{
    t_stack_a *stack_a;
    t_stack_b *stack_b;

    stack_a = init_stack(20);
    stack_b = init_stack(20);

    push(stack_a, 10);
    push(stack_a, 80);
    push(stack_a, 30);
    push(stack_a, 90);
    push(stack_a, 40);
    push(stack_a, 50);
    push(stack_a, 70);
   
    // print_stack(stack_a, stack_b);
    quick_sort(stack_a, stack_b, 0, 6);
    // swap_nbr(stack_a, stack_b, 1, 5);
    // reset_stack(stack_a, 70);
    print_stack(stack_a, stack_b);
    return 0;
}