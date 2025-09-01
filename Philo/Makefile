# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/04 16:26:27 by pfreire-          #+#    #+#              #
#    Updated: 2025/09/01 18:29:31 by pfreire-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc
FLAGS = -Wall -Werror -Wextra -g
SRC_FILES =	main.c aux_funcs.c aux_aux_funcs.c grim_reaper.c routine.c parsing.c clean.c
OBJS = $(SRC_FILES:.c=.o)


all: $(NAME) 

$(NAME):$(OBJS)
	@$(CC) -g $(OBJS) -o $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
fclean:clean
	@rm -f $(NAME)

re: fclean all

ra: re clean
	@rm -f $(OBJS)

e: all clean

.PHONY: all fclean clean re
