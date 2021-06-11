CC=gcc
CFLAGS=-g -Wall -Wextra -Werror
DEFINE=-D BUFFER_SIZE=8

NAME=main

OBJS=$(SRCS:.c=.o)
INC_DIR=/Users/sm/42seoul_inner/gnl

SRCS=get_next_line.c\
get_next_line_utils.c

all: 
	$(CC) -I$(INC_DIR) $(DEFINE) -o $(NAME) main.c $(SRCS)
clean: 
	rm $(name)
fclean:
	rm $(name)
re:
	make all
debug:
	$(CC) -g -I$(INC_DIR) $(DEFINE) -o $(NAME) main.c $(SRCS)