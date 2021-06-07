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
	int		idx;

	idx = -1;
	count = 0;
	if (s[idx] != c)
	{
		idx++;
		count++;
	}
	while (s[++idx])
		if (s[idx] != c && s[idx - 1] == c)
			count++;
	return (count);
}

size_t	get_max_len(char const *s, char c)
{
	size_t	max_len;
	int	idx;
	size_t	start;

	idx = -1;
	if (s[0] == c)
		start = 1;
	else
		start = 0;
	max_len = 0;
	while (s[++idx])
	{
		if (s[idx] != c && s[idx - 1] == c)
			start = idx;
		else if (s[idx] != c && s[idx + 1] == c)
			if (max_len < idx - start + 1)
				max_len = idx - start + 1;
	}
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
	int		idx;
	int		idx2;
	size_t	start;

	idx = -1;
	idx2 = 0;
	start = 0;
	if (!get_max_len(s, c))
		return (NULL);
	rslt = (char **)malloc(get_max_len(s, c) * (counter(s, c) + 1));
	if (!rslt)
		return (NULL);
	while (s[++idx])
	{
		if (s[idx - 1] == c && s[idx] != c)
			start = idx;
		else if (s[idx] != c && s[idx + 1] == c)
		{
			temp = slicer(s, start, idx + 1);
			rslt[idx2++] = temp;
		}
	}
	return (rslt);
}

int main()
{
	char **pString;
	// pString = ft_split("          ", ' ');
	// pString = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' ');
	// pString = ft_split("   lorem   ipsum dolor     sit amet, consectetur   adipiscing elit. Sed non risus. Suspendisse   ", ' ');
	// pString = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.", 'i');
	// pString = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.", 'z');
	pString = ft_split("", 'z');

	printf("%p", pString);

	// for (size_t i = 0; i < counter("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.", 'z'); i++)
	// {
	// 	printf("%s\n", pString[i]);
	// }

	return 0;
}
