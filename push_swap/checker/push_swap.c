/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:35:51 by mwane             #+#    #+#             */
/*   Updated: 2021/04/09 17:33:23 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"
#include"checker.h"

void    check_args(int argc, char **args, s_stack_a *stack);

void        inserton_sort(s_stack_a *stack_a, s_stack_b *stack_b)
{
	// for small dataset
	
	/*
	1) We start by making the second element of the given array, i.e. element at index 1, the key. The key element here is the new card that we need to add to our existing sorted set of cards(remember the example with cards above).
	
	2) We compare the key element with the element(s) before it, in this case, element at index 0:
	If the key element is less than the first element, we insert the key element before the first element.
	If the key element is greater than the first element, then we insert it after the first element.
	
	3) Then, we make the third element of the array as key and will compare it with elements to it's left and insert it at the right position.
	
	4) And we go on repeating this, until the array is sorted.
	*/

   int      i;
   int      key;
   int      j;

   i = 1;
   write(1, "ra\n", 3);
   while (i < stack_a->top + 1)
   {
	  	j = i;
		write(1, "pb\n", 3);
	   	while (j > 0 && stack_a->a_stack[j - 1] > stack_a->a_stack[j])
		{
			key = stack_a->a_stack[j];
			stack_a->a_stack[j] = stack_a->a_stack[j - 1];
			stack_a->a_stack[j - 1] = key;
			j--;
		}
	   i++;
   }
}

int		main(int argc, char **argv)
{
	s_stack_a	*stack;
	s_stack_b	*stack_b;

	stack = init_stack(argc);
	check_args(argc, argv + 1, stack);
	inserton_sort(stack, NULL);
	print_stack(stack, NULL);
	return (0);
}

// void        quick_