/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 16:12:22 by sungmcho          #+#    #+#             */
/*   Updated: 2021/09/09 15:18:56 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

void	ft_putstr_fd(const char *s, int fd, int *res)
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
