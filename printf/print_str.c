/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:21:26 by sungmcho          #+#    #+#             */
/*   Updated: 2022/01/14 16:56:51 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

void	print_str(va_list *args, int *res)
{
	char	*c;

	c = va_arg(*args, char *);
	ft_printf_print_str(c, 1, res);
}
