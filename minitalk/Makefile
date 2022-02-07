NAME		= minitalk

CLIENT 		= client
SERVER		= server

CC 			= gcc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar cr
RM			= rm -f

FT_PRINTF	= libftprintf.a
PRINTF_NAME	= ftprintf
PRINTF_LDIR	= $(shell pwd)/printf
PRINTF_LIB	= -L$(PRINTF_LDIR) -l$(PRINTF_NAME)

FT_LIBFT = libft.a
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

CBOBJS = $(CBFILES:.c=.o)
SBOBJS = $(SBFILES:.c=.o)

ifdef WITH_BONUS
	COBJS = $(CBFILES:.c=.o)
	SOBJS = $(SBFILES:.c=.o)
else
    COBJS = $(CFILES:.c=.o)
	SOBJS = $(SFILES:.c=.o)
endif

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(FT_PRINTF) $(FT_LIBFT) server client

$(FT_PRINTF):
	make -C $(LIBFT_LDIR) all

$(FT_LIBFT):
	make -C $(PRINTF_LDIR) all

$(SERVER): $(SOBJS)
	gcc -o server/server $(SOBJS) $(PRINTF_LIB) $(LIBFT_LIB) -I$(LIB)

$(CLIENT): $(COBJS)
	gcc -o client/client $(COBJS) $(PRINTF_LIB) $(LIBFT_LIB) -I$(LIB)

all: $(NAME)

bonus:
	make WITH_BONUS=1 all

clean:
	make -C $(PRINTF_LDIR) clean
	make -C $(LIBFT_LDIR) clean
	$(RM) $(COBJS) $(SOBJS) $(CBOBJS) $(SBOBJS)

fclean: clean
	make -C $(PRINTF_LDIR) fclean
	make -C $(LIBFT_LDIR) fclean
	$(RM) client/client server/server

re: clean all

.PHONY: libft ft_printf all clean fclean re
