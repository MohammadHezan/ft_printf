SRC = ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_puthex.c ft_putptr.c ft_putunbr.c
OBJS := $(SRC:.c=.o)
NAME = libftprintf.a

%.o: %.c
	cc -I. -Werror -Wall -Wextra -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re