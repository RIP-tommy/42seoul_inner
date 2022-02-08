# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/09 14:21:21 by sungmcho          #+#    #+#              #
#    Updated: 2022/02/08 17:24:51 by sungmcho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
CC 			= gcc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar cr
RM			= rm -f
HEADER		= ft_printf.h
FILES		= ft_printf.c \
				ft_printf_print_char.c \
				ft_printf_print_nbr.c \
				ft_printf_print_str.c \
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

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re
