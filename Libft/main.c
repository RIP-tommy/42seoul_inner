#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "libft.h"

size_t	ft_strlen(const char *src)
{
	size_t length;

	length = 0;
	while (src[length])
		length++;
	return (length);
}

char	*ft_strdup(const char *s1)
{
	size_t	idx;
	char	*temp;

	idx = 0;
	temp = (char *)malloc(ft_strlen(s1) + 1);
	if (!temp)
		return (NULL);
	while (s1[idx])
	{
		temp[idx] = s1[idx];
		idx++;
	}
	temp[idx] = '\0';
	return (temp);
}


size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	index;
	char	*dst_temp;
	char	*src_temp;

	if (!dstsize)
		return (ft_strlen(src));
	index = 0;
	dst_temp = (char *)dst;
	src_temp = (char *)src;
	while (index + 1 < dstsize && src[index])
	{
		dst_temp[index] = src_temp[index];
		index++;
	}
	dst_temp[index] = '\0';
	return (ft_strlen(src));
}

char		**ft_split(char const *s, char c)
{
	char	**rslt;
	size_t	idx;
	size_t	word_counts;

	idx = 0;
	word_counts = 0;
	while (s[idx])
	{
		if (s[idx + 1] != c && s[idx] == c)
			word_counts++;
		idx++;
	}
	if (!word_counts)
	{
		rslt = (char **)malloc(2);
		if (!rslt)
			return (NULL);
		rslt[0] = "";
		rslt[1] = "\0";
		return (rslt);
	}
	return (NULL);
}

int main()
{
	char **pString;

	// pString = ft_split("          ", ' ');
	// pString = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' ');
	// pString = ft_split("   lorem   ipsum dolor     sit amet, consectetur   adipiscing elit. Sed non risus. Suspendisse   ", ' ');
	// pString = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.", 'i');
	pString = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.", 'z');
	// pString = ft_split("", 'z');

	printf("pointer : %p\n", pString);
	printf("str 0 : %s", pString[0]);

	// for (size_t i = 0; i < counter("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.", 'z'); i++)
	// {
	// 	printf("%s\n", pString[i]);
	// }

	return 0;
}
