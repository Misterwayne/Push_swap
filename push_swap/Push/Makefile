# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: truepath <truepath@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/11 19:08:29 by truepath          #+#    #+#              #
#    Updated: 2021/10/19 00:11:07 by truepath         ###   ########.fr        #
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
					srcs/quick_sort.c \
					srcs/ft_atoi.c \
					srcs/ft_strcmp.c \
					srcs/chunk_sort.c \
					srcs/small_sort.c \
					srcs/sort_5.c \
					srcs/tools.c \
					srcs/set_up.c \
					srcs/more_tools.c

OBJS		= 		$(SRCS:%.c=%.o)

CHECKER 	=		main/checker.c

PUSH_SWAP 	= 		main/push_swap.c

NAME_PUSH	=		push_swap

NAME_CHECK	=		checker

HEAD		=		checker.h

CFLAGS 		= 		-Werror -Wextra -Wall

CC 			= 		gcc

RM			=		rm -f

all 		:		$(NAME_PUSH)
					

push_swap 	:		$(OBJS)
					$(CC) $(CFLAGS) $(SRCS) $(PUSH_SWAP)  -o $(NAME_PUSH)

bonus	 	:		$(NAME_CHECK)

$(NAME_CHECK):
					$(CC) $(CFLAGS) $(SRCS) $(CHECKER)  -o $(NAME_CHECK)

clean		:
					@$(RM) $(NAME_PUSH) $(OBJS)

re			:
					@make clean
					@make

.PHONY		:		all
