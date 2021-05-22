/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 12:00:33 by sungmcho          #+#    #+#             */
/*   Updated: 2021/05/07 15:53:07 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h";

size_t	ft_strlcat(char * restrict dst, const char * restrict src, unsigned int dstsize)
{
	unsigned int index;
	unsigned int dst_len;
	unsigned int src_len;

	index = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dst_len + 1 > dstsize)
		return (dst_len + dstsize - 1);
	else
	{
		while (dst_len + index + 1 < dstsize)
		{
			dst[dst_len + index] = src[index];
			index++;
		}
		dst[dst_len + index] = '\0';
		return (dst_len + src_len);
	}
}
