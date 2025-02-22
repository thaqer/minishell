
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRCS = ft_printf.c ft_mod.c ft_putpoin.c ft_putcharpf.c ft_putpoin.c ft_putstrpf.c ft_putnbr_base.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re