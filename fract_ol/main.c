#include "fractol.h"

int		window_init(t_mlx *mlx)
{
	if (!(mlx->mlx_ptr = mlx_init()))
		return (0);
	if (!(mlx->win = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "fractol")))
		return (0);
	if (!(mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT)))
		return (0);
	if (!(mlx->img.data = mlx_get_data_addr(mlx->img.img_ptr, &mlx->img.bpp, &mlx->img.size_l, &mlx->img.endian)))
		return (0);
	return (1);
}

int	close(int keycode)
{
	if (keycode == X_EVENT_KEY_EXIT)
		exit(EXIT_SUCCESS);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_mlx	mlx;

	if (argc < 2)
		printf("NOT ENOUGH PARAMATERS\nINPUT A PARAMTER LIKE\n medelbrot\n julia");
	if (!validate_arg(argv[1]))
		printf("%s", validate_arg(argv[1]));
	if (!window_init(&mlx))
		return (0);
	put_pixel(&mlx.img);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win, mlx.img.img_ptr, 0, 0);
	mlx_hook(mlx.win, X_EVENT_KEY_EXIT, 0, close, 0);
	mlx_loop(mlx.mlx_ptr);
	return (0);	
}
