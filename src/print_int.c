/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 18:36:59 by sungmcho          #+#    #+#             */
/*   Updated: 2021/08/25 19:13:03 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_int(va_list *args)
{
	int	c;

	c = va_arg(*args, int);
	ft_putnbr_fd(c, 1);
}
