#include "fractol.h"

int	press_esc(int keycode)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

int	press_wheel(int keycode, int x, int y, t_frac_data *frac)
{
	if (keycode == 4 || keycode == 5)
	{
		frac->mouse.x = (double)x / frac->pixel - frac->w_l.x / 2;
		frac->mouse.y = (double)y / frac->pixel - frac->w_l.y / 2;
		if (keycode == 5)
		{
			frac->center.x += -frac->mouse.x * (ZOOM_RATE - 1);
			frac->center.y += -frac->mouse.y * (ZOOM_RATE - 1);
			frac->pixel /= ZOOM_RATE;
			frac->w_l.x *= ZOOM_RATE;
			frac->w_l.y *= ZOOM_RATE;
		}
		else
		{
			frac->center.x += frac->mouse.x * (1 - 1 / ZOOM_RATE);
			frac->center.y += frac->mouse.y * (1 - 1 / ZOOM_RATE);
			frac->pixel *= ZOOM_RATE;
			frac->w_l.x /= ZOOM_RATE;
			frac->w_l.y /= ZOOM_RATE;
		}
		draw_frac(frac);
		mlx_put_image_to_window(frac->mlx, frac->win, frac->img.img_ptr, 0, 0);
	}
	return (0);
}
