/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 18:02:39 by sungmcho          #+#    #+#             */
/*   Updated: 2021/06/02 14:15:23 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			idx;
	unsigned char	*src_temp;
	unsigned char	*dst_temp;

	idx = 0;
	src_temp = (unsigned char *)src;
	dst_temp = (unsigned char *)dst;
	while (idx < len)
	{
		dst_temp[idx] = src_temp[idx];
		idx++;
	}
	return (dst);
}
