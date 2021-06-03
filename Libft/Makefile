# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/14 17:12:50 by sungmcho          #+#    #+#              #
#    Updated: 2021/06/03 17:44:53 by sungmcho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-Wall -Wextra -Werror
NAME=libft.a
OBJS = $(SRCS:.c=.o)
SRCS=ft_memset.c\
ft_bzero.c\
ft_memcpy.c\
ft_memccpy.c\
ft_memmove.c\
ft_memchr.c\
ft_memcmp.c\
ft_strlen.c\
ft_strlcpy.c\
ft_strlcat.c\
ft_strchr.c\
ft_strrchr.c\
ft_strnstr.c\
ft_strncmp.c\
ft_atoi.c\
ft_isalpha.c\
ft_isdigit.c\
ft_isalnum.c\
ft_isascii.c\
ft_isprint.c\
ft_toupper.c\
ft_tolower.c\
ft_calloc.c\
ft_strdup.c\
ft_substr.c\
ft_strjoin.c

$(NAME): $(OBJS)
	ar -cr $@ $^
$(OBJS):
	$(CC) -c $(SRCS)
all: $(NAME)
re:
	make fclean
	make all
clean:
	rm $(OBJS)
	rm $(NAME)
fclean:
	rm -f $(OBJS)
	rm -f $(NAME)
