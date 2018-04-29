# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/11 13:59:37 by pierre            #+#    #+#              #
#    Updated: 2018/04/29 04:14:16 by pleroux          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DBG=-ggdb -fsanitize=address -fno-omit-frame-pointer -g3
DBG2=-ggdb  -fsanitize=address -fsanitize-memory-track-origins

NAME= pleroux.filler
CC=gcc
LIB= libft/libft.a
LIB_PATH = libft/
CFLAGS= -Ilibft/includes -Wall -Werror -Wextra
LIB_FLAGS= -L$(LIB_PATH) -lft
SRC_DIR = src/
SRC_FILE = main.c \
		   analyse.c \
		   analyse_position.c \
		   parser.c \
		   init.c
SRC = $(addprefix $(SRC_DIR), $(SRC_FILE))
OBJ = $(SRC:.c=.o)

all		: $(LIB) $(NAME)

$(LIB)	:
	make -C $(LIB_PATH)

$(NAME)	: $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LIB_FLAGS)

clean	:
	rm -f $(OBJ)
	make -C libft/ fclean

fclean	: clean
	rm -f $(NAME)

re		: clean all

.PHONY : all clean re fclean BUILD $(LIB)
