/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 22:31:32 by sungmcho          #+#    #+#             */
/*   Updated: 2021/07/06 18:04:53 by sungmcho         ###   ########.fr       */
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

static int	nl_idx(char *str)
{
	int index;

	index = 0;
	while (str[index] != '\n')
		index++;
	return (index);
}

int	get_next_line(int fd, char **line)
{
	static char	*fds[OPEN_MAX];
	char		buffer[BUFFER_SIZE + 1];
	char		*temp;
	int			r_r;

	if (!fds[fd])
		fds[fd] = ft_strdup("");
	while (1)
	{
		r_r = read(fd, buffer, BUFFER_SIZE);
		buffer[BUFFER_SIZE] = '\0';
		if (r_r > 0 && (r_r < BUFFER_SIZE))
			*line = ft_strjoin(fds[fd], buffer, r_r);
		else if (r_r > 0 && ft_strchr(buffer) == 0)
			fds[fd] = ft_strjoin(fds[fd], buffer, r_r);
		else if (r_r > 0 && ft_strchr(buffer))
		{
			*line = ft_strjoin(fds[fd], buffer, nl_idx(buffer));
			fds[fd] = ft_strdup(ft_strchr(buffer) + 1);
			return (1);
		}
		else if (r_r == 0)
			return (0);
		else
			break ;
	}
	return (-1);
}
