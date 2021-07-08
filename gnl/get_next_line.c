/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 22:31:32 by sungmcho          #+#    #+#             */
/*   Updated: 2021/07/08 20:14:42 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static	char	*ft_strdup(const char *s1)
{
	size_t	idx;
	char	*temp;

	idx = 0;
	temp = (char *)malloc(ft_strlen(s1) + 1);
	if (!temp)
		return (NULL);
	while (s1[idx])
	{
		temp[idx] = s1[idx];
		idx++;
	}
	temp[idx] = '\0';
	return (temp);
}

static char	*ft_strchr(char *str)
{
	while (*str != '\0')
	{
		if (*str == '\n')
			return (str);
		++str;
	}
	return (0);
}

static int	nl_idx(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\n')
		index++;
	return (index);
}

char	*ret_val(char **s1)
{
	char	*res;

	res = ft_strjoin(ft_strdup(""), *s1, nl_idx(*s1));
	*s1 = ft_strdup(ft_strchr(*s1) + 1);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*fds[OPEN_MAX];
	char		buffer[BUFFER_SIZE + 1];
	char		*temp;
	int			r_r;

	if (!fds[fd])
		fds[fd] = ft_strdup("");
	if (ft_strchr(fds[fd]))
		return (ret_val(&fds[fd]));
	while (!ft_strchr(buffer))
	{
		r_r = read(fd, buffer, BUFFER_SIZE);
		if (!r_r)
		{
			temp = fds[fd];
			fds[fd] = 0;
			return (temp);
		}
		buffer[BUFFER_SIZE] = '\0';
		fds[fd] = ft_strjoin(fds[fd], buffer, r_r);
	}
	return (ret_val(&fds[fd]));
}
