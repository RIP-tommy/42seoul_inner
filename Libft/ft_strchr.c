/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 15:51:42 by sungmcho          #+#    #+#             */
/*   Updated: 2021/06/02 16:05:13 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	int		idx;
	char	*temp;

	idx = 0;
	temp = (char *)s;
	if (c == '\0')
		return (temp = "\0");
	while (temp[idx])
	{
		if (temp[idx] == c)
			return (temp + idx);
		idx++;
	}
	return (NULL);
}
