/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 14:24:04 by sungmcho          #+#    #+#             */
/*   Updated: 2022/01/12 20:18:52 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	sorting_order(t_stack *stack, int n, int max, int min)
{
	if (n == 0)
	{
		max += 1;
		while (--max)
			r_operation(stack, 2);
	}
	else if (n == 1)
		while (stack->b_len - max++)
			rr_operation(stack, 2);
	else if (n == 2)
	{
		min += 1;
		while (--min)
			r_operation(stack, 2);
	}
	else
		while (stack->b_len - min++)
			rr_operation(stack, 2);
	pa(stack);
	if (n == 2 || n == 3)
	{
		r_operation(stack, 1);
		stack->min_sorted += 1;
	}
}

static void	shrt_rt(t_stack *stack)
{
	int	min;
	int	max;
	int	mov[4];

	max = find_max_idx(stack->b_stack, stack->b_len);
	min = find_min_idx(stack->b_stack, stack->b_len);
	if (!max)
		pa(stack);
	else
	{
		mov[0] = max + 1;
		mov[1] = stack->b_len - max + 1;
		mov[2] = min + 3;
		mov[3] = stack->b_len - min +3;
		sorting_order(stack, find_min_idx(mov, 4), max, min);
	}
}

static void	pa_largest_num(t_stack *stack, int iter)
{
	int	len;
	int	max;
	int	min;

	len = stack->b_len;
	while (stack->b_len)
	{
		shrt_rt(stack);
		stack->sort_len += 1;
	}
	while (stack->min_sorted)
	{
		rr_operation(stack, 1);
		stack->min_sorted -= 1;
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

static void	pb_over_med(t_stack *stack, int iter)
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

void	push_swap(t_stack *stack)
{
	int	iter;

	iter = 4;
	while (iter)
	{
		pb_over_med(stack, iter);
		pa_largest_num(stack, iter);
		iter -= 1;
	}
}
