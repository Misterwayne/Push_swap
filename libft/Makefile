## nom du produit
NAME = libft.a

## liste des dossiers d'includes
## cherche tous les includes de type dossier
INC_DIR = 	$(shell find includes -type d)

## liste des dossiers de sources
## cherche tous les sources de type dossier
SRC_DIR = 	$(shell find srcs -type d)

## dossier contenant les .o
OBJ_DIR	=	obj

## chemin virtuel amenant aux .c
vpath %.c $(foreach dir, $(SRC_DIR), $(dir):)

## liste des .c sans leur path recursivement
SRC = $(foreach dir, $(SRC_DIR), $(foreach file, $(wildcard $(dir)/*.c), $(notdir $(file))))

## remplace '.c' par '.o' dans $(SRC)
TMP_OBJ = $(SRC:%.c=%.o)

## ajoute le path a chaque element de $(TMP_OBJ)
OBJ = $(addprefix $(OBJ_DIR)/, $(TMP_OBJ))

## path menant a des librairies (utile qd plusieurs libs)
LIB_PATH = libft

## nom des libs a linker (NE PAS METTRE 'lib')
LIBS = ft.a

## liste des flags de compilation
CFLAGS = -Werror -Wextra -Wall

## liste des flags d'include
IFLAGS = $(foreach dir, $(INC_DIR),-I$(dir) )

## liste des flags de librairies
LFLAGS = $(foreach dir, $(LIB_PATH),-L$(dir) ) $(foreach lib, $(LIBS),-l$(lib) )

## programme de compilation
CC = gcc

## liste de couleurs pour personnaliser sa mere
COLOR_GREY = \033[0;30m
COLOR_RED = \033[0;31m
COLOR_GREEN = \033[0;32m
COLOR_YELLOW = \033[0;33m
COLOR_WHITE = \033[0m
COLOR_GREEN = \033[0;32m
COLOR_CYAN = \033[0;36m
COLOR_BLUE = \033[0;34m

##couleur de background
IGREY = \033[0;40m
IRED = \033[0;41m
IGREEN = \033[0;42m
IYELLOW = \033[0;43m
IBLUE = \033[0;44m
IPURPLE = \033[0;45m
ICYAN = \033[0;46m
IWHITE = \033[0;47m

## style d'ecriture

## porte du garage
all:
	make $(NAME)

## permet dacceder a un autre makefile
##	make -C yolo_folder

## print les alias
show:
	@echo "SRC_DIR : $(SRC_DIR)"
	@echo "IFLAGS : $(IFLAGS)"
	@echo "CFLAGS : $(CFLAGS)"
	@echo "LFLAGS : $(LFLAGS)"
	@echo "SRC : "
	@echo $(foreach src, $(SRC), $(src))
	@echo "OBJ : "
	@echo $(foreach obj, $(OBJ), $(obj))

## regle de compilation du produit
$(NAME): $(OBJ)
	@echo "${IBLUE}Compiling $(COLOR_CYAN)$(NAME)$(COLOR_WHITE) ... \c"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(COLOR_GREEN)DONE$(COLOR_WHITE)"

## cherche dans le OBJDIR le .o, si pb, elle va chercher le .c correspondant grace a vpath et le compile
$(OBJ_DIR)/%.o : %.c
	@mkdir -p $(OBJ_DIR)
## \c evite les retours chariot(s)
	@echo "${IBLUE}Compiling $(COLOR_CYAN)$*$(COLOR_WHITE) ... \c"
## compile avec les flags (-o = --object / $@ = destination -> nom de la regle appellee 
## -c = sources a compiler / $< = dependance, ce qui est envoye)
	@$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $<
	@echo "$(COLOR_GREEN)シ$(COLOR_WHITE)"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "clean"

fclean:
	@make clean
	@rm -f $(NAME)
	@echo "fclean"

re:
	@make fclean
	@make $(NAME)

## si un fichier/dossier a le meme nom, donne priorite a la regle du makefile
.PHONY: all clean fclean re show