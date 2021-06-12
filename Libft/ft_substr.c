/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 21:27:14 by sungmcho          #+#    #+#             */
/*   Updated: 2021/06/12 16:30:02 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*temp;
	size_t	idx;

	if (start >= ft_strlen(s))
		return ((ft_strdup("")));
	if (ft_strlen(s) == 0)
		return (0);
	idx = 0;
	temp = (char *)malloc(len + 1);
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
