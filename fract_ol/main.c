/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:15:23 by sungmcho          #+#    #+#             */
/*   Updated: 2021/12/09 19:23:44 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	window_init(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		return (0);
	mlx->win = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "fractol");
	if (!mlx->win)
		return (0);
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!mlx->img.img_ptr)
		return (0);
	mlx->img.data = mlx_get_data_addr(mlx->img.img_ptr, \
					&mlx->img.bpp, &mlx->img.size_l, &mlx->img.endian);
	if (!mlx->img.data)
		return (0);
	return (1);
}

static int	key_press(int keycode)
{
	if (keycode == KEY_ESC)
		exit(0);
	else
		return (0);
	return (0);
}

static int	close(int keycode)
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

static int	validate_type(int argc, char *type)
{
	if (argc < 2)
		return (0);
	if (argc == 2 && ft_strcmp(type, "mandelbrot"))
		return (1);
	if (argc == 4 && ft_strcmp(type, "julia"))
		return (2);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_mlx	mlx;
	int		type;

	type = validate_type(argc, argv[1]);
	if (!type)
		close(-1);
	if (!window_init(&mlx))
		return (0);
	put_pixel(&mlx.img, type, argv);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win, mlx.img.img_ptr, 0, 0);
	mlx_hook(mlx.win, X_EVENT_KEY_PRESS, 0, key_press, 0);
	mlx_hook(mlx.win, X_EVENT_KEY_EXIT, 0, close, 0);
	mlx_hook(mlx.win, 4, 1, handle_mouse_scroll, &frac);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
