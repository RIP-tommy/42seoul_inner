NAME		= pipex

CC		= gcc
CFLAGS		= -Wall -Wextra -Werror
AR		= ar cr
RM		= rm -f

HEADER		= pipex.h
CFILES		= main.c

SRCS = $(FILES)
OBJS = $(SRCS:.c=.o)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(AR) $@ $^

all: $(NAME)

clean:
	$(RM) $(COBJS) $(SOBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re

debug:
	gcc -I/Users/sungmcho/inner/pipex main.c -o pipex