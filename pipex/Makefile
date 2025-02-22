CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

NAME = libpipex.a

SRCS = pipex.c end_process.c child_process.c

LIBFT = ../../minishell/libft/libft.a

OBJS_DIR = objs
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C ../../minishell/libft

clean:
	rm -f $(OBJS)
	-rmdir $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
