
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = lst_utils.c  operations.c  push_swap.c  utils.c algorithm.c chunks.c quick_sort.c
OBJS =$(SRCS:.c=.o) 

NAME = push_swap

all: $(NAME)
	
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

debug: $(SRCS)
	$(CC) $(CFLAGS) -g $^ -o $(NAME)
		
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
