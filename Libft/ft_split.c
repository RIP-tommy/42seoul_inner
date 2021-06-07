/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 16:19:23 by sungmcho          #+#    #+#             */
/*   Updated: 2021/06/07 17:40:16 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

size_t		counter(char const *s, char c)
{
	size_t	count;
	int		idx;

	idx = -1;
	count = 0;
	if (s[idx] != c)
	{
		idx++;
		count++;
	}
	while (s[++idx])
		if (s[idx] != c && s[idx - 1] == c)
			count++;
	return (count);
}

size_t		get_max_len(char const *s, char c)
{
	int		idx;
	size_t	max_len;
	size_t	start;

	idx = -1;
	if (s[0] == c)
		start = 1;
	else
		start = 0;
	max_len = 0;
	while (s[++idx])
	{
		if (s[idx] != c && s[idx - 1] == c)
			start = idx;
		else if (s[idx] != c && s[idx + 1] == c)
			if (max_len < (size_t)idx - start + 1)
				max_len = (size_t)idx - start + 1;
	}
	return (max_len);
}

char		*slicer(char const *s, size_t start, size_t end)
{
	char	*rslt;

	rslt = (char *)malloc(end - start + 1);
	if (!rslt)
		return (NULL);
	ft_strlcpy(rslt, (s + start), (end - start + 1));
	return (rslt);
}

char		**ft_split(char const *s, char c)
{
	char	**rslt;
	char	*temp;
	int		idx;
	int		idx2;
	size_t	start;

	idx = -1;
	idx2 = 0;
	start = 0;
	if (!get_max_len(s, c))
		return (NULL);
	if (!(counter(s, c)))
		return ((char **)s);
	rslt = (char **)malloc(get_max_len(s, c) * (counter(s, c) + 1));
	if (!rslt)
		return (NULL);
	while (s[++idx])
	{
		if (s[idx - 1] == c && s[idx] != c)
			start = idx;
		else if (s[idx] != c && s[idx + 1] == c)
		{
			temp = slicer(s, start, idx + 1);
			rslt[idx2++] = temp;
		}
	}
	return (rslt);
}
