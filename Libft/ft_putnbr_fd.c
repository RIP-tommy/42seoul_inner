/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 16:12:19 by sungmcho          #+#    #+#             */
/*   Updated: 2021/06/07 16:12:19 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	int		power;
	char	temp;

	power = 1000000000;
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n == 0)
		write(fd, "0", 1);
	else
	{
		if (n < 0)
		{
			n *= -1;
			write(fd, "-", 1);
		}
		while (n < power)
			power /= 10;
		while (n != 0)
		{
			temp = (n / power) + '0';
			write(fd, &(temp), 1);
			n %= power;
			power /= 10;
		}
	}
}
