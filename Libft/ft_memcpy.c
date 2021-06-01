/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 17:20:42 by sungmcho          #+#    #+#             */
/*   Updated: 2021/06/01 18:08:36 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void		*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	size_t			idx;
	unsigned char	*src_temp;
	unsigned char	*dst_temp;

	idx = 0;
	src_temp = (unsigned char *)src;
	dst_temp = (unsigned char *)dst;
	while (idx < n)
	{
		dst_temp[idx] = src_temp[idx];
		idx++;
	}
	return (dst);
}
