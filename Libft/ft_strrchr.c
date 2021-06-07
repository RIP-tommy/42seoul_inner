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

#include <stddef.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	idx;
	char	*temp;

	idx = ft_strlen(s);
	temp = (char *) s;
	if (!c)
		return (temp + idx);
	while (idx != (size_t)-1)
	{
		if (temp[idx] == c)
			return (temp + idx);
		idx--;
	}
	return (NULL);
}
