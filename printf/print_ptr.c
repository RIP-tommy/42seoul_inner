/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:21:17 by sungmcho          #+#    #+#             */
/*   Updated: 2022/01/13 14:29:19 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

void	print_ptr(va_list *args, int *res)
{
	void	*c;

	c = va_arg(*args, void *);
	if (!c)
	{
		ft_putstr_fd("(nil)", 1, res);
	}
	else
	{
		ft_putstr_fd("0x", 1, res);
		itoh((unsigned long long)c, 0, res);
	}
}
