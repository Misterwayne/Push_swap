# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwane <mwane@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/08 17:39:45 by mwane             #+#    #+#              #
#    Updated: 2019/10/08 17:39:46 by mwane            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC 		= gcc -Wall -Werror -Wextra
SRCS 	= ${wildcard *.c}
OBJS 	= ${SRCS:.c=.o}
HEADERS = ./includes
RM		= rm -f
NAME	= libft.a

all		 	:	${NAME} 

${NAME} 	:	${OBJS}
					ar -r ${NAME} ${OBJS}
					ranlib ${NAME}
					${RM} ${OBJS}

${OBJS} 		: 	${SRCS}
					${CC} -c  ${SRCS} 

clean		:
					${RM} ${OBJS}

fclean		:	clean
					${RM} ${NAME}

re			:	fclean all
