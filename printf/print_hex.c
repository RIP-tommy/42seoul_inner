/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 14:27:45 by sungmcho          #+#    #+#             */
/*   Updated: 2021/09/09 18:55:30 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

void	print_hex(va_list *args, int capitals, int *res)
{
	unsigned int	c;

	c = va_arg(*args, unsigned int);
	if (c == 0)
		ft_putnbr_fd(0, res);
	else
		itoh(c, capitals, res);
}
