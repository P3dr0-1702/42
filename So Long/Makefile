# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/04 16:26:27 by pfreire-          #+#    #+#              #
#    Updated: 2025/05/29 12:41:49 by pfreire-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CFLAGS = -Wall -Werror -Wextra

libDIR = lib
libNAME = libft.a
libPATH = $(libDIR)/$(libNAME)

SRCS = 
OBJS = $(SRCS:.c=.o)

libSRCS = $(wildcard $(libDIR)/*.c)
libOBJS = $(libSRCS:%.c=%.o)

all: $(libPATH) $(NAME)

$(libPATH): $(libOBJS)
	ar rcs $@ $^

$(libDIR)/%.o: $(libDIR)/%.c
	cc $(CFLAGS) -I $(libDIR) -c $< -o $@

$(NAME): $(OBJS) $(libPATH)
	cc $(CFLAGS) $^ -I $(libDIR) -L $(libDIR) -lft -o $@ 
	
%.o: %.c
	cc $(CFLAGS) -I $(libDIR) -c $< -o $@

clean:
	rm -f $(OBJS) $(libOBJS)

fclean: clean
	rm -f $(NAME)
	rm -f $(libPATH)

re: fclean all

.PHONY: all fclean clean re
