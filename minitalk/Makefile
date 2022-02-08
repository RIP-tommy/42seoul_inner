NAME		= minitalk

CLIENT 		= client
SERVER		= server

CC 			= gcc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar cr
RM			= rm -f

PRINTF_LDIR	= $(shell pwd)/printf
FT_PRINTF	= $(PRINTF_LDIR)/libftprintf.a
PRINTF_NAME	= ftprintf
PRINTF_LIB	= -L$(PRINTF_LDIR) -l$(PRINTF_NAME)

LIBFT_LDIR	= $(shell pwd)/Libft
FT_LIBFT 	= $(LIBFT_LDIR)/libft.a
LIBFT_NAME	= ft
LIBFT_LIB	= -L$(LIBFT_LDIR) -l$(LIBFT_NAME)

LIB			= $(shell pwd)/inc
CFILES		= client/main.c \
			client/send_msg.c
SFILES		= server/main.c

CBFILES		= client/main_bonus.c \
			client/send_msg_bonus.c
SBFILES		= server/main_bonus.c

CBOBJS		= $(CBFILES:.c=.o)
SBOBJS		= $(SBFILES:.c=.o)

ifdef WITH_BONUS
	COBJS 	= $(CBFILES:.c=.o)
	SOBJS 	= $(SBFILES:.c=.o)
	S_HEADER	= $(LIB)/server_bonus.h
	C_HEADER	= $(LIB)/client_bonus.h
else
    COBJS 	= $(CFILES:.c=.o)
	SOBJS 	= $(SFILES:.c=.o)
	S_HEADER	= $(LIB)/server.h
	C_HEADER	= $(LIB)/client.h
endif

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

.PHONY: all clean fclean re

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(FT_PRINTF):
	make -C $(PRINTF_LDIR)

$(FT_LIBFT):
	make -C $(LIBFT_LDIR)

$(SERVER): $(SOBJS) $(S_HEADER)
	gcc -o server/server $(SOBJS) $(PRINTF_LIB) $(LIBFT_LIB) -I$(LIB)

$(CLIENT): $(COBJS) $(C_HEADER)
	gcc -o client/client $(COBJS) $(PRINTF_LIB) $(LIBFT_LIB) -I$(LIB)

$(NAME): $(FT_PRINTF) $(FT_LIBFT) $(SERVER) $(CLIENT)
