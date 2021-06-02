/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 17:34:30 by sungmcho          #+#    #+#             */
/*   Updated: 2021/06/02 17:40:17 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>


int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	idx;
	char	*s1_temp;
	char	*s2_temp;

	idx = 0;
	s1_temp = (char *)s1;
	s2_temp = (char *)s2;
	while (s1_temp[idx] && s2_temp[idx] && n > 0)
	{
		if (s1_temp[idx] != s2_temp[idx])
			break ;
		idx++;
		n--;
	}
	if (n == 0)
		return (0);
	return (s1_temp[idx] - s2_temp[idx]);
}
