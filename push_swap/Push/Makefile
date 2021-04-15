# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwane <mwane@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/11 19:08:29 by truepath          #+#    #+#              #
#    Updated: 2021/04/15 16:04:11 by mwane            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 		= 		srcs/check_sort.c \
					srcs/operation.c \
					srcs/operation_2.c \
					srcs/stack.c \
					srcs/ft_split.c \
					srcs/get_next_line.c \
					srcs/get_next_line_utils.c \
					srcs/stack_2.c \

CHECKER 	=		main/checker.c

PUSH_SWAP 	= 		main/push_swap.c

HEAD		=		checker.h

CFLAGS 		= 		-Werror -Wextra -Wall

all 		:
					make push_swap
					make checker

push_swap 	:
					gcc $(CFLAGS) $(SRCS) $(PUSH_SWAP) libft2/libft.a -o push_swap

checker 	:			
					gcc $(CFLAGS) $(SRCS) $(CHECKER) libft2/libft.a -o checker

clean		:
					rm -f push_swap checker

re			:
					rm -f push_swap checker
					make
