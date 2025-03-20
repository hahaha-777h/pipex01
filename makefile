# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhikita <hhikita@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/04 15:44:57 by hhikita           #+#    #+#              #
#    Updated: 2025/03/20 16:53:01 by hhikita          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= cc
CFLAGS = -Wall -Wextra -Werror


NAME	= pipex


SRCS = src/main.c	src/str_utils.c		src/init.c  src/env_and_args.c \
		src/execute.c gnl/gnl.c	gnl/gnl_utils.c	src/close_and_dup.c	src/cleanup.c \
		

LIBFT = libft/libft.a

OBJ_DIR = ./obj
OBJS    = $(SRCS:src/%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o:	src/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(LIBFT):
	make -C libft

clean:
	rm -rf $(OBJ_DIR) 
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all
