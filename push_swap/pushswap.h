/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 14:24:28 by sungmcho          #+#    #+#             */
/*   Updated: 2022/02/03 13:57:30 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "./Libft/libft.h"

typedef struct s_stack {
	int	*a_stack;
	int	*b_stack;
	int	a_len;
	int	b_len;
	int	min_sorted;
	int	sort_len;
}	t_stack;

int		is_sorted_asc(int *arr, int len);
void	over_max_min_int_checker(char *str);
void	exit_function(void);
void	pa(t_stack *stack);
void	pb(t_stack *stack);
void	r_operation(t_stack *stack, int n);
void	rr_operation(t_stack *stack, int n);
void	s_operation(t_stack *stack, int n);
int		find_median(int *arr, int len);
int		find_max_idx(int *arr, int len);
int		find_min_idx(int *arr, int len);
void	push_swap(t_stack *stack);
void	small_push_swap(t_stack *stack);
void	imbecile_ft(t_stack *stack);

#endif
