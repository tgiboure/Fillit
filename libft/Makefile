# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: jfeve <marvin@le-101.fr>                   +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/11/29 22:03:55 by jfeve        #+#   ##    ##    #+#        #
#    Updated: 2017/11/29 22:03:55 by jfeve       ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY = clean fclean re

NAME = libft.a

FLAGS = -Wall -Werror -Wextra

HEADERS = libft.h

FILES = ft_putchar_fd.c ft_putchar.c ft_putstr_fd.c ft_putstr.c ft_putendl_fd.c \
		ft_putendl.c ft_putnbr_fd.c ft_putnbr.c ft_strlen.c ft_atoi.c \
		ft_tolower.c ft_toupper.c ft_isprint.c ft_isascii.c ft_isalnum.c ft_isdigit.c \
		ft_isalpha.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_strcat.c \
		ft_strncat.c ft_strchr.c ft_strrchr.c ft_strcpy.c ft_strncpy.c ft_strdup.c \
		ft_memset.c ft_memalloc.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_strlcat.c \
		ft_memchr.c ft_memcmp.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c \
		ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c \
		ft_strsub.c ft_strjoin.c ft_strtrim.c ft_memmove.c ft_strsplit.c ft_itoa.c \
		ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c \
		ft_swap.c ft_isspace.c ft_putstr2d.c ft_putstr2d_fd.c ft_countdigits.c \
		ft_print_error.c

OBJ = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: $(SRCS)%.c
	gcc $(FLAGS) -c $(SRCS)$*.c

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
