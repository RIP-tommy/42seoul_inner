/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 18:55:17 by sungmcho          #+#    #+#             */
/*   Updated: 2021/09/09 19:59:01 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

static void	print_dtoh(unsigned long long n, int capitals, int *res)
{
	char	c;

	if (n < 10)
		ft_putnbr_fd(n, res);
	else
	{
		if (capitals)
			c = 'A' + n - 10;
		else
			c = 'a' + n - 10;
		ft_putchar_fd(c, 1, res);
	}
}

static void	print(unsigned long long n, int capitals, int *res)
{
	unsigned long long	stored[17];
	int			i;

	i = 0;
	while (n != 0)
	{
		stored[i++] = n % 16;
		n /= 16;
	}
	i--;
	while (i > -1)
		print_dtoh(stored[i--], capitals, res);
}

void	itoh(unsigned long long n, int capitals, int *res)
{
	if (n < 0)
	{
		ft_putchar_fd('-', 1, res);
		n *= -1;
	}
	print(n, capitals, res);
}
