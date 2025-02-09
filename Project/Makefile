
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = lst_utils.c  operations.c  push_swap.c  utils.c algorithm.c chunks.c quick_sort.c simple_sort.c
OBJS =$(SRCS:.c=.o) 

SRCSB = lst_utils.c  operations.c  checker.c  utils.c quick_sort.c
OBJSB =$(SRCSB:.c=.o) 

NAME = push_swap
BONUS = checker

all: $(NAME)

bonus: $(BONUS)
	
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(BONUS): $(OBJSB)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
		
clean:
	rm -f $(OBJS) $(OBJSB)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re
