/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_un.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 19:38:48 by sungmcho          #+#    #+#             */
/*   Updated: 2021/08/25 19:39:37 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_un(va_list *args)
{
	unsigned int	c;

	c = va_arg(*args, unsigned int);
	ft_putnbr_fd(c, 1);
}
