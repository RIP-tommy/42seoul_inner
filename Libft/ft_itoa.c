/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 16:14:28 by sungmcho          #+#    #+#             */
/*   Updated: 2021/06/13 18:19:28 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*print_min(void)
{
	return (ft_strdup("-2147483648"));
}

static char	*print_zero(void)
{
	return (ft_strdup("0"));
}

static char	*print_negative(int n, int count, int power)
{
	char	*rslt;
	int		idx;

	idx = 0;
	rslt = (char *)malloc(13 - count);
	if (!rslt)
		return (NULL);
	rslt[idx] = '-';
	idx++;
	while (n != 0)
	{
		rslt[idx] = (signed char)((n / power) + '0');
		n %= power;
		power /= 10;
		idx++;
	}
	while (idx < 12 - count)
	{
		rslt[idx] = '0';
		idx++;
	}
	rslt[idx] = '\0';
	return (rslt);
}

static char	*print_positive(int n, int count, int power)
{
	char	*rslt;
	int		idx;

	idx = 0;
	rslt = (char *)malloc(11 - count);
	if (!rslt)
		return (NULL);
	while (n != 0)
	{
		rslt[idx] = (signed char)((n / power) + '0');
		n %= power;
		power /= 10;
		idx++;
	}
	while (idx < 10 - count)
	{
		rslt[idx] = '0';
		idx++;
	}
	rslt[idx] = '\0';
	return (rslt);
}

char		*ft_itoa(int n)
{
	int		sign;
	int		count;
	int		power;

	count = 0;
	sign = 1;
	power = 1000000000;
	if (n == -2147483648)
		return (print_min());
	if (n == 0)
		return (print_zero());
	if (n < 0)
	{
		n *= -1;
		sign = 0;
		count++;
	}
	while (n < power)
	{
		power /= 10;
		count++;
	}
	if (sign)
		return (print_positive(n, count, power));
	return (print_negative(n, count, power));
}