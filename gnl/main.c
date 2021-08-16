#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*line;

	line = 0;
	fd = open("/Users/sm/inner/gnl/line", O_RDONLY);
	while (1)
	{
		/* line = get_next_line(300); */
		line = get_next_line(fd);
		if (!line)
		{
			printf("line has a null value\n");
			break ;
		}
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
