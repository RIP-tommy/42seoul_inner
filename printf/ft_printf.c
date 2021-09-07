/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:34:55 by sungmcho          #+#    #+#             */
/*   Updated: 2021/08/27 14:50:59 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	formatter(char c, va_list *args)
{
	if (c == 'c')
		print_chr(args);
	if (c == 's')
		print_str(args);
	if (c == 'p')
		print_ptr(args);
	if (c == 'i' || c == 'd')
		print_int(args);
	if (c == 'u')
		print_un(args);
	if (c == 'x')
		print_hex(args);
	if (c == '%')
		ft_putchar_fd(c, 1);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	va_list	*ptr;

	va_start(args, str);
	ptr = &args;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			formatter(*str, ptr);
		}
		else
			ft_putchar_fd(*str, 1);
		str++;
	}
	va_end(args);
	return (1);
}
