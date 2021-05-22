#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

int main()
{
	long long src[] = {1, 2, 3, 4, 5, 900719925474099999};
	long long dst[16];

	memcpy(dst, src, sizeof(long long) * 10);
	// ft_memcpy(dst, src, sizeof(long long) * 10);

	for (int i = 0; i < 10; i++)
	{
		printf("%d : %lld\n", i, dst[i]);
	}

	return 0;
}
