#ifndef FRACTOL_H
# define FRACTOL_H

// # include "mlx.h"
# include "minilibx_opengl_20191021/mlx.h"
# include <stdio.h>
# include <stdlib.h>

# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define ITER_MAX 100
# define ZOOM_RATE 1.2

# define X_EVENT_KEY_EXIT 17
# define X_EVENT_KEY_PRESS 2

# define KEY_ESC 53

typedef struct	coordinate{
	double	x;
	double	y;
}				t_cord;

typedef struct s_img{
	void	*img_ptr;
	char	*data;
	int		size_l;
	int		bpp;
	int		endian;
}			t_img;

typedef struct s_mlx{
	void	*mlx_ptr;
	void	*win;
	double		pixel;
	t_img	img;
	t_cord	center;
	t_cord	w_l;
	t_cord	mouse;
}			t_mlx;

int		main(int argc, char *argv[]);
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(char *src);
double	ft_atod(char *str);
int		ft_isdigit(int c);
int		mandelbrot(int count_w, int count_h, int iter);
int		julia(int count_w, int count_h, int iter, char *argv[]);
void	put_pixel(t_img *img, int type, char *argv[]);
int		handle_mouse_scroll(int keycode, int x, int y, t_mlx *mlx);
int		key_press(int keycode);
int		close(int keycode);

#endif
