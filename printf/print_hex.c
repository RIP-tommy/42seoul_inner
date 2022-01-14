/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 14:27:45 by sungmcho          #+#    #+#             */
/*   Updated: 2022/01/14 16:56:15 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

void	print_hex(va_list *args, int capitals, int *res)
{
	unsigned int	c;

	c = va_arg(*args, unsigned int);
	if (c == 0)
		ft_printf_print_nbr(0, res);
	else
		itoh(c, capitals, res);
}
