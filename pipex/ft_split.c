/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 16:19:23 by sungmcho          #+#    #+#             */
/*   Updated: 2021/06/19 16:10:49 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_memfree(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (-1);
}

static int	c_w(char const *s, char c)
{
	int				counts;
	int				word_in;
	int				idx;

	counts = 0;
	word_in = 0;
	idx = -1;
	while (s[++idx])
	{
		if (s[idx] == c)
		{
			if (word_in)
			{
				word_in = 0;
				counts++;
			}
		}
		else
			word_in = 1;
	}
	if (word_in)
		counts++;
	return (counts);
}

static int	split(char const *s, char c, char ***rslt)
{
	char	*break_point;
	size_t	i;
	size_t	len;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			break_point = (char *)s;
			while (*s && *s != c)
				++s;
			len = s - break_point + 1;
			(*rslt)[i] = (char *)malloc(len);
			if (!(*rslt)[i])
				return (ft_memfree(*rslt));
			ft_strlcpy((*rslt)[i++], break_point, len);
		}
		else
			++s;
	}
	(*rslt)[i] = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**rslt;

	rslt = (char **)malloc(sizeof(char *) * (c_w(s, c) + 1));
	if (!rslt)
		return (NULL);
	if (split(s, c, &rslt) == -1)
		return (NULL);
	return (rslt);
}
