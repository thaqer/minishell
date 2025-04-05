CC = cc

CFLAGS = -Wall -Werror -Wextra
SRCS = 	src/builtin.c\
	src/commands.c\
	src/environment.c\
	src/expantion.c\
	src/ft_cd.c\
	src/ft_echo.c\
	src/ft_exit.c\
	src/ft_export.c\
	src/ft_pwd.c\
	src/ft_unset.c\
	src/main.c\
	src/signals.c\
	src/tokenizer.c\
	src/utils.c\
	

NAME = minishell

LIBFT = libft/libft.a


LIBS = -lreadline

OBJ = $(addprefix objs/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LIBS) -o $(NAME)

$(LIBFT):
	@make -C libft


objs/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make -C libft clean
	@rm -rf objs

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re