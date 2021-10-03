#include "./ft_printf/ft_printf.h"
#include <signal.h>

int	main(void)
{
	char	*s1;

	ft_printf("d\n", getpid());
	return (0);
}
