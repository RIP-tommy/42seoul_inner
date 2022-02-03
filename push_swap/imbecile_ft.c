/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imbecile_ft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 19:49:44 by sungmcho          #+#    #+#             */
/*   Updated: 2022/02/03 14:04:36 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	imbecile_ft(t_stack *stack)
{
	int	i;

	while (stack->a_len > 3)
	{
		i = find_min_idx(stack->a_stack, stack->a_len);
		while (i)
		{
			if (i < stack->a_len / 2)
				r_operation(stack, 1);
			else
				rr_operation(stack, 1);
			i = find_min_idx(stack->a_stack, stack->a_len);
		}
		pb(stack);
	}
	small_push_swap(stack);
	pa(stack);
	pa(stack);
}
