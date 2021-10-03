NAMEi		= minitalk
CC 			= gcc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar cr
RM			= rm -f

FILES		= ./ft_printf/ft_printf.c \
				./ft_printf/ft_putchar_fd.c \
				./ft_printf/ft_putnbr_fd.c \
				./ft_printf/ft_putstr_fd.c \
				./ft_printf/ft_strlen.c \
				./ft_printf/print_chr.c \
				./ft_printf/print_hex.c \
				./ft_printf/print_int.c \
				./ft_printf/print_ptr.c \
				./ft_printf/print_str.c \
				./ft_printf/print_un.c \
				./ft_printf/itoh.c \
				main_client.c

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
	$(CC) -o main -g $(SRCS)