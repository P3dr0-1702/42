NAME = ft_lib.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -c

SRC = ft_putchar.c ft_putstr.c ft_strcmp.c ft_strlen.c ft_swap.c

all: $(NAME)

$(NAME):
		$(CC) $(CFLAGS) -c *.c ; ar rcs ft_lib.a *.o
clean:
		/bin/rm -f *.o

fclean: clean
		/bin/rm -f $(NAME)

re: fclean all
