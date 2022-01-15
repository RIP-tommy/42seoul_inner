/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 18:36:59 by sungmcho          #+#    #+#             */
/*   Updated: 2022/01/14 16:56:15 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

void	print_int(va_list *args, int *res)
{
	int	c;

	c = va_arg(*args, int);
	ft_printf_print_nbr(c, res);
}
