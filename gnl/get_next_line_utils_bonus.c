/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 15:02:00 by sungmcho          #+#    #+#             */
/*   Updated: 2021/07/15 17:42:38 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *src)
{
	size_t	length;

	length = 0;
	while (src[length])
		length++;
	return (length);
}

static size_t	ft_strlcat(char *dst, const char *src, size_t size)
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

static size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
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

char	*ft_strjoin(char *s1, char *s2, int len)
{
	char	*rslt;
	int		s1_len;

	if (!(s1) && !(s2))
		return (NULL);
	else if (!(s1) || !(s2))
	{
		if (!(s1))
			return (ft_strdup(s2, ft_strlen(s2)));
		else
			return (ft_strdup(s1, s1_len));
	}
	s1_len = (int)ft_strlen(s1);
	rslt = (char *)malloc(s1_len + len + 1);
	if (!rslt)
		return (NULL);
	ft_strlcpy(rslt, s1, s1_len + 1);
	free(s1);
	ft_strlcat(rslt, s2, s1_len + len + 1);
	return (rslt);
}

char	*ft_strdup(const char *s1, int size)
{
	size_t	idx;
	char	*temp;

	idx = 0;
	temp = (char *)malloc(ft_strlen(s1) + 1);
	if (!temp)
		return (NULL);
	while (s1[idx] && idx < size)
	{
		temp[idx] = s1[idx];
		idx++;
	}
	temp[idx] = '\0';
	return (temp);
}
