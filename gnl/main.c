#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int	main(int ac, char** av)
{
	int		fd;
	char	*line;

	line = 0;
	if (ac < 1) return 0;
	fd = open(av[1], O_RDONLY);
	while (1)
	{
		/* line = get_next_line(300); */
		line = get_next_line(fd);
		if (!*line)
		{
			break ;
		}
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
