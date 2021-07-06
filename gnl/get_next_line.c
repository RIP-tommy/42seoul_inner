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

int	nl_idx(char *str)
{
	int idx;

	idx = 0;
	while (str[idx] == '\n')
		idx++;
	return (idx);
}

int	get_next_line(int fd, char **line)
{
	static char	*fds[OPEN_MAX];
	char		buffer[BUFFER_SIZE + 1];
	int			read_result;
	char		*temp;

	read_result = read(fd, buffer, BUFFER_SIZE);
	buffer[BUFFER_SIZE] = '\0';
	if (read_result > 0)
	{
		temp = ft_strchr(buffer);
		fds[fd] = ft_strdup("");
		if (!temp)
			fds[fd] = ft_strjoin(fds[fd], buffer, BUFFER_SIZE);
		else
			*line = ft_strjoin(fds[fd], buffer, BUFFER_SIZE);
		return (1);
	}
	else if (read_result == 0)
		return (0);
	else
		return (-1);
}
