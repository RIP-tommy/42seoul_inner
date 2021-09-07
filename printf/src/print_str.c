#include "../ft_printf.h"

void	print_str(va_list *args)
{
	char	*c;

	c = va_arg(*args, char *);
	ft_putstr_fd(c, 1);
}
