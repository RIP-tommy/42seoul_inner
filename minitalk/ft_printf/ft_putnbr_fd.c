/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 16:12:19 by sungmcho          #+#    #+#             */
/*   Updated: 2021/09/09 20:23:07 by sungmcho         ###   ########.fr       */
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
		ft_putchar_fd(temp, 1, res);
		n %= power;
		power /= 10;
		count--;
	}
	while (count != 0)
	{
		ft_putchar_fd('0', 1, res);
		count--;
	}
}

void	ft_putnbr_fd(long long n, int *res)
{
	int		power;
	int		counts;

	power = 1000000000;
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", 1, res);
	else if (n == 0)
		ft_putchar_fd('0', 1, res);
	else
	{
		if (n < 0)
		{
			n *= -1;
			ft_putchar_fd('-', 1, res);
		}
		counts = 10 - counter(n, power);
		while (n < (long long)power)
			power /= 10;
		print(n, power, counts, res);
	}
}
