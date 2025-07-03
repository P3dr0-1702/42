# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/04 16:26:27 by pfreire-          #+#    #+#              #
#    Updated: 2025/05/15 13:57:39 by pfreire-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CFLAGS = -Wall -Werror -Wextra
SRCS = get_next_line.c get_next_line_utils.c ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_printf.c ft_putstr.c ft_putunbr.c ft_wordcpy.c ft_count_words.c ft_lstadd_back.c ft_putlchar.c ft_printlhex.c ft_putlnbr_hexlow.c ft_putlnbr_hex.c ft_putlunbr.c ft_putlnbr.c ft_printhex.c ft_putchar.c ft_putnbr_hex.c ft_putnbr_hexlow.c ft_putnbr.c ft_putlstr.c ft_i_wanna_break_free.c ft_strcmp.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJS): %.o: %.c
	cc $(CFLAGS) -c $< -o $@


clean:
	rm -f $(OBJS)
	rm -f $(BOBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean clean re
