#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_vars
{
	void *mlx;
	void *win;
} t_vars;

typedef struct s_data
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_data;

int handle_exit(int keycode, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(1);
	return (1);
}

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int main(int argc, char *argv[])
{
	t_vars vars;
	t_data img;
	int i;
	int j;
	int k;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "fractol");
	img.img = mlx_new_image(vars.mlx, 640, 480);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	for (i = 250, k = 99; i < 300; i++, k -= 2)
	{
		for (j = 150 + k; j < 250; j++)
			my_mlx_pixel_put(&img, i, j, 0x0000FF00);
	}
	for (i = 300, k = 0; i < 350; i++, k += 2)
	{
		for (j = 150 + k; j < 250; j++)
			my_mlx_pixel_put(&img, i, j, 0x0000FF00);
	}
	mlx_hook(vars.win, 2, 1L << 0, handle_exit, &vars);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_loop(vars.mlx);
	return 0;
}
