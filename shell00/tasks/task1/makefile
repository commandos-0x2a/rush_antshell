CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude

NAME = antshell

SRCS =  main.c \
	../utils/forking.c \
	../utils/ft_split.c \
	../utils/ft_dup.c \
	../utils/free_all.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

