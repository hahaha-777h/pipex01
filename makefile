# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhikita <hhikita@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/04 15:44:57 by hhikita           #+#    #+#              #
#    Updated: 2025/03/11 19:12:50 by hhikita          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= cc
CFLAGS = -Wall -Wextra -Werror


NAME	= pipex


SRCS = src/main.c	src/utils/str_utils.c		src/utils/split.c		src/init.c  \
		gnl/gnl.c	gnl/gnl_utils.c

OBJ_DIR = ./obj
OBJS    = $(SRCS:src/%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o:	src/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	make -C libft


clean:
	rm -rf $(OBJ_DIR) 
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all
