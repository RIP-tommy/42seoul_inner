NAME	= fractol

CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror
HEADER	= fractol.h

LIB		= -L$(MLX) -lmlx -framework OpenGL -framework AppKit

MLX		= minilibx_opengl_20191021


SRCS	= main.c \
		ft_strcmp.c \
		ft_strlen.c \
		ft_atod.c \
		ft_isdigit.c \
		julia.c \
		mandelbrot.c \
		handle_mouse_scroll.c \
		process_pixcels.c

OBJS = $(SRCS:.c=.o)

%.o: %.c $(LIB) $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)

all: $(NAME)
	make -C $(MLX)
	$(CC) $(CFLAGS) $(LIB) -o $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean: 	clean
			make clean -C $(MLX)
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re