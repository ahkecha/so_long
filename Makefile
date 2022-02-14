# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahkecha <ahkecha@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/12 12:08:25 by ahkecha           #+#    #+#              #
#    Updated: 2022/02/14 17:27:47 by ahkecha          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
LIBFT = libft
INCLUDE = so_long.h libft/libft.h
LIB = libft/libft.a
LIB_MLX = minilibx/libmlx.a
SRC = error_exits.c gnl.c map_check.c player_moves.c render_texture.c so_long.c so_long_main.c so_longs_utils.c render_.c
OBJS = ${SRC:.c=.o}
CC = gcc
# CFLAGS = -Wall -Wextra -Werror
MINILIBX_FLAGS = -lmlx -framework OpenGL -framework AppKit
RM = rm -f

%.o: %c $(INCLUDE)
	$(CC) $(CFLAGS) -o $@ -c $<


all: $(NAME)

$(NAME): $(OBJS) $(LIB) $(INCLUDE)
		$(CC) $(MINILIBX_FLAGS) $(LIB) $(OBJS) -o $(NAME)

$(LIB):
	$(MAKE) -C $(LIBFT)

clean:
	$(MAKE) clean -C $(LIBFT)
	$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)
		$(RM) $(LIB)

re: fclean all





