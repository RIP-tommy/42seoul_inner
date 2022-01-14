/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_nbr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:56:21 by sungmcho          #+#    #+#             */
/*   Updated: 2022/01/14 16:58:00 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

static int	counter(long long n, int power)
{
	int	count;

	count = 0;
	while (n < (long long)power)
	{
		power /= 10;
		count++;
	}
	return (count);
}

static void	print(long long n, int power, int count, int *res)
{
	char	temp;

	while (n != 0)
	{
		temp = (n / power) + '0';
		ft_printf_print_char(temp, 1, res);
		n %= power;
		power /= 10;
		count--;
	}
	while (count != 0)
	{
		ft_printf_print_char('0', 1, res);
		count--;
	}
}

void	ft_printf_print_nbr(long long n, int *res)
{
	int		power;
	int		counts;

	power = 1000000000;
	if (n == -2147483648)
		ft_printf_print_str("-2147483648", 1, res);
	else if (n == 0)
		ft_printf_print_char('0', 1, res);
	else
	{
		if (n < 0)
		{
			n *= -1;
			ft_printf_print_char('-', 1, res);
		}
		counts = 10 - counter(n, power);
		while (n < (long long)power)
			power /= 10;
		print(n, power, counts, res);
	}
}
