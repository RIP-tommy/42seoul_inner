#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
	char BUFFER[BUFFER_SIZE];
	static char *BUFFER_backup;

	if (read(fd, BUFFER, BUFFER_SIZE) > 0)
	{
		if (!strchr(BUFFER, '\n'))
		{
			BUFFER_backup = (char *)malloc(BUFFER_SIZE + 1);
			if (!BUFFER_backup)
				return (0);
			strlcat(BUFFER_backup, BUFFER, ft_strlen(BUFFER_backup) + BUFFER_SIZE +1);
		}
		else
		{
			BUFFER_backup = (char *)malloc(ft_strlen(BUFFER_backup) + BUFFER_SIZE + 1);
			if (!BUFFER_backup)
				return (0);
			strlcat(BUFFER_backup, BUFFER, ft_strlen(BUFFER_backup) + BUFFER_SIZE +1);
			*line = (char *)malloc(ft_strlen(BUFFER_backup) + BUFFER_SIZE + 1);
			if (!*line) {
				return (0);
			}
			strlcpy(*line, BUFFER_backup, 9);
		}
		return (1);
	}
	else if (read(fd, line[0], BUFFER_SIZE) == 0)
	{
		return (0);
	}
	else
		return (-1);
}
