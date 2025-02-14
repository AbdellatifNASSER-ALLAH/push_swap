.PHONY: e clean
# Dirctory where your project resides
DIR=../Project

# Program Name
NAME = push_swap

# Complie
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = lst_utils.c  operations.c  utils.c algorithm.c chunks.c quick_sort.c simple_sort.c
SRCB = lst_utils.c  operations.c  utils.c quick_sort.c

all: $(NAME)
	$(CC) $(CFLAGS) -g push_swap.c $(SRC) -o $^

bonus: $(NAME)
	$(CC) $(CFLAGS) -g checker.c $(SRCB) -o $^

$(NAME): fclean
	cp $(DIR)/*.c  $(DIR)/*.h .
e:
	@vi Makefile

test:
	./push_swap_test_linux.sh

clean:
	rm -rf *.c *.h 0 traces.txt

fclean: clean
	rm -rf $(NAME)

re: fclean all 
