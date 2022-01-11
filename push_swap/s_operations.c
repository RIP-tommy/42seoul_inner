/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 14:24:06 by sungmcho          #+#    #+#             */
/*   Updated: 2022/01/09 21:28:33 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	sa(t_stack *stack)
{
	int	temp;

	temp = stack->a_stack[0];
	stack->a_stack[0] = stack->a_stack[1];
	stack->a_stack[1] = temp;
}

static void	sb(t_stack *stack)
{
	int	temp;

	temp = stack->b_stack[0];
	stack->b_stack[0] = stack->b_stack[1];
	stack->b_stack[1] = temp;
}

void	s_operation(t_stack *stack, int n)
{
	if (n == 1)
	{
		sa(stack);
		write(1, "sa\n", 3);
	}
	else if (n == 2)
	{
		sb(stack);
		write(1, "sb\n", 3);
	}
	else
	{
		sa(stack);
		sb(stack);
		write(1, "ss\n", 3);
	}
}
