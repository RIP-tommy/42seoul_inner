CC=gcc
CFLAGS=-Wall -Wextra -Werror
DEFINE=-D BUFFER=42

NAME=main

OBJS=$(SRCS:.c=.o)
INC_DIR=/Users/sm/inner/gnl

SRCS=get_next_line.c\
get_next_line_utils.c

B_SRCS=get_next_line_bonus.c\
get_next_line_utils_bonus.c

all: 
	$(CC) $(DEFINE) -o $(NAME) main.c $(SRCS)
clean: 
	rm $(name)
fclean:
	rm $(name)
re:
	make all
debug:
	$(CC) -g $(CFLAGS) $(DEFINE) main.c $(SRCS) -o $(NAME) 
bonus:
	$(CC) $(CFLAGS) $(DEFINE) main.c $(B_SRCS) -o bonus_main 
