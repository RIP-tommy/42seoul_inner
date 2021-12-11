/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:13:45 by sungmcho          #+#    #+#             */
/*   Updated: 2021/12/09 16:15:47 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_d_pair p)
{
	int			i;
	t_d_pair	z;
	double		t;

	i = 0;
	z.x = p.x;
	z.y = p.y;
	while (z.x * z.x + z.y * z.y <= 4 && i < LOOP_LIMIT)
	{
		t = z.x * z.x - z.y * z.y + p.x;
		z.y = 2 * z.x * z.y + p.y;
		z.x = t;
		i++;
	}
	return (i);
}
