#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define ITER_MAX 100

# define X_EVENT_KEY_EXIT 17
# define X_EVENT_KEY_PRESS 2

# define KEY_ESC 53

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
	t_img	img;
}			t_mlx;

int		main(int argc, char *argv[]);
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(char *src);
double	ft_atod(char *str);
int		ft_isdigit(int c);
int		mandelbrot(int count_w, int count_h, int iter);
int		julia(int count_w, int count_h, int iter, char *argv[]);
void	put_pixel(t_img *img, int type, char *argv[]);

#endif
