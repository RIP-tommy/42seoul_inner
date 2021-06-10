#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 8

# include <stddef.h>

int     get_next_line(int fd, char **line);
size_t  ft_strlen(char *s);

#endif
