/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sm <sm@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 14:24:31 by sungmcho          #+#    #+#             */
/*   Updated: 2022/01/11 11:56:38 by sm               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	ra(t_stack *stack)
{
	int	fst_el;
	int	i;

	i = 0;
	fst_el = stack->a_stack[0];
	while (i < stack->a_len - 1)
	{
		stack->a_stack[i] = stack->a_stack[i + 1];
		i += 1;
	}
	stack->a_stack[stack->a_len - 1] = fst_el;
}

static void	rb(t_stack *stack)
{
	int	fst_el;
	int	i;

	i = 0;
	fst_el = stack->b_stack[0];
	while (i < stack->b_len - 1)
	{
		stack->b_stack[i] = stack->b_stack[i + 1];
		 i += 1;
	}
	stack->b_stack[stack->b_len - 1] = fst_el;
}

void	r_operation(t_stack *stack, int n)
{
	if (n == 1)
	{
		ra(stack);
		write(1, "ra\n", 3);
	}
	else if (n == 2)
	{
		rb(stack);
		write(1, "rb\n", 3);
	}
	else
	{
		ra(stack);
		rb(stack);
		write(1, "rr\n", 3);
	}
}
