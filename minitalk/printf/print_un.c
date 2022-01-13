/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_un.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 19:38:48 by sungmcho          #+#    #+#             */
/*   Updated: 2021/09/09 20:10:53 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

void	print_un(va_list *args, int *res)
{
	unsigned int	c;

	c = va_arg(*args, unsigned int);
	ft_putnbr_fd(c, res);
}
