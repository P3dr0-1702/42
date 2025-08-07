# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/04 16:26:27 by pfreire-          #+#    #+#              #
#    Updated: 2025/08/07 10:37:18 by pfreire-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
FLAGS = -Wall -Werror -Wextra -g
MLX =  minilibx-linux/

SRC_FILES =	\
  ./code/debug/debug.c \
  ./code/debug/debug_aux_func.c \
  ./code/aux_func.c \
  ./code/init/init_base.c \
  ./code/init/init_collect.c \
  ./code/init/inititalizer.c \
  ./code/init/initializer_aux.c \
  ./code/gameloop.c \
  ./code/map/map.c \
  ./code/map/map_validation.c \
  ./code/map/map_validation_aux.c \
  ./code/map/map_parsing_aux.c \
  ./code/map/map_parsing.c \
  ./code/map/map_aux.c \
  ./code/main.c \
  ./code/player/player.c \
  ./code/player/move.c \
  ./code/rendering.c \
  ./code/utils.c
OBJS = $(SRC_FILES:.c=.o)
LIBFT = libft/libft.a
REPO = https://github.com/42paris/minilibx-linux.git

all: $(NAME) 

$(NAME):$(OBJS) $(LIBFT) $(MLX)/libmlx.a
	@$(CC) $(FLAGS) $(OBJS) $(LIBFT) $(MLX) -lXext -lX11 -g -o $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@
	
$(LIBFT):
	@$(MAKE) -C libft
	
$(MLX):
	@make -C $(MLX)

mlx:
	git clone $(REPO)

clean:
	@rm -f $(OBJS)
	@make clean -C libft
fclean:clean
	@rm -f $(NAME)
	@make fclean -C libft

re: fclean all

ra: re clean
	@rm -f $(OBJS)
	@make clean -C libft

e: all clean

.PHONY: all fclean clean re
