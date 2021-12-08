NAME	= fractol

CC		= gcc

SRC		= main.c

all:
	$(CC) -L./minilibx_opengl_20191021 -lmlx -framework OpenGL -framework AppKit main.c -o $(NAME)
	./$(NAME)

debug:
	$(CC) -L./minilibx_opengl_20191021 -lmlx -framework OpenGL -framework AppKit test.c -o $(NAME)
	./$(NAME)