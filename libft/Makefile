

SRCS		= 	ft_calloc.c \
				ft_isdigit.c \
				ft_memchr.c \
				ft_memset.c \
				ft_strchr.c \
				ft_strjoin.c \
				ft_strncat.c \
				ft_strrchr.c \
				ft_tolower.c \
				ft_isalnum.c \
				ft_isprint.c \
				ft_memcmp.c \
				ft_putstr_fd.c \
				ft_strcmp.c \
				ft_strlcat.c \
				ft_strncmp.c \
				ft_strstr.c \
				ft_toupper.c \
				ft_atoi.c \
				ft_isalpha.c \
				ft_itoa.c \
				ft_memcpy.c \
				ft_putchar_fd.c \
				ft_strcpy.c \
				ft_strlcpy.c \
				ft_strncpy.c \
				ft_strtrim.c \
				ft_bzero.c \
				ft_isascii.c \
				ft_memccpy.c \
				ft_memmove.c \
				ft_strcat.c \
				ft_strdup.c \
				ft_strlen.c \
				ft_strnstr.c \
				ft_substr.c \
				ft_strmapi.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_split.c \


OBJS		= $(SRCS:%.c=%.o)

BONUSOBJ	= ${BONUS:%.c=%.o} $(OBJS)

CFLAGS 		= -Werror -Wextra -Wall

NAME		= libft.a

BONUS		= 	ft_lstadd_front.c \
				ft_lstlast.c \
				ft_lstnew.c \
				ft_lstsize.c \
				ft_lstadd_back.c \
				ft_lstdelone.c \
				ft_lstiter.c \
				ft_lstmap.c \
				ft_lstclear.c \


CC 			= gcc

HEAD		= libft.h


all 	:
		@make $(NAME)


$(NAME)	: $(OBJS)
		@ar rc $(NAME) $(OBJS)
		@ranlib $(NAME)

bonuslib :$(BONUSOBJ)
		@ar rc $(NAME) $(BONUSOB)
		@ranlib $(NAME)	

bonus :
		@make bonuslib

%.o 	: %.c
		$(CC) $(CFLAGS) -I$(HEAD) -o $@ -c $<

clean	:
		@rm -rf $(OBJS) $(BONUSOBJ)

fclean	:
		@make clean
		@rm -f $(NAME)

re		:
		@make fclean
		@make $(NAME)
