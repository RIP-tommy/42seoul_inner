/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_chr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 18:27:09 by sungmcho          #+#    #+#             */
/*   Updated: 2022/01/14 16:55:22 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

void	print_chr(va_list *args, int *res)
{
	char	c;

	c = va_arg(*args, int);
	ft_printf_print_char(c, 1, res);
}
