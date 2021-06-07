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

size_t	counter(char const *s, char c)
{
	size_t	count;
	size_t	idx;

	idx = -1;
	count = 0;
	while (s[++idx])
		if (s[idx] == c)
			count++;
	return (count + 1);
}

size_t	get_max_len(char const *s, char c)
{
	size_t	max_len;
	size_t	str_len;
	size_t	idx;
	size_t	start;

	idx = 0;
	start = 0;
	max_len = 0;
	str_len = ft_strlen(s);
	while (s[idx++])
	{
		if (s[idx] == c)
		{
			if (max_len < idx - start)
				max_len = idx - start;
			start = idx + 1;
		}
	}
	if (max_len < str_len - start)
		max_len = str_len - start;
	return (max_len);
}

char	*slicer(char const *s, size_t start, size_t end)
{
	char	*rslt;

	rslt = (char *)malloc(end - start + 1);
	if (!rslt)
		return (NULL);
	ft_strlcpy(rslt, (s + start), (end - start + 1));
	return (rslt);
}

char	**ft_split(char const *s, char c)
{
	char	**rslt;
	char	*temp;
	size_t	idx;
	size_t	idx2;
	size_t	start;

	idx = -1;
	idx2 = 0;
	start = 0;
	rslt = (char **)malloc(get_max_len(s, c) * (counter(s, c) + 1));
	if (!rslt)
		return (NULL);
	while (s[++idx])
		if (s[idx] == c)
		{
			temp = slicer(s, start, idx);
			rslt[idx2++] = temp;
			start = idx + 1;
		}
	temp = slicer(s, start, idx);
	rslt[idx2] = temp;
	return (rslt);
}

int main()
{
	char **pString;
//	ft_split("          ", ' ');
//	pString = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' ');
//	ft_split("   lorem   ipsum dolor     sit amet, consectetur   adipiscing elit. Sed non risus. Suspendisse   ", ' ');
//	ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.", 'i');
//	ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.", 'z');

	for (size_t i = 0; i < 13; i++)
	{
		printf("%s\n", pString[i]);
	}

	return 0;
}
