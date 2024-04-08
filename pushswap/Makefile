##
## EPITECH PROJECT, 2021
## B-CPE-110-LIL-1-1-pushswap-noa.trachez
## File description:
## Makefile
##

SRC	=	pushswap.c\
		my_lib.c\
		sorting.c\
		linked_list.c

OBJ	=	$(SRC:.c=.o)

NAME	=	push_swap

all	:	$(NAME)

$(NAME)	:	$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean	:
	rm -f $(OBJ)

fclean	:	clean
	rm -f $(NAME)

re	:	fclean all