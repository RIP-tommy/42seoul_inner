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
CFILES		= client/main.c \
			client/send_msg.c
SFILES		= server/main.c

CBFILES		= client/main_bonus.c \
			client/send_msg_bonus.c
SBFILES		= server/main_bonus.c

COBJS = $(CFILES:.c=.o)
SOBJS = $(SFILES:.c=.o)

CBOBJS = $(CBFILES:.c=.o)
SBOBJS = $(SBFILES:.c=.o)

%.o: %.c
	make -C $(PRINFT_LDIR) all
	make -C $(LIBFT_LDIR) all
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(COBJS) $(SOBJS)
	gcc -o client/client $(COBJS) $(PRINFT_LIB) $(LIBFT_LIB) -I$(LIB)
	gcc -o server/server $(SOBJS) $(PRINFT_LIB) $(LIBFT_LIB) -I$(LIB)

all: $(NAME)

bonus: $(CBOBJS) $(SBOBJS)
	gcc -o client/client $(CBOBJS) $(PRINFT_LIB) $(LIBFT_LIB) -I$(LIB)
	gcc -o server/server $(SBOBJS) $(PRINFT_LIB) $(LIBFT_LIB) -I$(LIB)

clean:
	make -C $(PRINFT_LDIR) clean
	make -C $(LIBFT_LDIR) clean
	$(RM) $(COBJS) $(SOBJS) $(CBOBJS) $(SBOBJS)

fclean: clean
	make -C $(PRINFT_LDIR) fclean
	make -C $(LIBFT_LDIR) fclean
	$(RM) client/client server/server

re: clean all

.PHONY: all clean fclean re

debug: $(DNAME)
	make -C $(PRINFT_LDIR) all
	make -C $(LIBFT_LDIR) all
	gcc -g -o client/client $(CFILES) $(PRINFT_LIB) $(LIBFT_LIB) -I$(LIB)