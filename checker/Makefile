##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC = 	main.hs

NAME = pushswap_checker

all: $(NAME)

$(NAME):
	ghc -o $(NAME) $(SRC)

clean:
	find . -name "*.o" -delete
	find . -name "*.hi" -delete

fclean:    clean
	rm -f $(NAME)

re:        fclean all
