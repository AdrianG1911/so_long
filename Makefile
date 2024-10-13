# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adrgutie <adrgutie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/08 17:51:00 by adrgutie          #+#    #+#              #
#    Updated: 2024/10/08 20:58:44 by adrgutie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
LDFLAGS		= -Llibft -Lminilibx-linux
LDLIBS		= -lft -lmlx_Linux -lm -lXext -lX11
RM			= rm -fr
OBJ_DIR		= obj

SRCS		= src/so_long.c \
			  src/free_stuff.c \
			  src/make_and_count_map.c \
			  src/init_game.c \
			  src/map_checker.c \
			  src/map_completable_check.c

OBJS		= $(SRCS:src/%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	make -C minilibx-linux
	make -C libft
	$(CC) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJ_DIR)
	make clean -C libft
	make clean -C minilibx-linux

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft

re: fclean all

.PHONY : all clean fclean re
