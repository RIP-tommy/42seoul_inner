/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:42:58 by sungmcho          #+#    #+#             */
/*   Updated: 2021/12/09 19:10:26 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(int count_w, int count_h, int iter, char *argv[])
{
	double	c_re;
	double	c_im;
	double	x;
	double	x_new;
	double	y;

	c_re = ft_atod(argv[2]);
	c_im = ft_atod(argv[3]);
	x = ((count_w - WIN_WIDTH / 2) * 4.0 / WIN_WIDTH);
	y = ((WIN_HEIGHT / 2) - count_h) * 4.0 / WIN_HEIGHT;
	while ((x * x + y * y < 4) && (iter < ITER_MAX))
	{
		x_new = x * x - y * y + c_re;
		y = 2 * x * y + c_im;
		x = x_new;
		iter++;
	}
	return (iter);
}
