/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:21:17 by sungmcho          #+#    #+#             */
/*   Updated: 2022/01/14 16:58:34 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

void	print_ptr(va_list *args, int *res)
{
	void	*c;

	c = va_arg(*args, void *);
	ft_printf_print_str("0x", 1, res);
	if (!c)
		ft_printf_print_str("0", 1, res);
	else
		itoh((unsigned long long)c, 0, res);
}
