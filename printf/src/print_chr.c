/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_chr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 18:27:09 by sungmcho          #+#    #+#             */
/*   Updated: 2021/08/25 19:12:43 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	print_chr(va_list *args)
{
	char	c;

	c = va_arg(*args, int);
	ft_putchar_fd(c, 1);
}
