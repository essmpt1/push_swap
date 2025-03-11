NAME = libft.a

CC = cc

SRC_DIR = .

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_bzero.c ft_calloc.c ft_atol.c ft_isdigit.c \

OBJS = $(SRCS:%.c=$(SRC_DIR)/%.o)

INC_DIR = .

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

all: $(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.DEFAULT_GOAL := all

.PHONY: all clean fclean re

