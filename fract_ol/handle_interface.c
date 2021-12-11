#include "fractol.h"

int	key_press(int keycode)
{
	if (keycode == KEY_ESC)
		exit(0);
	else
		return (0);
	return (0);
}

int	close(int keycode)
{
	if (keycode == X_EVENT_KEY_EXIT)
		exit(EXIT_SUCCESS);
	if (keycode == -1)
	{	
		printf("NOT ENOUGH PARAMATERS\n\n");
		printf("INPUT A PARAMTER LIKE\n\nmandelbrot\njulia 0.27 -0.27\n");
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	handle_mouse_scroll(int keycode, int x, int y, t_mlx *mlx)
{
	if (keycode == 4 || keycode == 5)
	{
		mlx->mouse.x = (double)x / mlx->pixel - mlx->w_l.x / 2;
		mlx->mouse.y = (double)y / mlx->pixel - mlx->w_l.y / 2;
		if (keycode == 5)
		{
			mlx->center.x += -mlx->mouse.x * (ZOOM_RATE - 1);
			mlx->center.y += -mlx->mouse.y * (ZOOM_RATE - 1);
			mlx->pixel /= ZOOM_RATE;
			mlx->w_l.x *= ZOOM_RATE;
			mlx->w_l.y *= ZOOM_RATE;
		}
		else
		{
			mlx->center.x += mlx->mouse.x * (1 - 1 / ZOOM_RATE);
			mlx->center.y += mlx->mouse.y * (1 - 1 / ZOOM_RATE);
			mlx->pixel *= ZOOM_RATE;
			mlx->w_l.x /= ZOOM_RATE;
			mlx->w_l.y /= ZOOM_RATE;
		}
		draw_mlx(mlx);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img.img_ptr, 0, 0);
	}
	return (0);
}
