# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/14 17:12:50 by sungmcho          #+#    #+#              #
#    Updated: 2021/05/14 17:22:05 by sungmcho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-Wall -Wextra -Werror
NAME=libft.a
OBJS = $(SRCS:.c=.o)
SRCS=ft_memcpy.c

$(NAME): $(OBJS)
	ar -cr $@ $^
$(OBJS):
	$(CC) -c $(SRCS)
all: $(NAME)
clean:
	rm $(OBJS)
	rm $(NAME)
fclean:
	rm -f $(OBJS)
	rm -f $(NAME)
