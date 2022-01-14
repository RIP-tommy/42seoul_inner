/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:56:55 by sungmcho          #+#    #+#             */
/*   Updated: 2022/01/14 16:56:58 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

void	ft_printf_print_str(const char *s, int fd, int *res)
{
	size_t	len;

	if (!s)
	{
		write(fd, "(null)", 6);
		*res += 6;
	}
	else
	{
		len = ft_strlen(s);
		write(fd, s, len);
		*res += len;
	}
}
