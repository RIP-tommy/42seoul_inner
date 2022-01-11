/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 14:24:04 by sungmcho          #+#    #+#             */
/*   Updated: 2022/01/11 10:40:06 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int find_median(int *arr, int len)
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

static int find_max(int *arr, int len)
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

static int find_min(int *arr, int len)

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

void	sort(t_stack *stack)
{
	int	i;
	int	mi;
	int	len;
	int	max;

	i = 0;
	len = stack->a_len;
	mi = find_median(stack->a_stack, len);
	while (i < len)
	{
		if (mi < stack->a_stack[0])
			pb(stack);
		else
			r_operation(stack, 1);
		i += 1;
	}
	len = stack->b_len;
	i = 0;
	while (i < len)
	{
		max = find_max(stack->b_stack, stack->b_len);
		while (max)
		{
			r_operation(stack, 2);
			max -= 1;
		}
		pa(stack);
		i += 1;
		stack->sort_len += 1;
	}
	while (i)
	{
		r_operation(stack, 1);
		i -= 1;
	}
	i = 0;
	len = stack->a_len - stack->sort_len;
	mi = find_median(stack->a_stack, len);
	while (i < len)
	{
		if (mi < stack->a_stack[0])
			pb(stack);
		else
			r_operation(stack, 1);
		i += 1;
	}
	len = stack->b_len;
	i = 0;
	while (i < len)
	{
		max = find_max(stack->b_stack, stack->b_len);
		while (max)
		{
			r_operation(stack, 2);
			max -= 1;
		}
		pa(stack);
		i += 1;
		stack->sort_len += 1;
	}
	i = 0;
	len = stack->a_len - stack->sort_len;
	while (i < len)
	{
		rr_operation(stack, 1);
		i += 1;
	}
	while (i)
	{
		pb(stack);
		i -= 1;
	}
	len = stack->b_len;
	i = 0;
	while (i < len)
	{
		max = find_max(stack->b_stack, stack->b_len);
		while (max)
		{
			r_operation(stack, 2);
			max -= 1;
		}
		pa(stack);
		i += 1;
		stack->sort_len += 1;
	}
}
