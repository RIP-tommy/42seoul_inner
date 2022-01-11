/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 14:24:25 by sungmcho          #+#    #+#             */
/*   Updated: 2022/01/10 15:44:51 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	push_a_stack(t_stack *stack)
{
	int	temp;
	int	i;

	i = ++stack->a_len;
	while (i)
	{
		temp = stack->a_stack[i - 1];
		stack->a_stack[i] = temp;
		i--;
	}
	stack->a_stack[i] = 0;
}

static void	push_b_stack(t_stack *stack)
{
	int	temp;
	int	i;

	i = ++stack->b_len;
	while (i)
	{
		temp = stack->b_stack[i - 1];
		stack->b_stack[i] = temp;
		i--;
	}
	stack->b_stack[i] = 0;
}

void	pa(t_stack *stack)
{
	int	i;

	i = 0;
	if (stack->b_len != 0)
	{
		push_a_stack(stack);
		stack->a_stack[0] = stack->b_stack[0];
		while (i < stack->b_len - 1)
		{
			stack->b_stack[i] = stack->b_stack[i + 1];
			i++;
		}
		stack->b_stack[i] = 0;
		stack->b_len--;
	}
	write(1, "pa\n", 3);
}

void	pb(t_stack *stack)
{
	int	i;

	i = 0;
	if (stack->a_len != 0)
	{
		push_b_stack(stack);
		stack->b_stack[0] = stack->a_stack[0];
		while (i < stack->a_len - 1)
		{
			stack->a_stack[i] = stack->a_stack[i + 1];
			i++;
		}
		stack->a_stack[i] = 0;
		stack->a_len--;
	}
	write(1, "pb\n", 3);
}
