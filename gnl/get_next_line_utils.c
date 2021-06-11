/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 15:02:00 by sungmcho          #+#    #+#             */
/*   Updated: 2021/06/11 17:01:51 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t		ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}

size_t		ft_strlcat(char *dst, char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;
	size_t	j;

	j = 0;
	while (j < size && dst[j])
		j++;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = 0;
	if (size >= dst_len)
	{
		while (i < src_len && dst_len + i + 1 < size)
		{
			dst[dst_len + i] = src[i];
			i++;
		}
		dst[dst_len + i] = '\0';
	}
	return (j + src_len);
}

size_t		ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	index;
	char	*dst_temp;
	char	*src_temp;

	if (!dstsize)
		return (ft_strlen(src));
	index = 0;
	dst_temp = (char *)dst;
	src_temp = (char *)src;
	while (index + 1 < dstsize && src[index])
	{
		dst_temp[index] = src_temp[index];
		index++;
	}
	dst_temp[index] = '\0';
	return (ft_strlen(src));
}

char		*ft_strchr(char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == c)
			return ((char *)str);
		++str;
	}
	if (c == '\0')
		return ((char *)str);
	return (0);
}
