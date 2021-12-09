#include "fractol.h"

int	julia(int count_w, int count_h, int iter, t_img *img)
{
	double	c_re;
	double	c_im;
	double	x;
	double	x_new;
	double	y;

	c_re = -0.75;
	c_im = 0;
	x = ((count_w - WIN_WIDTH / 2) * 4.0 / WIN_WIDTH);
	y = ((WIN_HEIGHT / 2) - count_h) * 4.0 / WIN_HEIGHT;
	while ((pow(x, 2.0) + pow(y, 2.0) < 4) && (iter < ITER_MAX))
	{
		x_new = pow(x, 2.0) - pow(y, 2.0) + c_re;
		y = 2 * x * y + c_im;
		x = x_new;
		iter++;
	}
	return (iter);
}
