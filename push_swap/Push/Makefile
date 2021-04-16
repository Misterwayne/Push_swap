# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwane <mwane@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/11 19:08:29 by truepath          #+#    #+#              #
#    Updated: 2021/04/16 16:04:34 by mwane            ###   ########.fr        #
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
					srcs/check_sort_2.c \

OBJS		= 		$(SRCS:%.c=%.o)

CHECKER 	=		main/checker.c

PUSH_SWAP 	= 		main/push_swap.c

NAME_PUSH	=		push_swap

NAME_CHECK	=		checker

LIB			=		libft2/.

HEAD		=		checker.h

CFLAGS 		= 		-Werror -Wextra -Wall

CC 			= 		gcc

RM			=		rm -f

all 		:
					@make libft
					@make push_swap
					@make checker

push_swap 	:
					$(CC) $(CFLAGS) $(SRCS) $(PUSH_SWAP) libft2/libft.a -o push_swap

libft		:
					@make -C $(LIB)

checker 	:			
					$(CC) $(CFLAGS) $(SRCS) $(CHECKER) libft2/libft.a -o checker

clean		:
					@$(RM) $(NAME_PUSH) $(NAME_CHECK)
					@make -C $(LIB) clean

re			:
					@make clean
					@make

.PHONY		:		all $(LIB)
