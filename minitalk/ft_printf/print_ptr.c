/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:21:17 by sungmcho          #+#    #+#             */
/*   Updated: 2021/09/09 19:57:12 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

void	print_ptr(va_list *args, int *res)
{
	void	*c;

	c = va_arg(*args, void *);
	ft_putstr_fd("0x", 1, res);
	if (!c)
		ft_putchar_fd('0', 1, res);
	else
	{
		if (sizeof(void *) == 4)
			itoh((unsigned int)c, 0, res);
		else if (sizeof(void *) == 8)
			itoh((unsigned long long)c, 0, res);
	}
}
