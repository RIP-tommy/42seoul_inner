NAME		= minitalk

CC 			= gcc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar cr
RM			= rm -f

PRINFT_NAME	= ftprintf
PRINFT_LDIR	= $(shell pwd)/printf
PRINFT_LIB	= -L$(PRINFT_LDIR) -l$(PRINFT_NAME)

CFILES		= main_client

SFILES		= main_server

CSRCS = $(addsuffix .c, $(CFILES))
COBJS = $(addsuffix .c, $(CFILES))
SSRCS = $(addsuffix .c, $(SFILES))
SOBJS = $(addsuffix .c, $(SFILES))

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(COBJS) $(SOBJS)
	make -C $(PRINFT_LDIR) all
	gcc $(COBJS) $(PRINFT_LIB) -o client
	gcc $(SOBJS) $(PRINFT_LIB) -o server

all: $(NAME)

clean:
	make -C $(PRINFT_LDIR) clean
	$(RM) $(COBJS) $(SOBJS)

fclean: clean
	$(RM) server client

re: clean all

.PHONY: all clean fclean re

debug: $(COBJS) $(SOBJS)
	gcc -g $(COBJS) $(FT_PRINTF) -o client
	gcc -g $(SOBJS) $(FT_PRINTF) -o server
