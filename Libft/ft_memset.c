/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 15:40:28 by sungmcho          #+#    #+#             */
/*   Updated: 2021/05/14 15:58:00 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int				i;
	unsigned char	*dst;

	i = 0;
	dst = (unsigned char *)b;
	while (i < len)
	{
		dst[i] = (unsigned char)c;
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
