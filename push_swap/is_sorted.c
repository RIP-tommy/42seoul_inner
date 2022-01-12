/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 10:51:32 by sungmcho          #+#    #+#             */
/*   Updated: 2022/01/12 10:51:32 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
