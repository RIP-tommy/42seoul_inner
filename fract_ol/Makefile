NAME	= fractol

CC		= gcc

SRC		= main.c \
		ft_strcmp.c \
		ft_strlen.c \
		ft_atod.c \
		ft_isdigit.c \
		julia.c \
		mandelbrot.c \
		process_pixcels.c

all:
	$(CC) -L./minilibx_opengl_20191021 -lmlx -framework OpenGL -framework AppKit $(SRC) -o $(NAME)
