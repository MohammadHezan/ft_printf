SRC = ft_printf.c 
SRC_PUTS = $(addprefix puts/, ft_putchar.c ft_putstr.c ft_putnbr.c \
		   ft_putunbr.c ft_puthex.c ft_putptr.c)
OBJS := $(SRC:%.c=%.o)
OBJS += $(SRC_PUTS:puts/%.c=puts/%.o)
NAME = libftprintf.a

%.o: %.c
	cc -I. -Werror -Wall -Wextra -o $@ -c $?

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re