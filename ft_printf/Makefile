# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwane <mwane@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/21 17:46:15 by mwane             #+#    #+#              #
#    Updated: 2019/11/23 16:38:07 by mwane            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c ft_printf_utils.c ft_printf_util2.c ft_printf_util3.c ft_printf_util4.c

OBJS = $(SRC:%.c=%.o)

CC 	= gcc

HEAD	= ft_printf.h

CFLAGS 	= -Werror -Wextra -Wall

RM = rm -f

all:
	make $(NAME)

$(NAME)	: $(OBJS)
		@ar rc $(NAME) $(OBJS)
		@ranlib $(NAME)
		@echo "libftprintf.a DONE"

%.o : %.c
		 $(CC) $(CFLAGS) -I$(HEAD) -o $@ -c $<

clean:
	@rm -rf $(OBJS)
##	@echo "Removing object file."

fclean:
	@make clean
	@rm -f $(NAME)
##	@echo "${COLOR_RED}Removing bineries"

re:
	@make fclean
##	@echo "${COLOR_BLUE}Compiling :${COLOR_WHITE}"
	@make $(NAME)