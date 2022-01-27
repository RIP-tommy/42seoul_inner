/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 19:27:22 by sungmcho          #+#    #+#             */
/*   Updated: 2022/01/20 19:27:39 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	small_push_swap(t_stack *stack)
{
	if (find_max_idx(stack->a_stack, stack->a_len) == 2)
	{
		if (stack->a_stack[0] > stack->a_stack[1])
			s_operation(stack, 1);
	}
	else if (find_max_idx(stack->a_stack, stack->a_len) == 1)
	{
		rr_operation(stack, 1);
		if (stack->a_stack[0] > stack->a_stack[1])
			s_operation(stack, 1);
	}
	else
	{
		r_operation(stack, 1);
		if (stack->a_stack[0] > stack->a_stack[1])
			s_operation(stack, 1);
	}
}
