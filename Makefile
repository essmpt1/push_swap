NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

LIBFT_DIR = ./libft

LIBFT = $(LIBFT_DIR)/libft.a

SRC_DIR = .

SRCS = moviments_p.c moviments_r.c moviments_re.c moviments_s.c push_swap.c \
	utils.c validate.c sort.c init_radix.c

OBJS = $(SRCS:%.c=$(SRC_DIR)/%.o)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

all: $(NAME)

clean:
	@rm -f $(OBJS)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
