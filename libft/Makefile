# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/04 16:26:27 by pfreire-          #+#    #+#              #
#    Updated: 2025/04/07 11:22:18 by pfreire-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra
SRCS = ft_*.c
OBJS = $(SRCS:.c=.o)
INCS = includes

all: libft

$(OBJS): srcs/%.o: srcs/%.c
	cc $(CFLAGS) -c $< -o $@


libft: $(OBJS)
	ar rcs libft.a $(OBJS)


clean:
	rm -f $(OBJS)

fclean: clean
	rm -f libft.a

re: fclean all
