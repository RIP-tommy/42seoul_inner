NAME	= pipex

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
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

all:
	gcc $(CFLAGS) -I$(HLOC) $(SRCS) -o $(NAME)

clean:
	$(RM) $(NAME)

fclean: clean
	$(RM) outfile

re: clean all

.PHONY: all clean fclean re
