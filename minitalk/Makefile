NAME		= minitalk

FT_PRINTF	= libftprintf.a
CC 			= gcc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar cr
RM			= rm -f

CFILES		= main_client.c

SFILES		= main_server.c

CSRCS = $(CFILES)
COBJS = $(CSRCS:.c=.o)
SSRCS = $(SFILES)
SOBJS = $(SSRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(COBJS) $(SOBJS)
	gcc $(COBJS) $(FT_PRINTF) -o client
	gcc $(SOBJS) $(FT_PRINTF) -o server

all: $(NAME)

clean:
	$(RM) $(COBJS) $(SOBJS)

fclean: clean
	$(RM) $(NAME) server client

re: clean all

.PHONY: all clean fclean re

debug: $(COBJS) $(SOBJS)
	gcc -g $(COBJS) $(FT_PRINTF) -o client
	gcc -g $(SOBJS) $(FT_PRINTF) -o server
