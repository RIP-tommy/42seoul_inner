#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>

int			get_next_line(int fd, char **line);
size_t		ft_strlen(char *s);
size_t		ft_strlcat(char *dst, char *src, size_t size);
size_t		ft_strlcpy(char *dst, char *src, size_t dstsize);
char		*ft_strchr(char *str, int c);

#endif
