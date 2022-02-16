# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahkecha <ahkecha@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/12 12:08:25 by ahkecha           #+#    #+#              #
#    Updated: 2022/02/16 15:48:55 by ahkecha          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus

LIBFT = libft
INCLUDE = so_long.h libft/libft.h

LIB = libft/libft.a
LIB_MLX = minilibx/libmlx.a

SRC = error_exits.c gnl.c map_check.c player_moves.c render_texture.c so_long.c so_long_main.c so_longs_utils.c so_long_utils2.c check_content.c
SRC_BONUS = $(addprefix bonus/, error_exits_bonus.c gnl_bonus.c map_check_bonus.c player_moves_bonus.c render_texture_bonus.c so_long_bonus.c so_long_main_bonus.c so_longs_utils_bonus.c so_long_utils2_bonus.c check_content_bonus.c)

OBJS = ${SRC:.c=.o}
OBJS_BONUS = ${SRC_BONUS:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror

MINILIBX_FLAGS = -lmlx -framework OpenGL -framework AppKit

RM = rm -f

%.o: %c $(INCLUDE)
	$(CC) $(CFLAGS) -o $@ -c $<


all: $(NAME)

bonus: $(NAME_BONUS)


$(NAME_BONUS):	$(OBJS_BONUS) $(LIB) $(INCLUDE)
			$(CC) $(MINILIBX_FLAGS) $(LIB) $(OBJS_BONUS) -o $(NAME_BONUS)


$(NAME): $(OBJS) $(LIB) $(INCLUDE)
		$(CC) $(MINILIBX_FLAGS) $(LIB) $(OBJS) -o $(NAME)

$(LIB):
	$(MAKE) -C $(LIBFT)
	$(MAKE) -C minilibx/

clean:
	$(MAKE) clean -C $(LIBFT)
	$(RM) $(OBJS)
	$(RM) $(OBJS_BONUS)

fclean: clean
		$(RM) $(NAME)
		$(RM) $(NAME_BONUS)
		$(RM) $(LIB)
		$(MAKE) clean -C minilibx/

re: fclean all

.PHONY: clean all fclean re





