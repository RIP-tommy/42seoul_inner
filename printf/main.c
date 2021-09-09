#include <stdio.h>
#include "./ft_printf.h"
#include <limits.h>

int main()
{
	int ml29 =    ft_printf("%p\n", (void *)-1	);
	int pl29 =       printf("%p\n", (void *)-1	);
	printf("%d, %d\n", ml29, pl29);

	int ml30 =    ft_printf("%X\n", LONG_MAX	);
	int pl30 =       printf("%X\n", LONG_MAX	);
	printf("%d, %d\n", ml30, pl30);

	int ml31 =    ft_printf("%x\n", LONG_MAX	);
	int pl31 =       printf("%x\n", LONG_MAX	);
	printf("%d, %d\n", ml31, pl31);

	return 0;
}
