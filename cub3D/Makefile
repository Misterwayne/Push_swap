# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwane <mwane@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/22 14:13:58 by mwane             #+#    #+#              #
#    Updated: 2020/02/22 14:30:14 by mwane            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3D

SRC			= srcs/*.c

SRC2 		= gnl/*.c

CC 			= gcc

HEAD 		= cub3d.h

CFLAGS 		= -Werror -Wextra -Wall -lmlx -framework OpenGL -framework AppKit libft.a

RM 			= rm -f

BMP 		= cub3D.bmp

BUFFER 		= -D BUFFER_SIZE=10

SAVE 		= -save

MAP 		= map.cub

all:
	make $(NAME)

$(NAME)	: 
		@$(CC) $(CFLAGS) $(SRC) $(SRC2) $(BUFFER) -o $(NAME)

run		: $(NAME)
		./$(NAME) $(MAP)

save	:
		./$(NAME) $(MAP) -save
bonus:
	  @make $(NAME)

clean:
	@rm -f $(BMP)

fclean:
	@make clean
	@rm -f $(NAME)

re:
	@make fclean
	@make $(NAME)