# NAME = libftprintf.a

CC = gcc
# CFLAGS = -Wall -Wextra -Werror
# AR = ar -cr
# RM = rm -f

# FILES =		

# FILES_B =	

# SRCS = $(addsuffix .c, $(FILES))
# SRCS_B = $(addsuffix .c, $(FILES_B))

# OBJS = $(addsuffix .o, $(FILES))
# OBJS_B = $(addsuffix .o, $(FILES_B))


# .c.o: $(SRCS)
# 	$(CC) $(CFLAGS) -c -o $@ $<

# $(NAME): $(OBJS)
# 	$(AR) $@ $^

# bonus: $(OBJS_B)
# 	$(AR) $(NAME) $^

# all: $(NAME)

# clean:
# 	$(RM) $(OBJS) $(OBJS_B)

# fclean: clean
# 	$(RM) $(NAME)

# re: clean all

# .PHONY: bonus all clean fclean re

all:
	$(CC) main.c ft_printf.c ft_printf.h ./Libft/* ./src/*

debug:
	$(CC) -g main.c ft_printf.c ft_printf.h ./Libft/* ./src/*