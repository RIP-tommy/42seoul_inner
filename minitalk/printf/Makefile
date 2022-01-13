# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sungmcho <sungmcho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/09 14:21:21 by sungmcho          #+#    #+#              #
#    Updated: 2021/09/09 18:58:02 by sungmcho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
CC 			= gcc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar cr
RM			= rm -f
HEADER		= ft_printf.h
FILES		= ft_printf.c \
				ft_putchar_fd.c \
				ft_putnbr_fd.c \
				ft_putstr_fd.c \
				ft_strlen.c \
				print_chr.c \
				print_hex.c \
				print_int.c \
				print_ptr.c \
				print_str.c \
				print_un.c \
				itoh.c

SRCS = $(FILES)
OBJS = $(SRCS:.c=.o)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(AR) $@ $^

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re

debug:
	$(CC) -o main -g $(SRCS) main.c

debug2:
	$(CC) -o main -g $(SRCS) test.c