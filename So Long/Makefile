# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/04 16:26:27 by pfreire-          #+#    #+#              #
#    Updated: 2025/07/08 13:27:04 by pfreire-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
FLAGS = -Wall -Werror -Wextra -g
MLX = minilibx/libmlx.a

SRC_FILES =	$(wildcard *.c)
OBJS = $(SRC_FILES:.c=.o)
LIBFT = libft/libft.a

all: $(NAME) 

$(NAME):$(OBJS) $(LIBFT) $(MLX)
	@$(CC) $(FLAGS) $(OBJS) $(LIBFT) $(MLX) -lXext -lX11 -g -o $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@
	
$(LIBFT):
	@$(MAKE) -C libft
	
$(MLX):
	@make -C minilibx

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

.PHONY: all fclean clean re
