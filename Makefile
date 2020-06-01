##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC = 	$(wildcard SRC/*.c)

OBJ =	$(SRC:.c=.o)

NAME =	my_runner

CFLAGS =	-Iinclude -g3

all: 	$(OBJ)
	make -C ./lib/my
	gcc -l csfml-graphics -l csfml-audio -l csfml-system -l csfml-window -o $(NAME) $(OBJ) -L./lib/my -lmy

clean:
	rm -f $(OBJ)

fclean: clean
	make fclean -C ./lib/my
	rm -f lib/libmy.a
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re