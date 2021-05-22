/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 17:20:42 by sungmcho          #+#    #+#             */
/*   Updated: 2021/05/22 21:41:01 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	size_t			i;
	unsigned char	*src_temp;
	unsigned char	*dst_temp;

	i = 0;
	src_temp = (unsigned char *)src;
	dst_temp = (unsigned char *)dst;
	while (i < n)
	{
		dst_temp[i] = src_temp[i];
		i++;
	}
	return (dst_temp);
}
