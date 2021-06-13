/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 21:27:14 by sungmcho          #+#    #+#             */
/*   Updated: 2021/06/13 18:21:35 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*temp;
	size_t	idx;
	size_t	m_size;
	size_t	s_len;

	s_len = ft_strlen(s);
	if ((size_t)start >= s_len)
		return ((ft_strdup("")));
	if (s_len == 0)
		return (0);
	idx = 0;
	m_size = (s_len - start + 1 < len) ? s_len - start + 1 : len + 1;
	temp = (char *)malloc(m_size);
	if (!temp)
		return (NULL);
	while (idx < len && s[idx])
	{
		temp[idx] = s[start + (unsigned int)idx];
		idx++;
	}
	temp[len] = '\0';
	return (temp);
}
