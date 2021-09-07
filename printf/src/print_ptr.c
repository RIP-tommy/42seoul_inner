#include "../ft_printf.h"

void	print_ptr(va_list *args)
{
	long	c;

	c = va_arg(*args, long);
	ft_putstr_fd("0x", 1);
	itoh(c);
}
