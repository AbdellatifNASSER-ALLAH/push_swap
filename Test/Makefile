.PHONY: e
# Dirctory where your project resides
DIR=~/Files/push_swap/Project

# Program Name
NAME = push_swap

# Complie
CC = cc
CFLAGS = -g

# Path to the program
PATH=$(DIR)/$(NAME)


all: $(NAME)
	$(MAKE) -C $(DIR) fclean
$(NAME):
	$(MAKE) -C $(DIR)
	cp $(PATH) .
e:
	@vi Makefile

