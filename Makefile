CC = cc

CFLAGS = -Wall -Werror -Wextra
SRCS = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c\
	src/main.c\
	src/environment.c\
	src/signals.c\
	src/commands.c\

NAME = minishell

LIBFT = libft/libft.a
PRINTF = printf/libftprintf.a

LIBS = -lreadline

OBJ = $(addprefix objs/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) $(LIBS) -o $(NAME)

$(LIBFT):
	@make -C libft

$(PRINTF):
	@make -C printf


objs/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make -C libft clean
	@make -C printf clean
	@rm -rf objs

fclean: clean
	@make -C libft fclean
	@make -C printf fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re