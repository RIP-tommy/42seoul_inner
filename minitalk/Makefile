NAME		= minitalk

CC 			= gcc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar cr
RM			= rm -f

PRINFT_NAME	= ftprintf
PRINFT_LDIR	= $(shell pwd)/printf
PRINFT_LIB	= -L$(PRINFT_LDIR) -l$(PRINFT_NAME)

LIB			= $(shell pwd)/inc
CFILES		= main
SFILES		= main

CSRCS = client/$(addsuffix .c, $(CFILES))
COBJS = client/$(addsuffix .o, $(CFILES))
SSRCS = server/$(addsuffix .c, $(SFILES))
SOBJS = server/$(addsuffix .o, $(SFILES))

%.o: %.c
	make -C $(PRINFT_LDIR) all
	$(CC) -c $< -o $@
# $(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(COBJS) $(SOBJS)
	gcc -o client/client $(COBJS) $(PRINFT_LIB) -I$(LIB)
	gcc -o server/server $(SOBJS) $(PRINFT_LIB) -I$(LIB)

all: $(NAME)

clean:
	make -C $(PRINFT_LDIR) clean
	$(RM) $(COBJS) $(SOBJS)

fclean: clean
	$(RM) client/client server/server

re: clean all

.PHONY: all clean fclean re

debug: $(COBJS) $(SOBJS)
	gcc -g -o client/client $(COBJS) $(PRINFT_LIB) -I(LIB)
	gcc -g -o server/server $(SOBJS) $(PRINFT_LIB) -I(LIB)
