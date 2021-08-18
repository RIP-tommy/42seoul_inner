/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 22:31:32 by sungmcho          #+#    #+#             */
/*   Updated: 2021/08/17 01:19:29 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*f_n(char *str)
{
	if (!str)
		return (0);
	while (*str != '\0')
	{
		if (*str == '\n')
			return (str);
		str++;
	}
	return (0);
}

static char	*split_new_line(char **s1)
{
	char	*res;
	char	*tmp;
	int		s1_len;
	int		size;

	s1_len = (int)ft_strlen(*s1);
	size = f_n(*s1) - *s1 + 1;
	res = ft_strdup(*s1, size);
	tmp = *s1;
	*s1 = ft_strdup(f_n(*s1) + 1, s1_len);
	free(tmp);
	return (res);
}

static char	*ret_val(char **s1)
{
	char	*res;

	if (f_n(*s1))
		return (split_new_line(s1));
	else
	{
		if (!**s1)
		{
			free(*s1);
			return (0);
		}
		res = ft_strdup(*s1, ft_strlen(*s1));
		free(*s1);
		*s1 = 0;
		return (res);
	}
}

char	*get_next_line(int fd)
{
	static char	*fds[OPEN_MAX];
	char		buffer[BUFFER_SIZE + 1];
	int			r_r;

	if ((fd < 0) || (BUFFER_SIZE <= 0))
		return (0);
	while (1)
	{
		r_r = read(fd, buffer, BUFFER_SIZE);
		if (r_r == 0)
			break ;
		if (r_r < 0)
			return (0);
		buffer[r_r] = '\0';
		fds[fd] = ft_strjoin(fds[fd], buffer, r_r);
		if (f_n(fds[fd]))
			return (split_new_line(&fds[fd]));
	}
	if (r_r < 1 && !fds[fd])
		return (0);
	return (ret_val(&fds[fd]));
}
