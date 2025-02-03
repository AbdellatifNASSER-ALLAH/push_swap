
CC = cc
CFLAGS = -Wall -Wextra -Werror -g #TODO:	The -g flag it is not necessary here (it is just for debbuging)

SRCS = lst_utils.c  operations.c  push_swap.c  utils.c
OBJS =$(SRCS:.c=.o) 

NAME = push_swap

all: $(NAME)
	
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
