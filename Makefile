##
## EPITECH PROJECT, 2021
## B-CPE-110-LIL-1-1-pushswap-noa.trachez
## File description:
## Makefile
##

all	:	make_all

make_all	:
	make -C pushswap
	make -C checker
	cp pushswap/push_swap .
	cp checker/pushswap_checker .

clean	:
	make clean -C pushswap
	make clean -C checker

fclean	:	clean
	make fclean -C pushswap
	make fclean -C checker
	rm -f push_swap
	rm -f pushswap_checker

re	:	fclean all