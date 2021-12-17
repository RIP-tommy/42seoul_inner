/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:15:23 by sungmcho          #+#    #+#             */
/*   Updated: 2021/12/16 23:35:23 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_d_pair	get_julia_para(int flag, char **argc)
{
	t_d_pair	ret;

	ret.x = 0;
	ret.y = 0;
	if (flag != 2)
		return (ret);
	ret.x = ft_atod(argc[2]);
	ret.y = ft_atod(argc[3]);
	return (ret);
}

static int	fract_ol_init(t_frac_data *frac, t_img *img, char **argv)
{
	frac->mlx = mlx_init();
	frac->win = mlx_new_window(frac->mlx, WIDTH, LENGTH, "fract_ol");
	img->img_ptr = mlx_new_image(frac->mlx, WIDTH, LENGTH);
	img->data_ptr = mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel, \
	&img->line_length, &img->endian);
	if (frac->mlx == 0 || frac->win == 0 || img->img_ptr == 0 || \
	img->data_ptr == 0)
	{
		write(2, "mlx error\n", 11);
		return (0);
	}
	frac->center.x = 0;
	frac->center.y = 0;
	frac->pixel = WIDTH / 4;
	frac->w_l.x = WIDTH / frac->pixel;
	frac->w_l.y = LENGTH / frac->pixel;
	frac->julia_comp = get_julia_para(frac->f_flag, argv);
	return (1);
}

static int	set_frac_flag(int argv, char **argc)
{
	if ((argv != 2 && argv != 4) || \
	(argv == 2 && !ft_strcmp(argc[1], "mandelbrot")) || \
	(argv == 4 && !ft_strcmp(argc[1], "julia")))
	{
		printf("valid paramater : \"mandelbrot\"");
		printf("or \"julia\", complex number\n");
		printf("recommend : julia -0.7 -0.27015\n");
		return (0);
	}
	if (ft_strcmp(argc[1], "mandelbrot"))
		return (1);
	else if (ft_strcmp(argc[1], "julia"))
		return (2);
	else
		return (3);
}

int	main(int argc, char *argv[])
{
	t_frac_data	frac;

	frac.f_flag = set_frac_flag(argc, argv);
	if (!fract_ol_init(&frac, &frac.img, argv) || !frac.f_flag)
		return (0);
	draw_frac(&frac);
	mlx_put_image_to_window(frac.mlx, frac.win, frac.img.img_ptr, 0, 0);
	mlx_key_hook(frac.win, &press_esc, 0);
	mlx_mouse_hook(frac.win, &press_wheel, &frac);
	mlx_loop(frac.mlx);
	return (0);
}
