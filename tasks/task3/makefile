CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude 

NAME = antshell

SRCS =  main.c\
		../utils/ft_split.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -lreadline > /dev/null 2>&1
	@echo "make: Success"

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
