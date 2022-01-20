/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 14:24:34 by sungmcho          #+#    #+#             */
/*   Updated: 2022/01/10 15:18:30 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	rra(t_stack *stack)
{
	int	lst_el;
	int	i;

	i = stack->a_len - 1;
	lst_el = stack->a_stack[i];
	while (i)
	{
		stack->a_stack[i] = stack->a_stack[i - 1];
		i -= 1;
	}
	stack->a_stack[0] = lst_el;
}

static void	rrb(t_stack *stack)
{
	int	lst_el;
	int	i;

	i = stack->b_len - 1;
	lst_el = stack->b_stack[i];
	while (i)
	{
		stack->b_stack[i] = stack->b_stack[i - 1];
		i -= 1;
	}
	stack->b_stack[0] = lst_el;
}

void	rr_operation(t_stack *stack, int n)
{
	if (n == 1)
	{
		rra(stack);
		write(1, "rra\n", 4);
	}
	else if (n == 2)
	{
		rrb(stack);
		write(1, "rrb\n", 4);
	}
	else
	{
		rra(stack);
		rrb(stack);
		write(1, "rrr\n", 4);
	}
}
