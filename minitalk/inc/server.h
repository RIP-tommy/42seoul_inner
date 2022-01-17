#ifndef SERVER_H
# define SERVER_H

#include "../Libft/libft.h"
#include "../printf/ft_printf.h"

#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <stdlib.h>
#include <errno.h>

typedef struct s_msg_data {
    char    c;
    int     cnt;
}   t_msg_data;

int	main(void);

#endif
