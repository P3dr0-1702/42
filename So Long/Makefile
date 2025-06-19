# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/04 16:26:27 by pfreire-          #+#    #+#              #
#    Updated: 2025/06/19 16:34:45 by pfreire-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
FLAGS = -Wall -Werror -Wextra -g
MLX = minilibx/libmlx.a

SRC_FILES =	main.c
OBJS = $(SRC_FILES:.c=.o)
LIBFT = lib/libft.a

all: $(NAME) 

$(NAME):$(OBJS) $(LIBFT) $(MLX)
	@$(CC) $(FLAGS) $(OBJS) $(LIBFT) $(MLX) -lXext -lX11 -g -o $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@
	
$(LIBFT):
	@$(MAKE) -C lib
	
$(MLX):
	@make -C minilibx

clean:
	@rm -f $(OBJS)
	@make clean -C lib
fclean:clean
	@rm -f $(NAME)
	@make fclean -C lib

re: fclean all

.PHONY: all fclean clean re
