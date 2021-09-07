/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 14:27:45 by sungmcho          #+#    #+#             */
/*   Updated: 2021/08/28 00:13:34 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	print_dtoh(long n)
{
	char	c;

	if (n < 10)
		ft_putnbr_fd(n, 1);
	else
	{
		c = 'a' + n - 10;
		ft_putchar_fd(c, 1);
	}
}

static void	print(long n)
{
	long	q;
	long	r;
	long	k;

	k = 1;
	if (n == 0)
		ft_putnbr_fd(0, 1);
	while (n >= k)
	{
		q = n;
		while (q >= k)
		{
			r = q % 16;
			q = q / 16;
		}
		print_dtoh(r);
		k *= 16;
	}
}

void	itoh(long n)
{
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		n *= -1;
	}
	print(n);
}

void	print_hex(va_list *args)
{
	long	c;

	c = va_arg(*args, long);
	itoh(c);
}
