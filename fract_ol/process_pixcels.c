/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_pixcels.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:05:00 by sungmcho          #+#    #+#             */
/*   Updated: 2021/12/09 18:42:54 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->data + (x * img->bpp / 8) + (y * img->size_l);
	*(unsigned int *)dst = color;
}

static int	color_set(int iter)
{
	int	color;

	color = (255 - iter / 10) * 0x10000 + 10 * iter * 0x100 + 20 * (iter / 20);
	return (color);
}

void	put_pixel(t_img *img, int type, char *argv[])
{
	int	iter;
	int	color;
	int	count_w;
	int	count_h;

	count_h = -1;
	while (++count_h <= WIN_HEIGHT)
	{
		count_w = -1;
		while (++count_w <= WIN_WIDTH)
		{
			if (type == 1)
				iter = mandelbrot(count_w, count_h, 0);
			else
				iter = julia(count_w, count_h, 0, argv);
			if (iter < ITER_MAX)
			{
				color = color_set(iter);
				my_mlx_pixel_put(img, count_w, count_h, color);
			}
			else
				my_mlx_pixel_put(img, count_w, count_h, 0x00000000);
		}
	}
}
