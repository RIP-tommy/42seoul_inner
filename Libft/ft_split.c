#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

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

	idx = -1;
	start = 0;
	max_len = 0;
	str_len = ft_strlen(s);
	while (s[++idx])
	{
		if (s[idx - 1] != c && s[idx] == c)
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
	{
		if (s[idx] != c)
		{
			temp = slicer(s, start, idx);
			rslt[idx2++] = temp;
			start = idx + 1;
		}
	}
	temp = slicer(s, start, idx);
	rslt[idx2] = temp;
	return (rslt);
}

// char	**ft_split(char const *s, char c)
// {
// 	char	**rslt;
// 	char	*temp;
// 	size_t	idx;
// 	size_t	idx2;
// 	size_t	start;

// 	idx = -1;
// 	idx2 = 0;
// 	start = 0;
// 	rslt = (char **)malloc(get_max_len(s, c) * (counter(s, c) + 1));
// 	if (!rslt)
// 		return (NULL);
// 	while (s[++idx])
// 	{
// 		if (s[idx] == c && s[idx + 1] == c)
// 			start = idx + 1;
// 		else if (s[idx] == c)
// 		{
// 			temp = slicer(s, start, idx);
// 			rslt[idx2++] = temp;
// 			start = idx + 1;
// 		}
// 	}
// 	temp = slicer(s, start, idx);
// 	rslt[idx2] = temp;
// 	return (rslt);
// }
