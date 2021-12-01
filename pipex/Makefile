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

B_FILES		= main_bonus.c 

SRCS = $(FILES)
B_SRCS = $(B_FILES)

all:
	gcc $(CFLAGS) -I$(HLOC) $(SRCS) -o $(NAME)
	./pipex infile "cat" "wc -w" outfile

clean:
	$(RM) $(NAME)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re

bonus:
	gcc $(CFLAGS) -I$(HLOC) $(B_SRCS) -o $(NAME)
	./pipex infile "cat" | "grep a1" | "wc -w" outfile