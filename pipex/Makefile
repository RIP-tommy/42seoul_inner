NAME		= pipex

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
AR		= ar cr
RM		= rm -f

HLOC	= /Users/sungmcho/inner/pipex

HEADER		= pipex.h
FILES		= main.c \
			ft_split.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strlcat.c \
			ft_strncmp.c \
			ft_strjoin.c

SRCS = $(FILES)

# all: $(NAME)
all:
	gcc $(CFLAGS) -I$(HLOC) $(SRCS) -o $(NAME)

clean:
	$(RM) $(NAME)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re

debug:
	gcc -I/Users/sungmcho/inner/pipex $(SRCS) -o $(NAME)
	./pipex infile "cat" "wc -w" outfile
