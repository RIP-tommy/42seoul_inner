# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/14 17:12:50 by sungmcho          #+#    #+#              #
#    Updated: 2021/06/12 19:30:35 by sungmcho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-Wall -Wextra -Werror
NAME=libft.a
OBJS=$(SRCS:.c=.o)
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
ft_strjoin.c\
ft_strtrim.c\
ft_split.c\
ft_itoa.c\
ft_strmapi.c\
ft_putchar_fd.c\
ft_putstr_fd.c\
ft_putendl_fd.c\
ft_putnbr_fd.c

B_SRCS: ft_lstnew.c

$(NAME): $(OBJS)
	ar -cr $@ $^
$(OBJS):
	$(CC) -c $(SRCS)
$(B_OBJS):
	$(CC) -c $(B_SRCS)

ifdef WITH_BONUS
	OBJ_FILES = $(OBJS) $(B_OBJS)
else
	OBJ_FILES = $(OBJS)
endif

all: $(NAME)

re:
	make fclean
	make all

clean:
	rm $(OBJS)
	rm $(NAME)
fclean: clean
	rm -f $(NAME)
all : $(NAME)
bonus : 
	make WITH_BONUS=1 all
.PHONY: all bonus clean fclean re