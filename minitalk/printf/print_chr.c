/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_chr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 18:27:09 by sungmcho          #+#    #+#             */
/*   Updated: 2021/09/09 15:20:34 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

void	print_chr(va_list *args, int *res)
{
	char	c;

	c = va_arg(*args, int);
	ft_putchar_fd(c, 1, res);
}
