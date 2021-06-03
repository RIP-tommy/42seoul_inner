/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 21:27:14 by sungmcho          #+#    #+#             */
/*   Updated: 2021/06/02 21:27:46 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char	*temp;
// 	size_t	idx;

// 	idx = 0;
// 	temp = (char *)malloc(len - (size_t)start);
// 	if (!temp)
// 		return (NULL);
// 	while (idx < len)
// 	{
// 		temp[idx] = s[(size_t)start + idx];
// 		idx++;
// 	}
// 	return (temp);
// }
