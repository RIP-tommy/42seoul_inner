#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

//struct      s_list {
  //  void    *content;
   // s_list  *next;
//}           t_list;

int			get_next_line(int fd, char **line);

#endif
