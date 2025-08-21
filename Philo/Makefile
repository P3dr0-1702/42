# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/04 16:26:27 by pfreire-          #+#    #+#              #
#    Updated: 2025/08/21 11:40:13 by pedro            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc
FLAGS = -Wall -Werror -Wextra -g
SRC_FILES =	$(wildcard *.c)
OBJS = $(SRC_FILES:.c=.o)

all: $(NAME) 

$(NAME):$(OBJS)
	@$(CC) -g $(OBJS) -o $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

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
