/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 14:24:04 by sungmcho          #+#    #+#             */
/*   Updated: 2022/01/12 10:13:05 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	pa_max_num(t_stack *stack, int iter)
{
	int	i;
	int	len;
	int	max;
	
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
	if (iter != 1)
	{
		while (i)
		{
			r_operation(stack, 1);
			i -= 1;
		}
	}
}

static void	pb_large_num(t_stack *stack, int iter)
{
	int	i;
	int	mi;
	int	len;
	int	max;

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

	iter = 3;
	while (iter)
	{
		pb_large_num(stack, iter);
		pa_max_num(stack, iter);
		iter -= 1;
	}
}
