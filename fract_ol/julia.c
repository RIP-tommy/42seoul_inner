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

int	julia(t_d_pair p, t_d_pair j_p)
{
	int			i;
	t_d_pair	z;
	double		t;

	i = 0;
	z.x = p.x;
	z.y = p.y;
	while (z.x * z.x + z.y * z.y <= 4 && i < LOOP_LIMIT)
	{
		t = z.x * z.x - z.y * z.y + j_p.x;
		z.y = 2 * z.x * z.y + j_p.y;
		z.x = t;
		i++;
	}
	return (i);
}
