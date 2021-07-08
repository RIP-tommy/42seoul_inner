#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int	main(int ac, char **av)
{
	int		temp;
	int		fd;
	char	*line;

	fd = open(av[1], O_RDONLY);
	while (line = get_next_line(fd))
	{
		if (*line == NULL)
			break;
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	return (0);
}
