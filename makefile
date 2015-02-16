NAME		=	sortalg

DIR_INCLUDE	=	./headers/

DIR_SRC		=	./src/

CC		=	gcc

CFLAGS		=	-I$(DIR_INCLUDE) #-Wall -Wextra -ansi -pedantic -ansi -O2 -Wchar-subscripts -Wcomment -Wformat=2 -Wimplicit-int -Werror-implicit-function-declaration \
			-Wmain -Wparentheses -Wsequence-point -Wreturn-type -Wswitch -Wtrigraphs -Wunused -Wuninitialized -Wunknown-pragmas -Wfloat-equal -Wundef \
			-Wshadow -Wpointer-arith -Wbad-function-cast -Wwrite-strings -Wconversion -Wsign-compare -Waggregate-return -Wstrict-prototypes \
			-Wmissing-prototypes -Wmissing-declarations -Wmissing-noreturn -Wformat -Wmissing-format-attribute -Wno-deprecated-declarations \
			-Wpacked -Wredundant-decls -Wnested-externs -Winline -Wlong-long -Wunreachable-code

SRC		=	$(DIR_SRC)main.c \
			$(DIR_SRC)words.c

OBJ		=	$(SRC:.c=.o)

RM		=	rm -rf

$(NAME)		:	$(OBJ)
			$(CC) -o $@ $(OBJ)

all		:	$(NAME)

clean		:
			$(RM) $(OBJ) *~

fclean		:	clean
			$(RM) $(NAME)

re		:	fclean all
