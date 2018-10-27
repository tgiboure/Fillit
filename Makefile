# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: jfeve <marvin@le-101.fr>                   +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/11/29 22:03:55 by jfeve        #+#   ##    ##    #+#        #
#    Updated: 2017/11/30 17:39:38 by jfeve       ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #
NAME = fillit

SRC = files/check_size.c\
	files/check_place_letter.c\
	files/set_up_left.c\
	files/main.c\
	files/coordonee.c\
	files/init_out.c\
	files/solver.c

FLAGS = -Wall -Werror -Wextra
LIB = ./libft/
LIBFT = $(addprefix $(LIB),libft.a)

all: $(NAME)

$(NAME): libft
	gcc $(FLAGS) -I ./ -I ./libft/ $(SRC) $(LIBFT) -o $(NAME)

libft:
	make -C $(LIB)

clean:
	make clean -C $(LIB)
	rm -rf $(OBJ)

fclean: clean
	make fclean -C $(LIB)
	rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, libft
