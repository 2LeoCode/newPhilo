# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/24 21:18:33 by Leo Suardi        #+#    #+#              #
#    Updated: 2021/09/24 21:51:05 by Leo Suardi       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL=bash

NAME=philo

SRCD=src
INCD=inc
OBJD=.obj

SRC=$(wildcard $(SRCD)/*.c)
INC=$(wildcard $(INCD)/*.h)
OBJ=$(patsubst $(SRCD)/%.c, $(OBJD)/%.o, $(SRC))

CC=clang
CFLAGS=-Wall -Wextra -Werror -I $(INCD)
LCFLAGS=-lpthread

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ $(LCFLAGS)

$(OBJD)/%.o: $(SRCD)/%.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
