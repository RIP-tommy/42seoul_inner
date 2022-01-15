NAME		= minitalk

CC 			= gcc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar cr
RM			= rm -f

PRINFT_NAME	= ftprintf
PRINFT_LDIR	= $(shell pwd)/printf
PRINFT_LIB	= -L$(PRINFT_LDIR) -l$(PRINFT_NAME)

LIBFT_NAME	= ft
LIBFT_LDIR	= $(shell pwd)/Libft
LIBFT_LIB	= -L$(LIBFT_LDIR) -l$(LIBFT_NAME)

LIB			= $(shell pwd)/inc
CFILES		= main
SFILES		= main

CSRCS = client/$(addsuffix .c, $(CFILES))
COBJS = client/$(addsuffix .o, $(CFILES))
SSRCS = server/$(addsuffix .c, $(SFILES))
SOBJS = server/$(addsuffix .o, $(SFILES))

%.o: %.c
	make -C $(PRINFT_LDIR) all
	make -C $(LIBFT_LDIR) all
	$(CC) -c $< -o $@
# $(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(COBJS) $(SOBJS)
	gcc -o client/client $(COBJS) $(PRINFT_LIB) $(LIBFT_LIB) -I$(LIB)
	gcc -o server/server $(SOBJS) $(PRINFT_LIB) $(LIBFT_LIB) -I$(LIB)

all: $(NAME)

clean:
	make -C $(PRINFT_LDIR) clean
	make -C $(LIBFT_LDIR) clean
	$(RM) $(COBJS) $(SOBJS)

fclean: clean
	make -C $(PRINFT_LDIR) fclean
	make -C $(LIBFT_LDIR) fclean
	$(RM) client/client server/server

re: clean all

.PHONY: all clean fclean re
