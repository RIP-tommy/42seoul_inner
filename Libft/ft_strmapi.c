/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 15:43:01 by sungmcho          #+#    #+#             */
/*   Updated: 2021/06/12 15:48:19 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*rslt;
	unsigned int	idx;

	if (!(rslt = (char *)malloc(ft_strlen(s) + 1)))
		return (0);
	idx = 0;
	ft_strlcpy(rslt, s, (ft_strlen(s) + 1));
	while (rslt[idx])
	{
		rslt[idx] = f(idx, rslt[idx]);
		idx++;
	}
	rslt[idx] = 0;
	return (rslt);
}
