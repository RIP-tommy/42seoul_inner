/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_un.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 19:38:48 by sungmcho          #+#    #+#             */
/*   Updated: 2022/01/14 16:56:15 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

void	print_un(va_list *args, int *res)
{
	unsigned int	c;

	c = va_arg(*args, unsigned int);
	ft_printf_print_nbr(c, res);
}
