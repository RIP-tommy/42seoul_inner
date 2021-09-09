/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 12:10:27 by sungmcho          #+#    #+#             */
/*   Updated: 2021/09/09 15:08:50 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

size_t	ft_strlen(const char *src)
{
	size_t	length;

	if (!src)
		return (0);
	length = 0;
	while (src[length])
		length++;
	return (length);
}
