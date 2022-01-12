NAME		= push_swap

CC			= gcc
FLAGS		= -Wall -Werror
RM			= rm -rf
CWD			= $(shell pwd)

LIBFT_DIR	= $(shell pwd)/Libft
LIBFT_NAME	= ft

FILES		= main \
			is_sorted \
			over_max_min_int_checker \
			exit_failure \
			s_operations \
			p_operations \
			r_operations \
			rr_operations \
			find_number \
			sorting

SRCS = $(addsuffix .c, $(FILES))

OBJS = $(addsuffix .o, $(FILES))

.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $<

all:
	make -C $(LIBFT_DIR) all
	$(CC) -o $(NAME) $(SRCS) -I$(CWD) -L$(LIBFT_DIR) -l$(LIBFT_NAME)

clean:
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

debug:
	make -C $(LIBFT_DIR) all
	$(CC) -g -o $(NAME) $(SRCS) -I$(CWD) -L$(LIBFT_DIR) -l$(LIBFT_NAME)