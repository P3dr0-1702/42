# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/14 11:26:05 by pfreire-          #+#    #+#              #
#    Updated: 2025/04/18 11:12:45 by pfreire-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CFLAGS = -Wall -Werror -Wextra
SRCS = ft_printf.c ft_printhex.c ft_putchar.c ft_putnbr_hex.c ft_putstr.c ft_putnbr_hexlow.c ft_putnbr.c ft_putunbr.c 
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	
$(OBJS): %.o: %.c
	cc $(CFLAGS) -c $< -o $@
	
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean clean re
