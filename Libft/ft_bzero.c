/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 13:54:20 by sungmcho          #+#    #+#             */
/*   Updated: 2021/05/14 17:11:05 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_bzero(void *s, size_t n)
{
	int i;
	char *temp;

	i = 0;
	temp = (char *)s;
	if (n == 0) ;
	else
	{
		while (i < n)
		{
			temp[i] = 0;
			i++;
		}
	}
	s = temp;
}
