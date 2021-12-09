#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# define WIN_WIDTH 800
# define WIN_HEIGHT 800
# define ITER_MAX 255
# define ZOOM_RATE 1.2

# define X_EVENT_KEY_EXIT 53

typedef	struct	s_img{
	void		*img_ptr;
	char		*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef	struct	s_mlx{
	void		*mlx_ptr;
	void		*win;
	t_img		img;
}				t_mlx;

int		main(int argc, char *argv[]);
void	close(int keycode);

#endif