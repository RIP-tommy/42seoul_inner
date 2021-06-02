#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*temp;
	size_t	idx;

	idx = 0;
	temp = (char *)malloc(len - (size_t)start +1);
	if (!temp)
		return (NULL);
	while (idx < len)
	{
		temp[idx] = s[(size_t)start + idx];
		idx++;
	}
	return (temp);
}

int main()
{
	char s[] = "Hello World!";

	printf("%s", ft_substr(s, 1, 5));
}
