/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 15:01:58 by sungmcho          #+#    #+#             */
/*   Updated: 2021/06/17 13:13:54 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "get_next_line.h"

void			backup_buffer()
{
	static char	*backup;


}

int				get_next_line(int fd, char **line)
{
	static char	buffer[BUFFER_SIZE];
	char		*buffer_backup;
	char *temp = NULL;

	if (BUFFER_SIZE < 1)
		return (-1);
	if (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		if (temp[0])
			return 0;
		buffer_backup = (char *)malloc(ft_strlen(buffer_backup) + BUFFER_SIZE + 1);
		// if (!buffer_backup)
		// 	return (-1);
		ft_strlcat(buffer_backup, buffer, ft_strlen(buffer_backup) + BUFFER_SIZE + 1);
		// if (!ft_strchr(buffer, '\n'))
		// {
		// 	if (buffer_backup)
		// 		buffer_backup = (char *)malloc(ft_strlen(buffer_backup) + BUFFER_SIZE + 1);
		// 	else
		// 		buffer_backup = (char *)malloc(BUFFER_SIZE + 1);
		// 	if (!buffer_backup)
		// 		return (-1);
		// 	ft_strlcat(buffer_backup, buffer, ft_strlen(buffer_backup) + BUFFER_SIZE + 1);
		// }
		// else
		// {
		// 	if (buffer_backup)
		// 	{
		// 		*line = (char *)malloc(ft_strlen(buffer_backup) + (ft_strchr(buffer, '\n') - buffer) + 1);
		// 		if (!*line)
		// 			return (-1);
		// 		ft_strlcat(*line, buffer_backup, ft_strlen(buffer_backup) + 1);
		// 		ft_strlcat(*line, buffer, ft_strlen(buffer_backup) + ft_strchr(buffer, '\n') - buffer + 1);
		// 		free(buffer_backup);
		// 		buffer_backup = (char *)malloc((ft_strchr(buffer, '\n') - buffer));
		// 		if (!buffer_backup)
		// 			return (-1);
		// 		ft_strlcat(buffer_backup, ft_strchr(buffer, '\n') + 1, BUFFER_SIZE - (ft_strchr(buffer, '\n') - buffer));
		// 	}
		// 	else
		// 	{
		// 		*line = (char *)malloc((ft_strchr(buffer, '\n') - buffer) + 1);
		// 		if (!*line)
		// 			return (-1);
		// 		ft_strlcat(*line, buffer, (ft_strchr(buffer, '\n') - buffer));
		// 		buffer_backup = (char *)malloc(BUFFER_SIZE - (ft_strchr(buffer, '\n') - buffer));
		// 		if (!buffer_backup)
		// 			return (-1);
		// 		ft_strlcat(buffer_backup, ft_strchr(buffer, '\n') + 1, BUFFER_SIZE - (ft_strchr(buffer, '\n') - buffer));
		// 	}
		// }
		return (1);
	}
	else if (read(fd, line[0], BUFFER_SIZE) == 0)
		return (0);
	else
		return (-1);
}
