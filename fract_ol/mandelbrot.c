#include "fractol.h"

int	mandelbrot(int count_w, int count_h, int iter)
{
	double c_re;
	double c_im;
	double x;
	double x_new;
	double y;

	c_re = ((count_w - WIN_WIDTH / 2) * 3.0 / WIN_WIDTH) - 0.5;
	c_im = ((WIN_HEIGHT / 2) - count_h) * 2.0 / WIN_HEIGHT;
	x = 0;
	y = 0;
	while ((pow(x, 2.0) + pow(y, 2.0) < 4) && (iter < ITER_MAX))
	{
		x_new = pow(x, 2.0) - pow(y, 2.0) + c_re;
		y = 2 * x * y + c_im;
		x = x_new;
		iter++;
	}
	return (iter);
}
