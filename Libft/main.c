#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			idx;
	unsigned char	*src_temp;
	unsigned char	*dst_temp;

	idx = 0;
	src_temp = (unsigned char *)src;
	dst_temp = (unsigned char *)dst;
	while (idx < len)
	{
		dst_temp[idx] = src_temp[idx];
		idx++;
	}
	return (dst);
}

int main()
{
	char src[] = "these string is a src string";
	char dst[99];

	printf("origin dst: %s\n", dst);

	// char *copied =  memmove(dst, src, 11);
	char *copied = ft_memmove(dst, src, 11);

	printf("%s\n", copied);
	printf("dst string length: %zu\n", strlen(dst));
	printf("%s\n", dst);

	// for (size_t i = 0; i < strlen(dst); i++) {
	// 	printf("%zu: %c\n", i, dst[i]);
	// }

	return 0;
}
