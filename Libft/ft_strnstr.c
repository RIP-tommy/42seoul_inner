/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 16:11:15 by sungmcho          #+#    #+#             */
/*   Updated: 2021/06/12 19:37:49 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		start;
	int		idx;
	char	*h_temp;
	char	*n_temp;

	start = -1;
	idx = 0;
	h_temp = (char *)haystack;
	n_temp = (char *)needle;
	if (n_temp[0] == '\0')
		return (h_temp);
	while (++start < (int)len && h_temp[start])
	{
		if (h_temp[start] == n_temp[0])
			while (n_temp[++idx] && start + idx < (int)len)
				if (h_temp[start + idx] != n_temp[idx])
				{
					return (NULL);
					break ;
				}
		if (!n_temp[idx])
			return (h_temp + start);
	}
	return (NULL);
}
