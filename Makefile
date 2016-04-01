# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbaran <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/17 18:36:39 by rbaran            #+#    #+#              #
#    Updated: 2016/04/01 12:54:08 by rbaran           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc
LIB = libft.a
LIBDIR = ./libft/
FLAGS = -Wall -Werror -Wextra
LFLAGS = -I./inc/
LLIBFLAGS = -I./libft/includes/
LDFLAGS = -L./libft/ -lft
SRCS = ./srcs/ft_error.c ./srcs/ft_open.c ./srcs/ft_print.c ./srcs/ft_read.c \
	./srcs/ft_tetri.c ./srcs/main.c ./srcs/ft_map.c ./srcs/ft_bits.c \
	./srcs/ft_math.c
OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(LIB):
	@make -C libft/
	@printf 'Lib compilation: DONE\n'

$(NAME): $(LIB) $(OBJ)
	@$(CC) $(FLAGS) -o $@ $(OBJ) $(LDFLAGS)
	@printf 'Fillit compilation: DONE\n'

%.o: %.c
	@$(CC) $(FLAGS) -o $@ -c $< $(LFLAGS) $(LLIBFLAGS)


clean:
	@/bin/rm -f $(OBJ)
	@make -C $(LIBDIR) clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C $(LIBDIR) fclean

re: fclean all

.PHONY: clean fclean re
