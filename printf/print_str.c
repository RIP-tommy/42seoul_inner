/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:21:26 by sungmcho          #+#    #+#             */
/*   Updated: 2021/09/09 15:21:02 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

void	print_str(va_list *args, int *res)
{
	char	*c;

	c = va_arg(*args, char *);
	ft_putstr_fd(c, 1, res);
}
