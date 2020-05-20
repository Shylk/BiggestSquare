##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile
##

SRC	=	bsq.c			\
		get_size.c		\
		my_int_to_str.c		\
		malloc.c		\
		load_files_into_array.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	bsq

CFLAGS	=	-Iinclude -L lib/my/ -lmy

all:	$(NAME)

$(NAME):	$(OBJ)
	cd lib/my/ && make
	gcc -o $(NAME) $(SRC) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
