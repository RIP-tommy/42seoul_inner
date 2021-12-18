/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 17:44:37 by sungmcho          #+#    #+#             */
/*   Updated: 2021/12/18 17:54:58 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	check_sign(char c)
{
	if (c == '+')
		return (1.0);
	else if (c == '-')
		return (-1.0);
	else
		return (0.0);
}

static double	get_point(int cnt)
{
	double	ret;

	ret = 1.0;
	while (cnt--)
		ret *= 0.1;
	return (ret);
}

double	ft_atod(char *str)
{
	double	sign;
	int		dots;
	int		cnt;
	double	ret;

	ret = 0.0;
	dots = 0;
	cnt = 1;
	sign = check_sign(*str);
	while (ft_isdigit(*(++str)) != 0 && dots < 2)
	{
		if (*str == '.')
			dots++;
		else
		{
			if (dots == 0)
				ret = ret * 10 + (*str - '0');
			else
			{
				ret += (*str - '0') * get_point(cnt);
				cnt++;
			}
		}
	}
	return (sign * ret);
}
