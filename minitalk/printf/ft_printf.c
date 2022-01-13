/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:34:55 by sungmcho          #+#    #+#             */
/*   Updated: 2021/09/09 18:34:11 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

void	formatter(char c, va_list *args, int *res)
{
	if (c == 'c')
		print_chr(args, res);
	if (c == 's')
		print_str(args, res);
	if (c == 'p')
		print_ptr(args, res);
	if (c == 'i' || c == 'd')
		print_int(args, res);
	if (c == 'u')
		print_un(args, res);
	if (c == 'x')
		print_hex(args, 0, res);
	if (c == 'X')
		print_hex(args, 1, res);
	if (c == '%')
		ft_putchar_fd(c, 1, res);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	va_list	*ptr;
	int		res;

	res = 0;
	va_start(args, str);
	ptr = &args;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			formatter(*str, ptr, &res);
		}
		else
			ft_putchar_fd(*str, 1, &res);
		str++;
	}
	va_end(args);
	return (res);
}
