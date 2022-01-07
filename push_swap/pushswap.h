#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_pushswap {
	int	*stack_a;
	int	*stack_b;
}	t_pushswap;

int	main(int ac, char **argv);

#endif