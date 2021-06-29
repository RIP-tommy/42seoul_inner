/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 22:31:32 by sungmcho          #+#    #+#             */
/*   Updated: 2021/06/29 22:35:12 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			get_next_line(int fd, char **line)
{
	char	*temp;
	int		rslt;

	if (!(temp = (char *)malloc(BUFFER_SIZE)))
		return (-1);
	rslt = read(fd, temp, BUFFER_SIZE);
	if (rslt > 0)
	{
		write(1, temp, BUFFER_SIZE);
		return (1);
	}
	else if (rslt == 0)
		return (0);
	else
		return (-1);
}
