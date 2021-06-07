/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 16:19:23 by sungmcho          #+#    #+#             */
/*   Updated: 2021/06/07 20:18:59 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

char		**ft_split(char const *s, char c)
{
	char	**rslt;
	size_t	idx;
	size_t	word_counts;

	idx = 0;
	word_counts = 0;
	while (s[idx])
	{
		if (s[idx + 1] != c && s[idx] == c)
			word_counts++;
		idx++;
	}
	if (!word_counts)
	{
		rslt = (char **)malloc(2);
		if (!rslt)
			return (NULL);
		rslt[0] = "";
		rslt[1] = "\0";
		return (rslt);
	}
	return (NULL);
}
