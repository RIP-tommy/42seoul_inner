/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 15:52:09 by sungmcho          #+#    #+#             */
/*   Updated: 2021/06/02 16:08:35 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		idx;
	char	*temp;

	idx = ft_strlen(s) - 1;
	temp = (char *)s;
	if (c == '\0')
		return (temp = "\0");
	while (idx > -1)
	{
		if (temp[idx] == c)
			return (temp + idx);
		idx--;
	}
	return (NULL);
}
