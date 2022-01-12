#include "pushswap.h"

int	find_median(int *arr, int len)
{
	int i;
	int j;
	int cnt;

	i = 0;
	while (i < len)
	{
		j = 0;
		cnt = 0;
		while (j < len)
		{
			if (arr[i] > arr[j])
				cnt += 1;
			j += 1;
		}
		if (cnt == (len / 2))
			return (arr[i]);
		i += 1;
	}
}

int	find_max(int *arr, int len)
{
	int i;
	int j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (arr[i] < arr[j])
				break ;
			j += 1;
		}
		if (j == len)
			return (i);
		i += 1;
	}
}

int	find_min(int *arr, int len)

{
	int i;
	int j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (arr[i] > arr[j])
				break ;
			j += 1;
		}
		if (j == len)
			return (i);
		i += 1;
	}
}
