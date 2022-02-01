NAME		= push_swap

CC			= gcc
FLAGS		= -Wall -Wextra -Werror
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
			push_swap \
			small_push_swap \
			imbecile_ft

SRCS = $(addsuffix .c, $(FILES))
OBJS = $(addsuffix .o, $(FILES))

%.o: %.c
	make -C $(LIBFT_DIR) all
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) -I$(CWD) -L$(LIBFT_DIR) -l$(LIBFT_NAME)

all: $(NAME)

clean:
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all
