##
## Makefile for makefile in /home/menet/Bootstrap/PSU_2015_minishell1
## 
## Made by menett_a
## Login   <menett_a@epitech.net>
## 
## Started on  Mon Jan 18 16:43:44 2016 menett_a
## Last update Sun Jan 24 23:35:39 2016 menett_a
##

NAME	=	mysh

SRC	=	get_next_line.c		\
		my_path_copy.c		\
		my_unsetenv.c		\
		str_to_word.c		\
		minishell.c		\
		stock_env.c		\
		my_strlen.c		\
		my_getnbr.c		\
		my_status.c		\
		my_strcmp.c		\
		my_test.c		\
		my_exit.c		\
		my_free.c		\
		setenv.c		\
		my_cd.c			\
		path.c			\
		main.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Werror -ansi -pedantic

LIB	=	-Lmy_printf/lib -lmy

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C ./my_printf/
		gcc -o $(NAME) $(OBJ) $(LIB)

clean:
		make clean -C ./my_printf/
		rm -rf $(OBJ)

fclean:		clean
		make fclean -C ./my_printf/
		rm -rf $(NAME)

re:		fclean all
		make re -C ./my_printf/

.PHONY:		all clean fclean re
