#ifndef FRACTOL_H
# define FRACTOL_H

// # include "mlx.h"
# include "minilibx_opengl_20191021/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# define WIDTH 800
# define LENGTH 800
# define LOOP_LIMIT 255
# define ZOOM_RATE 1.5

typedef struct s_d_pair
{
	double	x;
	double	y;
}	t_d_pair;

typedef struct s_img
{
	void	*img_ptr;
	char	*data_ptr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_frac_data
{
	int			f_flag;
	double		pixel;
	void		*win;
	void		*mlx;
	t_img		img;
	t_d_pair	center;
	t_d_pair	w_l;
	t_d_pair	julia_comp;
	t_d_pair	mouse;
}	t_frac_data;

void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(char *str);
int		ft_isdigit(int c);
double	ft_atod(char *str);
int		mandelbrot(t_d_pair p);
int		julia(t_d_pair p, t_d_pair j_p);
int		press_esc(int keycode);
int		press_wheel(int keycode, int x, int y, t_frac_data *frac);
void	draw_frac(t_frac_data *frac);

#endif
