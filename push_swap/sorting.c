/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 14:24:04 by sungmcho          #+#    #+#             */
/*   Updated: 2022/01/12 12:32:46 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	shrt_rt(t_stack *stack)
{
	int	min;
	int	max;
	int	min_shrt;
	int max_shrt;
	int	dir;
	int shrt;

	min = find_min(stack->b_stack, stack->b_len);
	max = find_max(stack->b_stack, stack->b_len);
	if (min != 0 && max != 0)
	{
		if (min > stack->b_len - min)
		{
			min_shrt = stack->b_len - min;
			dir = 1;
		}
		else
		{
			min_shrt = min;
			dir = 0;
		}
		if (max > stack->b_len - max)
		{
			max_shrt = stack->b_len - max;
			dir = 1;
		}
		else
		{
			max_shrt = max;
			dir = 0;
		}
		if (max_shrt > min_shrt)
		{
			while (min_shrt)
			{
				if (dir)
					rr_operation(stack, 2);
				else
					r_operation(stack, 2);
				min_shrt -= 1;
			}
			return (1);
		}
		else
		{
			while (max_shrt)
			{
				if (dir)
					rr_operation(stack, 2);
				else
					r_operation(stack, 2);
				max_shrt -= 1;
			}
			return (0);
		}
	}
	else
	{
		if (max == 0)
			return (0);
		else
			return (1);
	}
}

static void	pa_num(t_stack *stack, int iter)
{
	int	len;
	int	max;
	int	min;

	len = stack->b_len;
	while (stack->b_len)
	{
		if (shrt_rt(stack))
		{
			pa(stack);
			r_operation(stack, 1);
		}
		else
			pa(stack);
		stack->sort_len += 1;
	}
	if (iter != 1)
	{
		len = stack->a_len - stack->sort_len;
		while (len)
		{
			rr_operation(stack, 1);
			len -= 1;
		}
	}
}

static void	pb_large_num(t_stack *stack, int iter)
{
	int	i;
	int	mi;
	int	len;

	i = 0;
	len = stack->a_len - stack->sort_len;
	mi = find_median(stack->a_stack, len);
	while (i < len)
	{
		if (iter != 1)
		{
			if (mi < stack->a_stack[0])
				pb(stack);
			else
				r_operation(stack, 1);
		}
		else
			pb(stack);
		i += 1;
	}
}

void	sort(t_stack *stack)
{
	int	iter;

	iter = stack->a_len / 10;
	if (!iter)
	{
		while (iter)
		{
			pb_large_num(stack, iter);
			pa_num(stack, iter);
			iter -= 1;
		}
	}
	else
	{
		pb_large_num(stack, iter);
		pa_num(stack, iter);
	}
}
