#include "pushswap.h"

int	is_sorted_asc(int *arr, int len)
{
	int	i;

	i = 1;
	while (i < len)
	{
		if (arr[i - 1] > arr[i])
			break ;
		i += 1;
	}
	if (i == len)
		return (1);
	else
		return (0);
}

int	is_sorted_desc(int *arr, int len)
{
	int	i;

	i = 1;
	while (i < len)
	{
		if (arr[i - 1] < arr[i])
			break ;
		i += 1;
	}
	if (i == len)
		return (1);
	else
		return (0);
}
