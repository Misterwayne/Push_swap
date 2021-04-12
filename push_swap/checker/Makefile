# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: truepath <truepath@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/11 19:08:29 by truepath          #+#    #+#              #
#    Updated: 2021/04/11 20:48:01 by truepath         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 		= 		check_sort.c \
					operation.c \
					operation_2.c \
					stack.c \
					ft_split.c \
					get_next_line.c \
					get_next_line_utils.c

CHECKER 	=		checker.c

PUSH_SWAP 	= 		push_swap.c

HEAD		=		checker.h

CFLAGS 		= 		-Werror -Wextra -Wall

all 		:
					make push_swap
					make checker

push_swap 	:
					gcc $(CFLAGS) $(SRCS) $(PUSH_SWAP) -o push_swap

checker 	:			
					gcc $(CFLAGS) $(SRCS) $(CHECKER) -o checker

re			:
			rm -f push_swap checker
			make
# run			: push_swap checker
# 					./push_swap $ARG | ./checker $ARG
