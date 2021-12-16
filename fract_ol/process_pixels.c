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

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->data_ptr + \
	(y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	coloring_pixel(t_frac_data *frac, t_d_pair p, int i, int j)
{
	int	val;

	if (frac->f_flag == 1)
	{
		val = mandelbrot(p);
		if (val != LOOP_LIMIT)
			my_mlx_pixel_put(&frac->img, i, j, \
			(255 - val / 10) * 0x10000 + 10 * val * 0x100 + 20 * (val / 20));
		if (val == LOOP_LIMIT)
			my_mlx_pixel_put(&frac->img, i, j, 0);
	}
	else if (frac->f_flag == 2)
	{
		val = julia(p, frac->julia_comp);
		if (val != LOOP_LIMIT)
			my_mlx_pixel_put(&frac->img, i, j, \
			20 * (val / 16) * 0x10000 + 16 * val * 0x100 + (255 - val / 16));
		if (val == LOOP_LIMIT)
			my_mlx_pixel_put(&frac->img, i, j, 0);
	}
}

void	draw_frac(t_frac_data *frac)
{
	int			i;
	int			j;
	t_d_pair	p;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < LENGTH)
		{
			p.x = frac->center.x + (double)i / frac->pixel - frac->w_l.x / 2;
			p.y = frac->center.y + (double)j / frac->pixel - frac->w_l.y / 2;
			coloring_pixel(frac, p, i, j);
			j++;
		}
		i++;
	}
}
